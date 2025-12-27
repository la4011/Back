#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int city[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int dis[13][101];
int sol = 1e9;
vector<int> choice;

int Chicken_distance()
{
	int tmp_sol = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int tmp = 1e9;
		for (int j = 0; j < m; j++)
		{
			int item = choice[j];
			tmp = min(tmp, dis[item][i]);
		}
		tmp_sol += tmp;
	}
	return tmp_sol;
}

void check(int cnt, int idx)
{
	if (cnt == m)
	{
		int tmp = Chicken_distance();
		sol = min(sol, tmp);
		return;
	}

	for (int i = idx; i < chicken.size(); i++)
	{
		choice.push_back({ i });
		check(cnt + 1, i + 1);
		choice.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 2)
				chicken.push_back({ i,j });
			if (city[i][j] == 1)
				house.push_back({ i,j });
		}

	for (int i = 0; i < chicken.size(); i++)
	{
		auto from = chicken[i];
		int fy = from.first;
		int fx = from.second;
		for (int j = 0; j < house.size(); j++)
		{
			auto arival = house[j];
			int ay = arival.first;
			int ax = arival.second;

			dis[i][j] = abs(fy - ay) + abs(fx - ax);
		}
	}

	check(0, 0);

	cout << sol;
}