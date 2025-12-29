#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int t;

int check(long long big, long long small)
{
	long long cnt = 0;
	while (1)
	{
		big -= (1LL << cnt);
		if (big < 0)
			return cnt;
		cnt++;
		small -= (1LL << cnt);
		if (small < 0)
			return cnt;
		cnt++;
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;

		int case1 = check(a, b);
		int case2 = check(b, a);
		cout << max(case1, case2) << '\n';
	}
}