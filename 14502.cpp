#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int slot[9][9];
int max_cnt = 0;

vector<pair<int, int>> pillar_point;
vector<pair<int, int>> virus_point;


int hx[4] = { 0, 1, 0, -1 };
int hy[4] = { 1, 0 ,-1, 0 };

void BFS()
{
	queue<pair<int, int>> Q;
	int vis[9][9] = { 0, };

	for (auto p : virus_point)
	{
		Q.push(p);
		vis[p.first][p.second] = 1;
	}

	while (!Q.empty())
	{
		auto p = Q.front();
		int x = p.second;
		int y = p.first;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + hx[i];
			int ny = y + hy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;
			if (slot[ny][nx] == 1)
				continue;
			if (vis[ny][nx] == 1)
				continue;

			vis[ny][nx] = 1;
			Q.push({ ny,nx });
		}
	}

	int tmp_cnt = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (slot[i][j] == 0 && vis[i][j] == 0)
				tmp_cnt++;
	max_cnt = max(max_cnt, tmp_cnt);
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> slot[i][j];
			if (slot[i][j] == 2)
				virus_point.push_back({ i,j });
			if (slot[i][j] == 0)
				pillar_point.push_back({ i,j });
		}

	for (int i = 0; i < pillar_point.size(); i++)
	{
		slot[pillar_point[i].first][pillar_point[i].second] = 1;
		for (int j = i+1; j < pillar_point.size(); j++)
		{
			slot[pillar_point[j].first][pillar_point[j].second] = 1;
			for (int p = j+1; p < pillar_point.size(); p++)
			{
				slot[pillar_point[p].first][pillar_point[p].second] = 1;
				BFS();
				slot[pillar_point[p].first][pillar_point[p].second] = 0;
			}
			slot[pillar_point[j].first][pillar_point[j].second] = 0;
		}
		slot[pillar_point[i].first][pillar_point[i].second] = 0;
	}

	cout << max_cnt;
}