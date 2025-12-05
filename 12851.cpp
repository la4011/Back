#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
pair<int,int> spot[100001]; //거리, 루트 수
int dis = -1;

int n, k;
queue<int> Q;

void Check()
{
	Q.push(k);
	spot[k] = { 0, 1 };

	while (!Q.empty())
	{
		int before = Q.front();
		Q.pop();

		if (before % 2 == 0 && before/2 != before)
		{
			int next = before / 2;
			if (spot[next].first == -1 || (spot[next].first != -1 && spot[next].first >= spot[before].first + 1))
			{
				spot[next].first = spot[before].first + 1;
				spot[next].second += spot[before].second;

				if (spot[next].first > dis && dis != -1)
					return;
				if (next == n && dis == -1)
					dis = spot[next].first;

				if (spot[next].second == spot[before].second)
					Q.push(next);
			}
		}
		if (before + 1 <= 100000)
		{
			int next = before + 1;
			if (spot[next].first == -1 || (spot[next].first != -1 && spot[next].first >= spot[before].first + 1))
			{
				spot[next].first = spot[before].first + 1;
				spot[next].second += spot[before].second;

				if (spot[next].first > dis && dis != -1)
					return;
				if (next == n && dis == -1)
					dis = spot[next].first;

				if (spot[next].second == spot[before].second)
					Q.push(next);
			}
		}
		if (before - 1 >= 0)
		{
			int next = before - 1;
			if (spot[next].first == -1 || (spot[next].first != -1 && spot[next].first >= spot[before].first + 1))
			{
				spot[next].first = spot[before].first + 1;
				spot[next].second += spot[before].second;

				if (spot[next].first > dis && dis != -1)
					return;
				if (next == n && dis == -1)
					dis = spot[next].first;

				if (spot[next].second == spot[before].second)
					Q.push(next);
			}
		}
	}
}

int main()
{
	pair<int, int> stn = { -1,0 };
	fill(spot, spot + 100001, stn);

	cin >> n >> k;

	Check();

	cout << spot[n].first << '\n' << spot[n].second;
}