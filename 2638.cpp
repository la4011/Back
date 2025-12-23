#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int slot[101][101];
int air[101][101];
int hx[4] = { 0,1,0,-1 };
int hy[4] = { 1,0,-1,0 };
int timecnt = 0;
vector<pair<int, int>> cheese;
queue<pair<int, int>> airQ;

void aircheck()
{
	if(air[0][0] == 0)
	{
		airQ.push({ 0,0 });
		air[0][0] = 1;
	}

	while (!airQ.empty())
	{
		auto before = airQ.front();
		int bx = before.second;
		int by = before.first;
		air[before.first][before.second] = 1;
		airQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = bx + hx[i];
			int ny = by + hy[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (slot[ny][nx] == 1)
				continue;
			if (air[ny][nx] == 1)
				continue;
			air[ny][nx] = 1;
			airQ.push({ ny,nx });
		}
	}
}

void cheesecheck()
{
	for (int i = cheese.size() - 1; i >= 0; i--)
	{
		auto here = cheese[i];
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = here.second + hx[i];
			int ny = here.first + hy[i];

			if (air[ny][nx] == 1)
				cnt++;
		}
		if (cnt >= 2)
		{
			cheese[i] = cheese.back();
			cheese.pop_back();
			slot[here.first][here.second] = 0;
			airQ.push(here);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	fill(air[0], air[0] + (101 * 101), 0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> slot[i][j];
			if (slot[i][j] == 1)
				cheese.push_back({ i,j });
		}

	while (1)
	{
		if (cheese.size() == 0)
			break;
		timecnt++;
		aircheck();
		cheesecheck();
	}

	cout << timecnt;
}