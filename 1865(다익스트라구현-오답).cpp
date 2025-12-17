#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> V[501]; //목적지, 걸리는 시간
int dis[501];

void Check(int item)
{
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //거리, 스팟
	pq.push({ 0, item });
	dis[item] = 0;

	while(!pq.empty())
	{
		auto before = pq.top();
		pq.pop();

		if (dis[before.second] != -1 && dis[before.second] < before.first)
			continue;

		for (auto next : V[before.second])
		{
			if (dis[next.first] != -1 && (dis[next.first] <= dis[before.second] + next.second))
				continue;
			dis[next.first] = dis[before.second] + next.second;
			pq.push({ dis[next.first], next.first });
			if (dis[next.first] < 0 && next.first == item)
				return;
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--)
	{
		for (int i = 0; i < 501; i++)
			V[i].clear();
		
		int n, m, w;
		cin >> n >> m >> w;

		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			V[s].push_back({ e,t });
			V[e].push_back({ s,t });
		}

		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			V[s].push_back({ e,-t });
		}

		bool flag = 0;
		for (int i = 1; i <= n; i++)
		{
			fill(dis, dis + 501, -1);
			Check(i);
			if (dis[i] < 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}