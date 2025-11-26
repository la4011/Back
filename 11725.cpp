#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, a, b;
vector<int> V[100002];
bool vis[100002] = { 0, };
queue<int> Q;
int parent[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	Q.push(1);
	vis[1] = 1;

	while (!Q.empty())
	{
		int before = Q.front();
		Q.pop();

		vector<int>::iterator ptr;
		for (ptr = V[before].begin(); ptr != V[before].end(); ptr++)
		{
			int next = *ptr;
			if (vis[next] == 1)
				continue;

			vis[next] = 1;
			parent[next] = before;
			Q.push(next);
		}
	}

	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}