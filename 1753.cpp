#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int v, e, k;
vector<pair<int, int>> path[20002];
int dis[20002];

int main()
{
	fill(dis, dis + 20002, INF);
	cin >> v >> e;
	cin >> k;
	
	for (int i = 1; i <= e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		path[a].push_back({ b,c });
	}

	dis[k] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,k });

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		if (dis[cur.first] != cur.second)
			continue;
		for (auto next : path[cur.second])
		{
			if (dis[next.first] <= dis[cur.first] + next.second)
				continue;
			dis[next.first] = dis[cur.first] + next.second;
			pq.push({ d[next.first],next.f });
			
		}
	}
}