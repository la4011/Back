#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;
pair<int, int> V[200001];

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> V[i].first >> V[i].second;

    sort(V, V + n, cmp);

    priority_queue<int, vector<int>, greater<int>> P;
    P.push(V[0].second);
    for(int i = 1; i < n; i++)
    {
        if (V[i].first >= P.top())
            P.pop();
        P.push(V[i].second);
    }

    cout << P.size();
}
