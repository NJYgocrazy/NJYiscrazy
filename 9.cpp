#include <bits/stdc++.h>
using namespace std;
struct node
{
    int fir, sec;
    bool operator<(const node &a) const
    {
        return fir * sec < a.fir * a.sec;
    }
} st[1005];
int sum[5050];
int vis[5050];
int arr[5050];
int len = 1, tex = 1;
void cheng(int b)
{
    for (int i = 1; i <= len; i++)
    {
        vis[i] *= b;
    }
    for (int i = 1; i <= len; i++)
    {
        vis[i + 1] += vis[i] / 10;
        vis[i] %= 10;
    }
    if (vis[len + 1] != 0)
        len++;
    while (vis[len] > 10)
    {
        vis[len + 1] += vis[len] / 10;
        vis[len] %= 10;
        len++;
    }
}
void chu(int b)
{
    int t = 0, flag = 0, ans = 0;
    for (int i = len; i >= 1; i--)
    {
        t = t * 10 + vis[i];
        if (t < b && flag == 0)
            continue;
        else
        {
            flag = 1;
            arr[++ans] = t / b;
            t %= b;
        }
    }
    if (ans > tex)
    {
        for (int i = 1; i <= ans; i++)
            sum[i] = arr[i];
        tex = ans;
    }
    else
    {
        if (ans == tex)
        {
            for (int i = 1; i <= ans; i++)
            {
                if (arr[i] > sum[i])
                {
                    for (int i = 1; i <= ans; i++)
                    {
                        sum[i] = arr[i];
                    }
                    break;
                }
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> st[i].fir >> st[i].sec;
    }
    sort(st + 1, st + 1 + n);
    sum[1] = vis[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        cheng(st[i - 1].fir);
        chu(st[i].sec);
    }
    for (int i = 1; i <= tex; i++)
        cout << sum[i];
    cout << "\n";
    return 0;
}