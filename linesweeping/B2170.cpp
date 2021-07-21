#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define endl '\n'

int n;
int64_t x, y, ans;
vector<pair<int64_t, int64_t> > v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int64_t l, r;
    l = v[0].first;
    r = v[0].second;

    for (int i = 1; i < n; i++)
    {
        if (r < v[i].first)
        {
            ans += r - l;
            l = v[i].first;
            r = v[i].second;
        }
        else if (v[i].second > r)
        {
            r = v[i].second;
        }
    }
    ans += r - l;
    cout << ans << endl;

    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;
// #define endl '\n'

// int n;
// int64_t x, y, ans;
// vector<pair<int64_t, int64_t> > v;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> x >> y;
//         v.push_back({x, y});
//     }
//     sort(v.begin(), v.end());
//     int64_t l, r;
//     l = v[0].first;
//     r = v[0].second;
//     for (int i = 1; i < n; i++)
//     {
//         if (r < v[i].first)
//         {
//             ans += r - l;
//             r = v[i].second;
//             l = v[i].first;
//         }
//         else if (r <= v[i].second)
//             r = v[i].second;
//     }
//     ans += r - l;
//     cout << ans << endl;
// }
/////////////////////////////////////////////////////////////
// #include <algorithm>
// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;
// int n;
// long long x, y, ans;
// vector<pair<long, long> > v;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> x >> y;
//         v.push_back({x, y});
//     }

//     sort(v.begin(), v.end());

//     long long s = v[0].first;
//     long long e = v[0].second;
//     for (int i = 1; i < n; i++)
//     {
//         if (v[i].first > e)
//         { // bigger
//             ans += abs(e - s);
//             s = v[i].first;
//             e = v[i].second;
//         }
//         else if (e <= v[i].second)
//             e = v[i].second;
//     }
//     ans += abs(e - s);
//     cout << ans;
//     return 0;
// }