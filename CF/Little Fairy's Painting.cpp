#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	int n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<int> V;

		while (n--)
		{
			int a;
			cin >> a;
			V.push_back(a);
		}

		sort(V.begin(), V.end());
		V.erase(unique(V.begin(), V.end()), V.end());
		int num = V.size();

		bool flag = 0;
		for (int item : V)
		{
			if (item >= num)
			{
				cout << item << '\n';
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << 1000000000000000000 - num << '\n';
	}
}