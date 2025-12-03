#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int slot[21][21];
int vis[21][21];
int shark_size = 2;
int feed_num = 0;
int cnt = 0;
pair<int, int> babyshark;
queue<pair<int, int>> Q;

int hx[4] = { 0, -1, 1, 0 };
int hy[4] = { -1, 0, 0, 1 };

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int BFS(pair<int,int> item)
{
	vector<pair<int,int>> fish;
	int target_dis = 0;

	fill(vis[0], vis[0] + (21 * 21), -1);
	Q.push(item);
	vis[item.first][item.second] = 0;

	while (!Q.empty())
	{
		auto before = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = hx[i] + before.second;
			int ny = hy[i] + before.first;

			if (ny < 0 || nx < 0 || ny >= n || nx >= n || vis[ny][nx] != -1)
				continue;
			if (slot[ny][nx] > shark_size)
				continue;
			vis[ny][nx] = vis[before.first][before.second] + 1;
			if (target_dis != 0 && target_dis != vis[ny][nx])
			{
				while (!Q.empty())
					Q.pop();
				break;
			}
			Q.push({ ny, nx });
			if (slot[ny][nx] < shark_size && slot[ny][nx] != 0)
			{
				target_dis = vis[ny][nx];
				fish.push_back({ ny,nx });
			}
		}
	}

	if (fish.empty())
		return 0;

	sort(fish.begin(), fish.end(), cmp);

	slot[fish[0].first][fish[0].second] = 0;
	feed_num++;
	if (feed_num == shark_size)
	{
		shark_size++;
		feed_num = 0;
	}
	babyshark = { fish[0].first, fish[0].second };
	return vis[fish[0].first][fish[0].second];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> slot[i][j];
			if (slot[i][j] == 9)
			{
				babyshark = { i, j };
				slot[i][j] = 0;
			}
		}

	while(1)
	{
		int plus = BFS(babyshark);
		if (!plus)
			break;
		cnt += plus;
	}

	cout << cnt;
}