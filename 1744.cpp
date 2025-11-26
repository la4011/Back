#include <iostream>
#include <algorithm>
using namespace std;
int n;
int slot[51];
int PLUS[51];
int MINUS[51];
int zero = 0;
int one = 0;
int sol = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> slot[i];

	int pcnt = 0;
	int mcnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (slot[i] == 1)
			one++;
		else if (slot[i] > 1)
			PLUS[pcnt++] = slot[i];
		else if (slot[i] < 0)
			MINUS[mcnt++] = slot[i];
		else
			zero++;
	}

	sort(PLUS, PLUS + pcnt, greater<int>());
	sort(MINUS, MINUS + mcnt);

	for (int i = 0; i < pcnt; i++)
	{
		if (i + 1 >= pcnt)
			sol += PLUS[i];
		else
		{
			sol += PLUS[i] * PLUS[i + 1];
			i++;
		}
	}

	for (int i = 0; i < mcnt; i++)
	{
		if (i + 1 >= mcnt)
		{
			if (zero == 0)
				sol += MINUS[i];
		}
		else
		{
			sol += MINUS[i] * MINUS[i + 1];
			i++;
		}
	}

	sol += one;

	cout << sol;
}