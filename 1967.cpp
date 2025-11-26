#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
int n;
int a, b, c;
pair<int, int> tree[10001][4];
queue<int> Q;
int dis[10001] = { 0, };

int main()
{
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;

		for (int j = 0; j < 3; j++)
		{
			if (tree[a][j] == 0)
				continue;

			tree[a][j].first = b;
			tree[a][j].second = c;
			break;
		}

		for (int j = 0; j < 3; j++)
		{
			if (tree[b][j] == 0)
				continue;

			tree[b][j].first = a;
			tree[b][j].second = c;
			break;
		}
	}

	Q.push(1);
	vis[1] = 1;

	while (!Q.empty())
	{
		int before = Q.front();
		Q.pop();

		for (int i = 0; i < 3; i++)
		{
			if (tree[before][i].first == 0)
				break;
			if (dis[tree[before][i].first] != 0)
				continue;

			dis[tree[before][i].first] = dis[before] + tree[before][i].second;
			Q.push(tree[before][i].first);
		}
	}
}