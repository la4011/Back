#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, t;
int condition;
int slot[51][51] = { 0, };
int n_slot[51][51] = { 0, };

int hy[4] = { 0, 1, 0, -1 };
int hx[4] = { 1, 0 , -1, 0 };

void check()
{
	int tmp_slot[51][51] = { 0, };

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (slot[i][j] > 0)
			{
				int amount = slot[i][j];
				int spread_cnt = 0;

				for (int k = 0; k < 4; k++)
				{
					int ny = hy[k] + i;
					int nx = hx[k] + j;

					if (nx >= 0 && ny >= 0 && ny < r && nx < c && slot[ny][nx] != -1)
					{
						tmp_slot[ny][nx] += amount / 5;
						spread_cnt++;
					}
				}
				slot[i][j] -= ((amount / 5) * spread_cnt);
			}
		}
	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			slot[i][j] += tmp_slot[i][j];
}

void move()
{
	for (int i = condition - 2; i > 0; i--)
		slot[i][0] = slot[i - 1][0];
	for (int i = 0; i < c - 1; i++)
		slot[0][i] = slot[0][i + 1];
	for (int i = 0; i < condition - 1; i++)
		slot[i][c - 1] = slot[i + 1][c - 1];
	for (int i = c - 1; i > 1; i--)
		slot[condition - 1][i] = slot[condition - 1][i - 1];
	slot[condition - 1][1] = 0;

	for (int i = condition + 1; i < r - 1; i++)
		slot[i][0] = slot[i + 1][0];
	for (int i = 0; i < c - 1 ; i++)
		slot[r - 1][i] = slot[r - 1][i + 1];
	for (int i = r - 1; i > condition; i--)
		slot[i][c - 1] = slot[i - 1][c - 1];
	for (int i = c - 1; i > 1; i--)
		slot[condition][i] = slot[condition][i - 1];
	slot[condition][1] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> slot[i][j];
			if (slot[i][j] == -1)
			{
				condition = i;
				n_slot[i][j] = -1;
			}
		}

	while (t--)
	{
		check();
		move();
	}

	int sol = 0;
	for(int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (slot[i][j] > 0)
				sol += slot[i][j];
		}

	cout << sol;
}