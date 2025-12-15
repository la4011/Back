#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> item[101]; //무게, 가치
int value[100001]; //무게당 최대값

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> item[i].first >> item[i].second;

	
	for (int i = 0; i < n; i++)
	{
		for (int j = k; j >= item[i].first; j--)
			value[j] = max(value[j], (value[j - item[i].first] + item[i].second));
	}

	cout << value[k];
}