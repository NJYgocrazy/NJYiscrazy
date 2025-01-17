#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e4 + 10;
int ans, n, a[N], f[N];
int flag;

int hi()
{
    for (int i = 2; i < n; i++)
    {
        int t = a[i] - f[i - 1] - f[i];
        if (t < 0 || t > 1)
            return 0;
        else
            f[i + 1] = t;
    }
    if (f[n] + f[n - 1] != a[n])
        return 0;
    return 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > 3)
            flag = 1;
    }
    if (a[0] > 2 || a[n - 1] > 2 || flag)
    {
        cout << 0 << endl;
        return 0;
    }
    if (a[1] == 2)
    {
        f[1] = 1;
        f[2] = 1;
        ans += hi();
    }
    else if (a[1] == 0)
    {
        f[1] = 0;
        ans += hi();
    }
    else if (a[1] == 1)
    {
        f[1] = 1;
        ans += hi();
        memset(f, 0, sizeof f);
        f[2] = 1;
        ans += hi();
    }
    cout << ans << endl;
}