#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

int n, w, v, k, dp[100001];
inline int max(int a, int b) { return a > b ? a : b; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        for (int j = k; j >= w; j--)
            dp[j] = max(dp[j], dp[j - w] + v);
    }
    cout << dp[k] << endl;
    return 0;
}
