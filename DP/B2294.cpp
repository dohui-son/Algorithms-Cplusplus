#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define endl "\n"
using namespace std;
int n, k, dp[10005], input[10005];
set<int> se;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill(&dp[0], &dp[0] + 10005, 100007);
    cin >> n >> k;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        se.insert(tmp);
        if (tmp <= k)
            dp[tmp] = 1;
    }

    for (int i = 1; i < k; i++)
    {
        for (auto s : se)
        {
            if (i + s <= k)
                dp[i + s] = min(dp[i] + 1, dp[i + s]);
        }
    }
    if (dp[k] == 100007)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[k] << endl;

    return 0;
}