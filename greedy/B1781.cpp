#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl "\n";

int n, d, c;
int64_t ans;
vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> c;
        v.push_back({d, c});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        pq.push(v[i].second);
        ans += v[i].second;
        if (pq.size() > v[i].first)
        {
            ans -= pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;
// #define endl "\n";
// vector<pair<int, int> > v;
// int n, ans;
// priority_queue<int, vector<int>, greater<int> > pq;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n;
//     int d = 0, c = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> d >> c;
//         v.push_back({d, c});
//     }
//     sort(v.begin(), v.end());
//     for (int i = 0; i < n; i++)
//     {
//         pq.push(v[i].second);
//         ans += v[i].second;
//         if (pq.size() > v[i].first)
//         {
//             ans -= pq.top();
//             pq.pop();
//         }
//     }
//     cout << ans;

//     return 0;
// }