#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int n;
long long x, y, ans;
vector<pair<long, long> > v;

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

    long long s = v[0].first;
    long long e = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > e)
        { // bigger
            ans += abs(e - s);
            s = v[i].first;
            e = v[i].second;
        }
        else if (e <= v[i].second)
            e = v[i].second;
    }

    ans += abs(e - s);

    cout << ans;
    return 0;
}