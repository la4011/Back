#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	int dp[361][361];

	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		
		vector<int> cards(n);
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < n; i++)
			cin >> cards[i];

		dp[0][0] = 0;
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			int limit = min(k, cur);
			int cnt = cards[i];

			for (int j = limit; j >= 0; j--)
			{
				for (int m = 0; m <= j; m++)
				{
					if (dp[j][m] == -1)
						continue;
					int curval = dp[j][m];
					dp[j][m] = max(dp[j][m], curval + m);
					for (int c = 1; c <= cnt; c++)
					{
						int nxtj = j + c;
						if (nxtj > k)
							break;
						int nxtm = max(c, m);
						int value = dp[j][m] + nxtm;

						if (value > dp[nxtj][nxtm])
							dp[nxtj][nxtm] = value;
					}
				}
			}
			cur += cnt;
		}

		int sol = 0;
		for (int i = 0; i <= k; i++)
			for (int j = 0; j <= i; j++)
				sol = max(sol, dp[i][j]);

		cout << sol << '\n';
	}
}