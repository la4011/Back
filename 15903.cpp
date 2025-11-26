#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
int n, m;
int slot[1001];

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> slot[i];

	for (int i = 0; i < m; i++)
	{
		qsort(slot, n, sizeof(int), cmp);

		int tmp = slot[0] + slot[1];
		slot[0] = slot[1] = tmp;
	}

	int total = 0;
	for (int i = 0; i < n; i++)
		total += slot[i];

	cout << total;
}