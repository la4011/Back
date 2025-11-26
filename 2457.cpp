#include <iostream>
#include <algorithm>
using namespace std;
int n;
int cnt = 0;
pair<pair<int, int>, pair<int, int>> P[100001];
pair<pair<int, int>, pair<int, int>> before{ {3,1}, {3,1} };

bool cmp(const pair<pair<int, int>, pair<int, int>>& a, pair<pair<int, int>, pair<int, int>>& b)
{
	if (a.first.first == b.first.first)
	{
		if (a.first.second == b.first.second)
		{
			if(a.second.first == b.second.first)
				return a.second.second < b.second.second;
			return a.second.first < b.second.first;
		}
		return a.first.second < b.first.second;
	}
	return a.first.first < b.first.first;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> P[i].first.first >> P[i].first.second >> P[i].second.first >> P[i].second.second;

	sort(P, P + n, cmp);

	int i = 0;
	while (before.second.first <= 11)
	{
		int nm = before.second.first;
		int nd = before.second.second;
		bool found = false;

		while (i < n && (P[i].first.first < before.second.first || (P[i].first.first == before.second.first && P[i].first.second <= before.second.second)))
		{
			if (P[i].second.first > nm || (P[i].second.first == nm && P[i].second.second > nd))
			{
				nm = P[i].second.first;
				nd = P[i].second.second;
				found = true;
			}
			i++;
		}

		if (!found)
		{
			cnt = 0;
			break;
		}

		before.second.first = nm;
		before.second.second = nd;
		cnt++;

		if (before.second.first > 11) break;
	}

	if (before.second.first <= 11)
		cnt = 0;

	cout << cnt;
}