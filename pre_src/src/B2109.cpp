#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define endl "\n";

int n, ans;
vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int pp, dd;
    for (int i = 0; i < n; i++)
    {
        cin >> pp >> dd;
        v.push_back({dd, pp});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        pq.push(v[i].second);
        if (pq.size() > v[i].first)
            pq.pop();
    }
    while (pq.size())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;

    return 0;
}