#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, c, a[1000004], ret, sum, ret_cnt;
bool check(ll mid)
{
    ll cnt = 0;
    for (int i = 0; i < s; i++)
        cnt += a[i] / mid;
    return cnt >= c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> c;
    for (int i = 0; i < s; i++)
        cin >> a[i], sum += a[i];
    ll lo = 1, hi = 1e9; //*********
    while (lo <= hi)
    {
        ll mid = (lo + hi) / (1LL * 2); //**************
        if (check(mid))
        {
            lo = mid + 1;
            ret = mid;
        }
        else
            hi = mid - 1;
    }
    cout << sum - ret * c << "\n";
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;
// #define endl "\n"
// typedef long long ll;
// int64_t s, c, tmp, sum, ans;
// vector<int64_t> pa;
// bool check(int64_t mid)
// {
//     int64_t cnt = 0;
//     for (int i = 0; i < s; i++)
//     {
//         cnt += pa[i] / mid;
//     }
//     return cnt >= c;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> s >> c;
//     for (int i = 0; i < s; i++)
//     {
//         cin >> tmp;
//         pa.push_back(tmp);
//         sum += tmp;
//     }
//     int64_t lo = 1, hi = sum, mid = 0;
//     while (lo <= hi)
//     {
//         mid = (lo + hi) / 2;
//         if (check(mid))
//         {
//             lo = mid + 1;
//             ans = mid;
//         }
//         else
//             hi = mid - 1;
//     }
//     cout << sum - ans * c << endl;

//     return 0;
// }