#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int slot[17][17] = { 0, }; //y, x
int hx[3] = { 1, 1, 0 };
int hy[3] = { 0, 1, 1 };
int dp[17][17][3];

int DFS(int y, int x, int before)
{
	if (dp[y][x][before] != -1)
		return dp[y][x][before];

	int cnt = 0;

	for (int i = 0; i < 3; i++)
	{
		int nx = hx[i] + x;
		int ny = hy[i] + y;

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) //범위이탈 검사
			continue;
		if (slot[ny][nx] == 1) //벽지범위 검사
			continue;
		if (before == 0 && i == 2)//수직꺾임 검사
			continue;
		if (i == 1 && (slot[y + 1][x] == 1 || slot[y][x + 1] == 1))//대각선 이동가능여부확인
			continue;
		if (before == 2 && i == 0)//수직 꺾임 검사
			continue;
		
		if (ny == n - 1 && nx == n - 1)
		{
			cnt++;
			continue;
		}

		cnt += DFS(ny, nx, i);
	}
	dp[y][x][before] = cnt;
	return cnt;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> slot[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 3; k++)
				dp[i][j][k] = -1;

	cout << DFS(0, 1, 0);

	
}