#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, lc, pc;
vector<int> party[51]; //파티에 어떤 멤버가 참가하는가
vector<int> member[51]; //멤버가 어떤 파티에 참가하는가
queue<int> liar; //진실을 원래 알고 있는 인원들 저장
int liarcheck[51]; //각 멤버가 진실을 알게되었는가

int main()
{
	cin >> n >> m;

	cin >> lc;
	for (int i = 0; i < lc; i++)
	{
		int a;
		cin >> a;
		liarcheck[a] = 1;
		liar.push(a);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> pc;
		for (int j = 0; j < pc; j++)
		{
			int a;
			cin >> a;
			party[i].push_back(a);
			member[a].push_back(i);
		}
	}

	while (!liar.empty())
	{
		int start = liar.front();
		liar.pop();

		for (int p : member[start])
		{
			for (int o : party[p])
			{
				if(liarcheck[o] == 0)
				{
					liarcheck[o] = 1;
					liar.push(o);
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		bool flag = 0;
		for (int p : party[i])
			if (liarcheck[p] == 1)
			{
				flag = 1;
				break;
			}
		if (!flag)
			cnt++;
	}

	cout << cnt;
}