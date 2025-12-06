#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, x;
int dis[1001];
vector<pair<int, int>> Route[1001]; //도착지, 가중치, [출발지]
vector<pair<int, int>> R_Route[1001];
int sol_dis[1001] = { 0, };

void BFS(int start)
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //거리(정렬목적), 출발지
	pq.push({0, start});
	dis[start] = 0;

	while (!pq.empty())
	{
		auto before = pq.top();
		pq.pop();

		if (dis[before.second] != before.first)
			continue;

		for (auto next : Route[before.second])
		{
			if (dis[next.first] != -1 && dis[next.first] <= dis[before.second] + next.second)
				continue;

			dis[next.first] = dis[before.second] + next.second;
			pq.push({ dis[next.first], next.first });
		}
	}
	for (int i = 1; i <= n; i++)
		sol_dis[i] += dis[i];
}

void ReturnBFS(int start)
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //거리(정렬목적), 출발지
	pq.push({ 0, start });
	dis[start] = 0;

	while (!pq.empty())
	{
		auto before = pq.top();
		pq.pop();
		if (dis[before.second] != before.first)
			continue;

		for (auto next : R_Route[before.second])
		{
			if (dis[next.first] != -1 && dis[next.first] <= dis[before.second] + next.second)
				continue;

			dis[next.first] = dis[before.second] + next.second;
			pq.push({ dis[next.first], next.first });
		}
	}

	for (int i = 1; i <= n; i++)
		sol_dis[i] += dis[i];
}

int main()
{
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Route[a].push_back({ b,c });
		R_Route[b].push_back({ a,c });
	}

	fill(dis, dis + 1001, -1);
	ReturnBFS(x);
	fill(dis, dis + 1001, -1);
	BFS(x);

	int high = 0;
	for (int i = 1; i <= n; i++)
		if (high < sol_dis[i])
			high = sol_dis[i];

	cout << high;
}