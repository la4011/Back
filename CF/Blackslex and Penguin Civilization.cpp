#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		long long num = pow(2, n);
		vector<int> arr(num, 0);
		vector<int> sol;
		queue<int> Q;

		for (int i = num; i > 0; i = i / 2)
			Q.push(i);
		
		while (!Q.empty())
		{
			int target = Q.front();
			Q.pop();

			vector<int> tmp;
			for (long long i = num; i > 0; i -= target)
			{
				if (arr[i - 1] == 0)
				{
					arr[i - 1] = 1;
					tmp.push_back(i-1);
				}
			}
			sort(tmp.begin(), tmp.end());
			sol.insert(sol.end(), tmp.begin(), tmp.end());
		}

		for (int i = 0; i < sol.size(); i++)
			cout << sol[i] << " ";

		for (int i = 0; i < num; i++)
			if (arr[i] == 0)
				cout << arr[i] << " ";

		cout << '\n';
	}
}