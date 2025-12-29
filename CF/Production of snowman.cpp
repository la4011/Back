#include <iostream>
#include <vector>
using namespace std;
int n;
int body_leg[5001];
int head[5001];
int body[5001];
int leg[5001];

long long shift(int arr1[5001], int arr2[5001])
{
	int tmp_cnt = 0;

	for (int i = 0; i < n; i++)
	{
		bool flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr1[j] >= arr2[(i + j) % n])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
			tmp_cnt++;
	}
	return tmp_cnt;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		fill(body_leg, body_leg + 5001, 0);
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> head[i];
		for (int i = 0; i < n; i++)
			cin >> body[i];
		for (int i = 0; i < n; i++)
			cin >> leg[i];

		long long case1 = shift(head, body);
		long long case2 = shift(body, leg);

		cout << case1 * case2 * n << '\n';
	}
}