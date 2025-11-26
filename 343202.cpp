#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
int slot[200001] = { 0, };
int vis[200001] = { 0, };
int check[2000001];
int n;

int main()
{
	cin >> n;

	for (int i = 0; i < n-1; i++)
		cin >> slot[i];

	bool dir = 1;
	int start = 0;
	int i;
	while (1)
	{
		if (dir)
		{
			for (i = start; slot[i] <= slot[i + 1]; i++)
				slot[i]--;
			start = i;
			cout << i + 1 << " ";
		}
		else
		{
			for (i = start; slot[i] <= slot[i - 1]; i--)
				slot[i]--;
			start = i;
			cout << i << " ";
		}
	}
}