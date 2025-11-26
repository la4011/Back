#include <iostream>
#include <algorithm>
using namespace std;
int n;
int rope[100001];
int sol = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> rope[i];

	sort(rope, rope + n, greater<int>());

	for (int i = 0; i < n; i++)
		sol = max(rope[i] * (i + 1), sol);
	cout << sol;
}