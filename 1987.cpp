#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int r, c;
int slot[21][21];
int check[26] = {0,};

int hy[4] = {0,1,0,-1};
int hx[4] = {1,0,-1,0};
int sol = 0;

void DFS(int cnt, pair<int,int> location)
{
    int x = location.second;
    int y = location.first;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + hx[i];
        int ny = y + hy[i];

        if(nx < 0 || ny < 0 || nx >= c || ny >= r)
        continue;
        int item = slot[ny][nx];
        if(check[item] == 1)
        continue;

        check[item] = 1;
        DFS(cnt+1, {ny,nx});
        check[item] = 0;
    }
    sol = max(sol, cnt);
}

int main()
{
    cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for(int p = 0; p < s.size(); p++)
            slot[i][p] = s[p] - 'A';
    }

    check[slot[0][0]] = 1;
    DFS(1, {0,0});
    

    cout << sol;
}