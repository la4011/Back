#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int n, m;
int table[1025][1025];

int main()
{
	
	cin >> n >> m;

	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;

			table[j][i] = table[j - 1][i] + table[j][i - 1] - table[j - 1][i - 1] + a;
		}

	for (int i = 0; i < m; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << table[x2][y2] - table[x1 - 1][y2] - table[x2][y1 - 1] + table[x1 - 1][y1 - 1] << '\n';
	}
}