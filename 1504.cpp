#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, e;
int v1, v2;
int dis[801];
int path1 = 0;
int path2 = 0;
int flag = 0;
vector<pair<int, int>> line[801];

int Check(int item, int goal)
{
	fill(dis, dis + 801, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, item });
	dis[item] = 0;

	while (!pq.empty())
	{
		auto before = pq.top();
		int before_spot = before.second;
		int before_dis = before.first;
		pq.pop();

		if (before_dis != dis[before_spot])
			continue;

		for (auto after : line[before_spot])
		{
			int after_spot = after.first;
			int add_dis = after.second;

			if (dis[after_spot] != -1 && dis[after_spot] <= dis[before_spot] + add_dis)
				continue;
			dis[after_spot] = dis[before_spot] + add_dis;
			pq.push({ dis[after_spot], after_spot });
		}
	}
	if (dis[goal] == -1)
		flag = 1;
	return dis[goal];
}

int main()
{
	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		line[a].push_back({ b, c });
		line[b].push_back({ a, c });
	}

	cin >> v1 >> v2;

	path1 = Check(1, v1) + Check(v1, v2) + Check(v2, n);
	if (flag)
	{
		cout << -1;
		return 0;
	}
	path2 = Check(1, v2) + Check(v2, v1) + Check(v1, n);

	cout << min(path1, path2);
}