#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int start, goal;
vector<pair<int, int>> bus[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> route;
int dis[1001];
int path[1001];

void Check()
{
	pq.push({ 0, start });
	dis[start] = 0;

	while (!pq.empty())
	{
		auto before = pq.top();
		pq.pop();
		int before_node = before.second;
		int before_dis = before.first;

		if (before_dis != dis[before_node])
			continue;

		for (auto after : bus[before_node])
		{
			int add_dis = after.second;
			int after_node = after.first;
			int tot_dis = add_dis + before_dis;

			if (dis[after_node] != -1 && dis[after_node] <= tot_dis)
				continue;

			dis[after_node] = tot_dis;
			path[after_node] = before_node;
			pq.push({ tot_dis, after_node });
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(dis, dis + 1001, -1);
	fill(path, path + 1001, -1);

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		bus[a].push_back({ b, c });
	}

	cin >> start >> goal;

	Check();

	cout << dis[goal] << '\n';

	for (int i = goal; i != -1; i = path[i])
		route.push_back(i);
	cout << route.size() << '\n';
	for (int i = route.size() - 1; i >= 0; i--)
		cout << route[i] << " ";
}