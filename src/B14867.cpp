#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int64_t a, b, aa, bb, ans = 987654321;
int64_t dp[100002][100002];

//기저사례//로직//메모자이제이션//초기화

int64_t go(int aaa, int bbb, int cnt)
{
    if (aaa == aa && bbb == bb)
    {
        ans = min(ans, cnt);
        return cnt;
    }
    if (aaa < 0 || bbb < 0 || aaa > aa || bbb > bb)
        return -1e9;

    int64_t &ret = dp[aaa][bbb];
    if (~ret)
        return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> a >> b >> aa >> bb;
    dp[0][0] = 0;
    dp[aa][0] = 1;
    dp[0][bb] = 1;
    min(go(aa, 0, 1), go(0, bb, 1));
    cout << ans << endl;

    return 0;
}
