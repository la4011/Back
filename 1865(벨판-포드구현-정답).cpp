#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9

vector<pair<int, int>> V[501]; //목적지, 걸리는 시간
int dis[501];
int n, m, w;

bool Check(int item)
{
	fill(dis, dis + 501, INF);
	dis[1] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (auto next : V[j])
			{
				int nextNode = next.first;
				int time = next.second;

				if (dis[nextNode] > dis[j] + time)
				{
					dis[nextNode] = dis[j] + time;
					if (i == n)
						return true;
				}
			}
		}
	}
	return false;
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

		if (Check(n))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}