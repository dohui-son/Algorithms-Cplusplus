#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl "\n"
int n, arrive, t;
int64_t now;
vector<pair<int, int> > v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arrive >> t;
        v.push_back({arrive, t});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (now >= v[i].first)
            now += v[i].second;
        else if (now < v[i].first)
            now = v[i].first + v[i].second;
    }
    cout << now << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// #define endl "\n";
// int n, start, t, now;
// vector<pair<int, int> > v;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> start >> t;
//         v.push_back({start, t});
//     }
//     sort(v.begin(), v.end());
//     now = v[0].first + v[0].second;
//     for (int i = 1; i < n; i++)
//     {
//         now = max(now, v[i].first);
//         now += v[i].second;
//     }
//     cout << now;

//     return 0;
// }