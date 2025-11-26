#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n;
int tree[27][3];

void front(int num)
{
	cout << char(num + 'A');
	if (tree[num][0] != -1)
		front(tree[num][0]);
	if (tree[num][1] != -1)
		front(tree[num][1]);
}

void middle(int num)
{
	if (tree[num][0] != -1)
		middle(tree[num][0]);
	cout << char(num + 'A');
	if (tree[num][1] != -1)
		middle(tree[num][1]);
}

void last(int num)
{
	if (tree[num][0] != -1)
		last(tree[num][0]);
	if (tree[num][1] != -1)
		last(tree[num][1]);
	cout << char(num + 'A');
}

int main()
{
	fill_n(tree[0], 81, -1);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;

		if (b != '.')
			tree[a - 'A'][0] = b - 'A';
		if (c != '.')
			tree[a - 'A'][1] = c - 'A';
	}

	front(0);
	cout << '\n';
	middle(0);
	cout << '\n';
	last(0);
}