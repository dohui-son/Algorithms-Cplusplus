#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
int n, a, b, len, lis[504];
vector<pair<int, int> > v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        auto it = lower_bound(lis, lis + len, v[i].second);
        if (*it == 0)
            len++;
        *it = v[i].second;
    }
    cout << n - len << endl;
    return 0;
}

////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;
int n, ans, tmp1, tmp2, maxim;
vector<pair<int, int> > lis;
int cnt[504];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp1 >> tmp2;
        lis.push_back({tmp1, tmp2});
    }
    sort(lis.begin(), lis.end());
    for (int i = 0; i < n; i++)
    {
        int maxim = 0;
        for (int j = 0; j < i; j++)
        {
            if (lis[j].second < lis[i].second && maxim < cnt[j])
            {
                maxim = cnt[j];
            }
        }
        cnt[i] = maxim + 1;
        ans = max(cnt[i], ans);
    }
    cout << n - ans << endl;
    return 0;
}