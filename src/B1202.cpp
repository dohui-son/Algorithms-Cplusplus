#include <bits/stdc++.h>
using namespace std;
int64_t n, m, v, k, c, ans;
vector<int64_t> bag;
priority_queue<int64_t> pq;
vector<pair<int64_t, int64_t> > dia;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> v;
        dia.push_back({m, v});
    }
    sort(dia.begin(), dia.end());
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        bag.push_back(c);
    }
    sort(bag.begin(), bag.end());
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && dia[idx].first <= bag[i])
        {
            pq.push(dia[idx].second);
            idx++;
        }
        if (pq.size())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}
