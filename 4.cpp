#include <iostream>

using namespace std;

const int N = 100;
int mp[12][12], cnt;
bool h[12][12], l[12][12], gong[12][12];
// dfs的一个关键点是如何判断可行从而进行下一步搜索
// 根据数独的要求这里分为行列和九宫格三个判断条件

struct sp
{
    int x;
    int y;
} space[N];

const int g[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
};
// 这里使用了一个打表的小技巧，通过二维数组的值来代指目前的位置处于第几个九宫格 巧思啊！

void print()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            cout << mp[i][j];
            if (j == 9)
                cout << endl;
            else
                cout << " ";
        }
}

void dfs(int u)
{
    if (u > cnt)
    {
        print();
        return;
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            int xx = space[u].x;
            int yy = space[u].y;
            if (!h[xx][i] && !l[yy][i] && !gong[g[xx][yy]][i])
            {
                h[xx][i] = 1, l[yy][i] = 1, gong[g[xx][yy]][i] = 1;
                mp[xx][yy] = i;
                dfs(u + 1);
                h[xx][i] = l[yy][i] = gong[g[xx][yy]][i] = 0;
                mp[xx][yy] = 0;
            }
        }
    }
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 0)
            {
                space[++cnt].x = i;
                space[cnt].y = j;
            }
            h[i][mp[i][j]] = true;
            l[j][mp[i][j]] = true;
            gong[g[i][j]][mp[i][j]] = true;
            // 这里的三个布尔数组的意思为，第i行的这个数已经存在以此类推
            // 故而在dfs过程中，实际上深搜的是从1~9的每个数，即这个数可以放在哪些地方
        }
    }
    dfs(1);
    return 0;
}