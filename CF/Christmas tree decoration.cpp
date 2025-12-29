#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MOD 998244353

long long pac[51];
long long nCr[51][51];

int main()
{
	pac[0] = 1;
	for (int i = 1; i <= 50; i++)
		pac[i] = (pac[i - 1] * i) % MOD;

	for (int i = 0; i <= 50; i++)
	{
		nCr[i][0] = 1;
		for (int j = 1; j <= i; j++)
			nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		long long cnt = 0;
		int box[52];
		int tot = 0;
		vector<int> high;
		vector<int> low;

		cin >> n;
		
		cin >> box[0];
		tot += box[0];
		for (int i = 1; i <= n; i++)
		{
			cin >> box[i];
			tot += box[i];
		}
		int tmp = tot / n; //1인당 트리에 달 수 있는 가장 작은 값
		int mem = tot % n; //작은값+1만큼 달아야하는 사람 수

		bool flag = 0;
		for(int i = 1; i <= n; i++)
			if (tmp + 1 < box[i])
			{
				cout << 0 << '\n';
				flag = 1;
				break;
			}
		if (flag)
			continue;

		long long addcnt = 0;

		for (int i = 1; i <= n; i++)
		{
			if (box[i] < tmp)
				addcnt += (tmp - box[i]);

			if (box[i] > tmp)
				high.push_back(i);
			else
				low.push_back(i);
		}

		if (high.size() > mem)
		{
			cout << 0 << '\n';
			continue;
		}

		int need = mem - high.size();
		addcnt += need;

		if (addcnt > box[0])
		{
			cout << 0 << '\n';
			continue;
		}

		cnt = nCr[low.size()][need]; //작은 사람 더미에서 need만큼 뽑는 경우의 수
		long long ord = (pac[mem] * pac[n - mem]) % MOD; //!먼저 뽑아야하는 사람 * !나중에 뽑아야하는 사람
		cout << (cnt * ord) % MOD << '\n';
	}
}