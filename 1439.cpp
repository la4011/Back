#include <iostream>
#include <algorithm>
using namespace std;
string n;
int num[1000001];

int main()
{
	cin >> n;

	int sz = n.size();
	for (int i = 0; i < sz; i++)
		num[i] = n[i] - '0';

	int before = num[0];
	int cnt = 1;

	for (int i = 1; i < sz; i++)
	{
		if (before != num[i])
			cnt++;
		before = num[i];
	}

	cout << cnt / 2;
}