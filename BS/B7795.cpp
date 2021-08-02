#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int t, n, m, tmp;
vector<int> a;
vector<int> b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            b.push_back(tmp);
        }
        sort(b.begin(), b.end());

        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            int idx = (int)(lower_bound(b.begin(), b.end(), a[j]) - b.begin());
            ans += idx;
        }
        cout << ans << endl;
        a.clear();
        b.clear();
    }

    return 0;
}
//////////////////다른 사람 코드
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        int ret = 0;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            auto pos = lower_bound(b.begin(), b.end(), a[i]);
            ret += (int)(pos - b.begin());
        }
        cout << ret << "\n";
    }
}