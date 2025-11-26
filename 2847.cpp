#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n;
int num[101];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	int cnt = num[n - 1];
	int sol = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (num[i] == cnt)
			cnt--;
		else if (num[i] > cnt)
		{
			sol += num[i] - cnt;
			cnt--;
		}
		else
			cnt = num[i] - 1;
	}

	cout << sol;
}