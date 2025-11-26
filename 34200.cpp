#include <iostream>
using namespace std;

bool slot[25001] = { 0, };

int main()
{
	int n;
	int num = 0;
	cin >> n;
	int before = -1;

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		if (p - before == 1)
		{
			cout << -1;
			return 0;
		}
		if ((p - before) % 2 != 0)
			num += ((p - before) / 2) + 1;
		else
			num += (p - before) / 2;
		before = p;
	}

	cout << num;
}