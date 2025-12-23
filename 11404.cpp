#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9

int n, m;
int bus[101][101];

int main()
{
	fill(bus[0], bus[0] + (101 * 101), INF);

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j)
				bus[i][j] = 0;


	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		bus[a][b] = min(bus[a][b], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if(bus[i][k] != INF && bus[k][j] != INF)
					bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (bus[i][j] == INF)
				cout << 0 << " ";
			else
				cout << bus[i][j] << " ";
		}
		cout << '\n';
	}
}