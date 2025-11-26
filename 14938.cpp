#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, r;
int node[102];
int path[102][102] = { 0, };
queue<int> Q;
pair<int, int> dis[101][101];

int main()
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			Q[i][j] = make_pair(-1, -1);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> node[i];

	for (int i = 0; i < r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		path[a][b] = c;
		paht[b][a] = c;
	}

	for (int i = 1; i <= n; i++)
	{

		Q.push(1);

		while (!Q.empty())
		{
			int before = Q.front();
			Q.pop();

			for (int j = 1; j <= n; j++)
			{
				if (path == 0)
					continue;
				int d = dis[i][before].first + path[before][j];
				if (d > m)
					continue;
				int am = dis[i][before].second + node[j];
				if(am < )
			}
		}
	}
}