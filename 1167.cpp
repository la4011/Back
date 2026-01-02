#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> tree[100005];
int M = 0;

int BFS(int target)
{
	int tmp_sol;
	int dis[100005];
	fill(dis, dis + 100005, -1);
	queue<int> Q;

	Q.push(target);
	dis[target] = 0;

	while (!Q.empty())
	{
		int before = Q.front();
		Q.pop();

		for (auto after : tree[before])
		{
			int add_dis = after.second;
			int node = after.first;

			if (dis[node] != -1 && dis[node] <= dis[before] + add_dis)
				continue;
			dis[node] = dis[before] + add_dis;
			if (M < dis[node])
			{
				M = dis[node];
				tmp_sol = node;
			}
			Q.push(node);
		}
	}
	return tmp_sol;
}

int main()
{
	int v;
	cin >> v;

	for (int i = 0; i < v; i++)
	{
		int n;
		cin >> n;

		while (1)
		{
			int a, b;
			cin >> a;
			if (a == -1)
				break;
			cin >> b;
			tree[n].push_back({ a,b });
			tree[a].push_back({ n,b });
		}
	}

	int tmp = BFS(1);
	M = 0;
	int Mtarget = BFS(tmp);

	cout << M;
}