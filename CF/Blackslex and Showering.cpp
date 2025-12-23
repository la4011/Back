#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		long long tot = 0;

		for (int i = 0; i < n - 1; i++)
			tot += abs(arr[i] - arr[i + 1]);

		long long sol = tot;

		long long tmp = tot - abs(arr[0] - arr[1]);
		if (tmp < sol)
			sol = tmp;
		tmp = tot - abs(arr[n - 2] - arr[n - 1]);
		if (tmp < sol)
			sol = tmp;
		for (int i = 1; i < n - 1; i++)
		{
			int before = abs(arr[i - 1] - arr[i]) + abs(arr[i] - arr[i + 1]);
			int after = abs(arr[i - 1] - arr[i + 1]);
			tmp = tot - before + after;
			if (tmp < sol)
				sol = tmp;
		}

		cout << sol << '\n';
	}
}