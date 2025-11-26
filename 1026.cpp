#include <iostream>
#include <algorithm>
using namespace std;
int n;
int A[51];
int B[51];
int sol = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		cin >> B[i];

	sort(A, A + n, greater<int>());
	sort(B, B + n);

	for (int i = 0; i < n; i++)
		sol += A[i] * B[i];

	cout << sol;
}