#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int t;

int main()
{
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		string s;
		cin >> s;

		size_t result1 = s.find("2026");
		size_t result2 = s.find("2025");
		if (result1 == string::npos && result2 != string::npos)
			cout << "1" << '\n';
		else
			cout << "0" << '\n';
	}
}