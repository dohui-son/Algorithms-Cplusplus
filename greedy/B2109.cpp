#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, d, p, ans;
priority_queue<int, vector<int>, greater<int> > pq;
vector<pair<int, int> > v;
#define endl '\n';

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        pq.push(v[i].second);
        if (v[i].first < pq.size())
            pq.pop();
    }
    while (pq.size())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;

    return 0;
}
