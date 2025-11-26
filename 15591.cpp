#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, q;
vector<pair<int, int>> graph[5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    while (q--) {
        int k, v;
        cin >> k >> v;

        vector<int> vis(n + 1, 0);
        queue<int> Q;
        vis[v] = 1;
        Q.push(v);

        int cnt = 0;

        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();

            for (auto [next, usado] : graph[cur]) {
                if (vis[next]) continue;
                if (usado < k) continue;
                vis[next] = 1;
                cnt++;
                Q.push(next);
            }
        }

        cout << cnt << '\n';
    }
}
