#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pp;

char b[1005][1005];
int x1, y1, x2, y2;
int n, m;
queue<pp> q[2]; // q[0]即为小B，q[1]为小A
// 用0，1其实是一个小技巧，在需要联系另一个人的时候直接非！一次即可
bool flag, v[2][1005][1005]; // 同理我们用这样一个三维的bool数组来分开标记a和b走过的地方
int ans = 0;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool bfs(int a)
{
    int x = 0, y = 0;
    int t = q[a].size();
    while (t--)
    {
        auto qq = q[a].front();
        q[a].pop();
        for (int i = 0; i < 4 + (a ? 4 : 0); i++)
        {
            x = qq.first + dx[i], y = qq.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || b[x][y] == '#' || v[a][x][y])
                continue;
            if (v[!a][x][y])
            {
                flag = 1;
                return true;
            }
            v[a][x][y] = 1;
            q[a].push({x, y});
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
            if (b[i][j] == 'D')
                x1 = i, y1 = j;
            if (b[i][j] == 'C')
                x2 = i, y2 = j;
        }
    }
    v[0][x1][y1] = true;
    q[0].push({x1, y1});
    v[1][x2][y2] = true;
    q[1].push({x2, y2});
    while (!q[1].empty() || !q[0].empty())
    {
        ans++;
        if (bfs(0))
            break;
        if (bfs(0))
            break;
        if (bfs(1))
            break;
    }
    if (flag)
        cout << "YES" << endl
             << ans;
    else
        cout << "NO";
    return 0;
}