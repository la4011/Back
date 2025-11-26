#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int n, w;

int main()
{
	cin >> n;
	cin >> w;

	int num = n * 10;
	if (n >= 3)
		num += 20;
	if (n == 5)
		num += 50;
	if (w > 1000)
	{
		num = num - 15;
		if (num <= 0)
			num = 0;
	}

	cout << num;
}