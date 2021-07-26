#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
int64_t n, l, s, e, ans, idx;
int nn[10002];
vector<pair<int, int> > v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i].second <= idx)
            continue;
        if (idx < v[i].first)
        {
            int b = (v[i].second - v[i].first) / l + ((v[i].second - v[i].first) % l ? 1 : 0);
            ans += b;
            idx = v[i].first + b * l;
        }
        else
        {
            int b = (v[i].second - idx) / l + ((v[i].second - idx) % l ? 1 : 0);
            ans += b;
            idx = idx + b * l;
        }
    }

    cout << ans << endl;

    return 0;
}