#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n";

int n, s, e, ans;
vector<pair<int, int> > v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        v.push_back({e, s});
    }
    sort(v.begin(), v.end());
    e = 0;
    for (int i = 0; i < n; i++)
    {
        if (e <= v[i].second)
        {
            ans++;
            e = v[i].first;
        }
    }
    cout << ans << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// #define endl "\n";
// int n, s, e, ans;
// vector<pair<int64_t, int64_t> > v;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> s >> e;
//         v.push_back({e, s});
//     }

//     sort(v.begin(), v.end());
//     s = v[0].first;
//     ans++;
//     for (int i = 1; i < n; i++)
//     {
//         if (v[i].second >= s)
//         {
//             ans++;
//             s = v[i].first;
//         }
//     }

//     cout << ans;

//     return 0;
// }