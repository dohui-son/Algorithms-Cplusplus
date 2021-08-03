#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, mid, ret;
int main()
{
    cin >> a >> b;
    ll z = b * 100 / a;
    ll lo = 0, hi = 1e9;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if ((b + mid) * 100 / (a + mid) > z)
        {
            ret = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << (ret ? ret : -1) << "\n";
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>

// #define endl "\n"
// using namespace std;
// typedef long long ll;
// ll x, y, ans = 1e9, z;

// bool check(ll mid)
// {
//     ll bunja = 100 * (y + mid);
//     bunja /= (x + mid);
//     return z < bunja;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> x >> y;
//     z = y * 100 / x;
//     ll lo = 0, hi = 1e9, mid = 0;
//     while (lo <= hi)
//     {
//         mid = (lo + hi) / 2;
//         if (check(mid))
//         {
//             ans = mid;
//             hi = mid - 1;
//         }
//         else
//             lo = mid + 1;
//     }

//     if (ans == 1e9)
//         cout << -1 << endl;
//     else
//         cout << ans << endl;

//     return 0;
// }