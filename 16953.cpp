#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int a, b;
queue<pair<int,int>> Q;
int sol = -2;

int main()
{
	cin >> a >> b;
	Q.push({b, 0});

	while (!Q.empty())
	{
		int num, time;
		tie(num, time) = Q.front();
		if (num == a)
		{
			sol = time;
			break;
		}
		Q.pop();

		for (int i = 0; i < 2; i++)
		{
			if (!i)
				if (num % 2 == 0)
					Q.push({ num / 2, time + 1 });

			if (i)
				if (num % 10 == 1 && num > 10)
					Q.push({ num / 10, time + 1 });
		}
	}

	cout << sol+1;
}