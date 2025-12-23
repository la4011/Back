#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		vector<int> num(n);
		for (int i = 0; i < n; i++)
			cin >> num[i];

		sort(num.begin(), num.end());
		int v1 = num[0];
		int v2 = num[1] - num[0];
		int sol = max(v1, v2);

		cout << sol << '\n';
	}
}