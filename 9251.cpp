#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int LCS[1001][1001];

int main()
{
	string s;
	char s1[1001], s2[1002];
	cin >> s;
	for (int i = 1; i <= s.size(); i++)
		s1[i] = s[i - 1];
	int size1 = s.size();
	cin >> s;
	for (int i = 1; i <= s.size(); i++)
		s2[i] = s[i - 1];
	int size2 = s.size();

	for (int i = 0; i <= size1; i++)
	{
		for (int j = 0; j <= size2; j++)
		{
			if (i == 0 || j == 0)
				LCS[i][j] = 0;
			else if (s1[i] == s2[j])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}

	int sol = 0;
	for (int i = 0; i <= size2; i++)
		sol = max(sol, LCS[size1][i]);

	cout << sol;
}