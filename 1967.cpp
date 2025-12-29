#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> line[10001];
int far;
int dis[10001];
int M = 0;

void BFS(int item)
{
	fill(dis, dis+10001, -1);
	queue<int> Q;
	
	Q.push(item);
	dis[item] = 0;

	while(!Q.empty())
	{
		int before = Q.front();
		Q.pop();

		for(auto after : line[before])
		{
			int add_dis = after.second;
			int dest = after.first;

			if(dis[dest] != -1 && dis[dest] <= dis[before] + add_dis)
			continue;
			
			dis[dest] = dis[before] + add_dis;
			Q.push(dest);
			if(M < dis[dest])
				{
					M = max(M, dis[dest]);
					far = dest;
				}
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		line[a].push_back({b,c});
		line[b].push_back({a,c});
	}

	BFS(1);
	M = 0;
	BFS(far);

	cout << M;
}