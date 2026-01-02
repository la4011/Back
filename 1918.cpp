#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

deque<char> dq;
string s;

int priority(char a)
{
	if (a == '+' || a == '-')
		return 1;
	if (a == '*' || a == '/')
		return 2;
	return 0;
}

int main()
{
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c >= 'A' && c <= 'Z')
			cout << c;
		else if (c == '(')
			dq.push_back(c);
		else if(c == ')')
		{
			while (!dq.empty() && dq.back() != '(')
			{
				cout << dq.back();
				dq.pop_back();
			}
			if (!dq.empty())
				dq.pop_back();
		}
		else
		{
			while (!dq.empty() && priority(dq.back()) >= priority(c))
			{
				cout << dq.back();
				dq.pop_back();
			}
			dq.push_back(c);
		}
	}
	while (!dq.empty())
	{
		cout << dq.back();
		dq.pop_back();
	}
}