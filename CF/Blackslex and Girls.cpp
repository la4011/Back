#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> arr(n);
		string s;
		cin >> s;
		for (int i = 0; i < n; i++)
			arr[i] = s[i] - '0';

		vector<int> num(n);
		long long need_x = 0;
		long long need_y = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];

			long long k = max(1, num[i]);
			long long a = 0;
			long long b = 0;
			if (arr[i])
			{
				a = (k - 1) / 2;
				b = (k - a);
			}
			else if (!arr[i])
			{
				b = (k - 1) / 2;
				a = (k - b);
			}
			need_x += a;
			need_y += b;
		}

		if (x < need_x || y < need_y)
		{
			cout << "NO" << '\n';
			continue;
		}

		long long remain_x = x - need_x;
		long long remain_y = y - need_y;

		bool flag = 0;
		for(int i = 1; i < n; i++)
			if (arr[i - 1] != arr[i])
			{
				flag = 1;
				continue;
			}

		if (flag == 0)
		{
			if ((arr[0] == 1 && remain_x > remain_y) || (arr[0] == 0 && remain_x < remain_y))
			{
				cout << "NO" << '\n';
				continue;
			}
		}

		cout << "YES" << '\n';

	}
}