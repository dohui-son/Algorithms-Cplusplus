#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl "\n"
int n, k, tmp, dp[10001];
int main()
{
    scanf("%d %d", &n, &k);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        if (tmp >= 10001)
            continue;
        for (int j = tmp; j <= k; j++)
            dp[j] += dp[j - tmp];
    }
    printf("%d\n", dp[k]);
    return 0;
}