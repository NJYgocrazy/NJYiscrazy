#include <iostream>

using namespace std;

const int N = 100;
int n, m, t;
int dx[4] = {1, 1, 2, 2};
int dy[4] = {2, -2, 1, -1}; // 用两个数组来表示方向的移动向量，在移动的时候只需要去遍历数组即可，类似于上面对上下左右的处理

void dfs(int x, int y)
{
    if (x == n && y == m)
    {
        t++;
        return;
    }
    else if (x > n || x < 1 || y > m || y < 1)
        return;
    else
    {
        for (int i = 0; i < 4; i++)
            dfs(x + dx[i], y + dy[i]);
        // 每次循环就相当于往一种情况移动，再以这种移动进入dfs直到出界或者走到终点，如果出界的话就会被return到上一层的dfs，相当于进行了一次回溯
    }
}

int main()
{
    cin >> m >> n;
    dfs(1, 1);
    cout << t << endl;
    return 0;
}