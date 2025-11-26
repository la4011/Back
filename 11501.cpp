#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int t, n;
int price[1000001];
int best[1000001];

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> price[i];

		long long sol = 0;
		int maxPrice = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (price[i] > maxPrice)
				maxPrice = price[i];
			else
				sol += maxPrice - price[i];
		}

		cout << sol << '\n';
	}
}