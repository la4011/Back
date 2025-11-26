#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
long long dp[1000002];

int main()
{
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 1000000; i++)
	{
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
	}

	while (t--)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}
}