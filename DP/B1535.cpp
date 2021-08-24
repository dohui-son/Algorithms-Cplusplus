#include <bits/stdc++.h>
using namespace std;
int n, cost[101], happy[101];
vector<int> dp(101);
double temp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> happy[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 100; j > cost[i]; j--)
            dp[j] = max(dp[j], dp[j - cost[i]] + happy[i]);
    }
    cout << dp[100] << endl;

    return 0;
}