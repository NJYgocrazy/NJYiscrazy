#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4;
struct node
{
    int cnt;
    int id;
} ct1[N], ct2[N];

bool cmpcnt(node a, node b)
{
    return a.cnt > b.cnt; // 从大到小找最优解
}

bool cmpid(node a, node b)
{
    return a.id < b.id; // 从小到大满足输出要求
}

int main()
{
    int m, n, k, l, d;
    cin >> m >> n >> k >> l >> d;
    while (d--)
    {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if (x == p)
        {
            int yy = min(y, q);
            ct1[yy].cnt++;
            ct1[yy].id = yy;
        }
        else if (y == q)
        {
            int xx = min(x, p);
            ct2[xx].cnt++;
            ct2[xx].id = xx;
        }
    }
    sort(ct1, ct1 + n, cmpcnt);
    sort(ct2, ct2 + m, cmpcnt);
    sort(ct1, ct1 + l, cmpid);
    sort(ct2, ct2 + k, cmpid);
    for (int i = 0; i < k; i++)
        cout << ct2[i].id << " ";
    cout << endl;
    for (int i = 0; i < l; i++)
        cout << ct1[i].id << " ";
    return 0;
}