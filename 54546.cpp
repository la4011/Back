#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
int n;
int target_slot[100001];
int slot[100001];

int cnt = 0;	//전부 토글
int cnt0 = 1;	//전부 0세팅
int cnt1 = 0;	//전부 1세팅

int main()
{
	int err = 1;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> slot[i];

	for (int i = 0; i < n; i++)
	{
		cin >> target_slot[i];
		if (!target_slot[i])
			cnt1++;
		else
			cnt0++;

		if (slot[i] != target_slot[i])
			cnt++;
		if (slot[i] == 0)
			err = 0;
	}

	if (!err)
	{
		cnt1++;
		cnt0++;
	}

	cout << min({ cnt, cnt0, cnt1 });
}