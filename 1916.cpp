#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//거리, 출발지(중요!!!)
vector<pair<int, int>> slot[20001]; //목적지, 거리
int dis[20001];
int v, e, start;

void Check()
{
	pq.push({ 0 , start });
	dis[start] = 0;

	while (!pq.empty())
	{
		auto before = pq.top();
		pq.pop();

		for (auto nxt : slot[before.second])
		{
			if (dis[nxt.first] != -1 && dis[nxt.first] <= dis[before.second] + nxt.second)
				continue;
			dis[nxt.first] = dis[before.second] + nxt.second;
			pq.push({ dis[nxt.first], nxt.first });
		}
	}
}

int main()
{
	fill(dis, dis + 20001, -1);
	cin >> v >> e;
	cin >> start;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		slot[a].push_back({ b, c });
	}


	Check();

	for (int i = 1; i <= v; i++)
	{
		if (dis[i] == -1)
			cout << "INF\n";
		else
			cout << dis[i] << '\n';
	}
}