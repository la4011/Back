#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int n, m, r;
int node[101];
vector<pair<int, int>> line[101]; //목적지, 거리
priority_queue<pair<int, int>> Q; //거리, 스팟
int dis[101];
int max_cnt = 0;

void Check(int item)
{
	int tmp_cnt = node[item];
	fill(dis, dis + 101, -1);

	Q.push({ 0,item });
	dis[item] = 0;

	while (!Q.empty())
	{
		auto before = Q.top();
		Q.pop();

		for (auto after : line[before.second])
		{
			if ((dis[after.first] < dis[before.second] + after.second && dis[after.first] != -1) || dis[before.second] + after.second > m)
				continue;
			if (dis[after.first] == -1)
				tmp_cnt += node[after.first];
			dis[after.first] = dis[before.second] + after.second;
			Q.push({ dis[after.first], after.first });
		}
	}
	max_cnt = max(tmp_cnt, max_cnt);
}

int main()
{
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
		cin >> node[i];

	for (int i = 0; i < r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		line[a].push_back({ b,c });
		line[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++)
		Check(i);

	cout << max_cnt;
}