#include <iostream>
#include <vector>
using namespace std;

long long a = 0;
long long b = 0;

//신발끈 공식 사용
int main()
{
	int n;
	cin >> n;

	long long fx, fy;
	cin >> fx >> fy;
	long long x = fx;
	long long y = fy;

	for (int i = 1; i < n; i++)
	{
		long long bx = x;
		long long by = y;
		cin >> x >> y;
		a += (bx * y);
		b += (by * x);
	}
	if(n!=1)
	{
		a += (x * fy);
		b += (y * fx);
	}

	double sol = (abs(a - b)) / 2.0;
	printf("%.1f", sol);
}