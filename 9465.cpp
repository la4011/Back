#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int t;
int n;
int num[3][100001];
int sol[1000001][4];

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> num[0][i];
		for (int i = 0; i < n; i++)
			cin >> num[1][i];

		sol[0][0] = 0;			//아무것도 선택하지 않는 경우
		sol[0][1] = num[0][0];	//위 [0]을 선택하는 경우
		sol[0][2] = num[1][0];	//아래 [1]를 선택하는 경우

		for (int i = 1; i < n; i++)
		{
			sol[i][0] = max({ sol[i - 1][0],sol[i - 1][1], sol[i - 1][2] });
			sol[i][1] = max(sol[i - 1][0], sol[i - 1][2]) + num[0][i];
			sol[i][2] = max(sol[i - 1][0], sol[i - 1][1]) + num[1][i];
		}

		cout << max({ sol[n - 1][0], sol[n - 1][1], sol[n - 1][2] }) << '\n';
	}
}