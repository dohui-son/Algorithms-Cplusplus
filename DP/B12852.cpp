#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define endl "\n"
int n, memo[1000002]; //1000,000

void go(int here)
{
    if (here == 0)
        return;
    cout << here << " ";
    if (here % 3 == 0 && memo[here] == (memo[here / 3] + 1))
        go(here / 3);
    else if (here % 2 == 0 && memo[here] == (memo[here / 2] + 1))
        go(here / 2);
    else if ((here - 1 >= 0) && (memo[here] == (memo[here - 1] + 1)))
        go(here - 1);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill(&memo[0], &memo[0] + 1000002, 1000004);
    cin >> n;
    memo[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i + 1 <= n)
            memo[i + 1] = min(memo[i] + 1, memo[i + 1]);
        if (i * 2 <= n)
            memo[i * 2] = min(memo[i] + 1, memo[i * 2]);
        if (i * 3 <= n)
            memo[i * 3] = min(memo[i] + 1, memo[i * 3]);
    }
    cout << memo[n] << endl;
    go(n);

    return 0;
}
/////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
int dp[1000004], n;
const int INF = 987654321;
void go(int here)
{
    if (here == 0)
        return;
    printf("%d ", here);
    if (here % 3 == 0 && dp[here] == (dp[here / 3] + 1))
        go(here / 3);
    else if (here % 2 == 0 && dp[here] == (dp[here / 2] + 1))
        go(here / 2);
    else if ((here - 1 >= 0) && (dp[here] == (dp[here - 1] + 1)))
        go(here - 1);
    return;
}
int main()
{
    scanf("%d", &n);
    fill(dp, dp + 1000004, INF);
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!(i % 3))
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        if (!(i % 2))
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }
    printf("%d\n", dp[n]);
    go(n);
    return 0;
}