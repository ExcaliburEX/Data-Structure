#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct pos
{
    int x, y;
    int num;
};
int n, m;
char map[550][550];
int vis[550][550];
int dir[4][2] = {1, 0, 0, -1, 0, 1, -1, 0};
int pre[550][550];
char str[5] = {"DLRU"};
void bfs()
{
    queue<pos> q;
    pos t;
    t.x = 1, t.y = 1, t.num = 0;
    q.push(t);
    vis[1][1] = 1;
    pre[1][1] = -1;
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        if (t.x == n && t.y == m)
        {
            printf("%d\n", t.num);
            return;
        }
        int i, j;
        pos tt;
        for (i = 0; i < 4; i++)
        {
            tt.x = t.x + dir[i][0];
            tt.y = t.y + dir[i][1];
            tt.num = t.num + 1;
            if (tt.x >= 1 && tt.x <= n && tt.y >= 1 && tt.y <= m && map[tt.x][tt.y] == '0' && vis[tt.x][tt.y] == 0)
            {
                pre[tt.x][tt.y] = i;
                q.push(tt);
                vis[tt.x][tt.y] = 1;
            }
        }
    }
}
void path(int x, int y)
{
    if (x == 1 && y == 1)
        return;
    path(x - dir[pre[x][y]][0], y - dir[pre[x][y]][1]);
    printf("%c", str[pre[x][y]]);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    getchar();
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            scanf("%c", &map[i][j]);
        }
        getchar();
    }
    bfs();
    path(n, m);
    return 0;
}