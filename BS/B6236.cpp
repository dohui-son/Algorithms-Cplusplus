#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;
int n, m, k, ans = 100000, tmp, psum;
vector<int> v;
bool check(int mid)
{
    int real_mid = mid, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (mid - v[i] >= 0)
        {
            mid -= v[i];
        }
        else
        {
            cnt++;
            mid = real_mid;
            mid -= v[i];
            if (mid < 0)
                return false;
        }
    }
    return cnt <= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        psum += tmp;
    }
    int lo = 0, hi = psum, mid = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// #define co(a) cout << a << "\n";
// typedef long long ll;
// int n, m, a[100005], _max;
// void fastIO()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
// }
// bool check(int mid)
// {
//     int cnt = 1;
//     int real_mid = mid;
//     for (int i = 0; i < n; i++)
//     {
//         if (mid - a[i] >= 0)
//         {
//             mid -= a[i];
//         }
//         else
//         {
//             //남은 금액을 넣고 통장에서 인출했다!
//             mid = real_mid;
//             cnt++;
//             if (a[i] > mid)
//                 return false;
//             else
//                 mid -= a[i];
//         }
//     }
//     return cnt <= m;
// }
// int main()
// {
//     fastIO();
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//         cin >> a[i], _max = max(a[i], _max);
//     int lo = 1, hi = 100004, ret;
//     while (lo <= hi)
//     {
//         int mid = (lo + hi) / 2;
//         if (check(mid))
//         {
//             hi = mid - 1;
//             ret = mid;
//         }
//         else
//             lo = mid + 1;
//     }
//     cout << ret << "\n";
//     return 0;
// }