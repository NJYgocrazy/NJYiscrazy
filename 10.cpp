#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
int a[N], n, k;

bool check(int x)
{
    int b[N];
    ll sum = 0;
    memcpy(b, a, sizeof a);
    for (int i = 1; i <= n; i++)
    {
        b[i] -= x;
        if (b[i] > 0)
            sum += ceil((double)b[i] / (k - 1));
    }
    if (sum > x)
        return false;
    return true;
}

int main()
{
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    cin >> k;
    if (k <= 1)
    {
        cout << mx << endl;
        return 0;
    }

    int l = 0, r = 0x3f3f3f3f;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}