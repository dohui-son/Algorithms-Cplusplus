#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int dp[2504][2504], dp2[2504];
const int INF = 9876543321;
string s;

int go(int here)
{
    if (here == s.size())
        return 0;
    if (dp2[here] != INF)
        return dp2[here];
    int &ret = dp2[here];
    for (int i = 1; here + i <= s.size(); i++)
    {
        if (dp[here][i])
            ret = min(ret, go(here + i) + 1);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    dp[s.size() - 1][1] = 1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        dp[i][1] = 1;
        if (s[i] == s[i + 1])
            dp[i][2] = 1; //dp[i][2] == i번째에서 뒤로 2개 비해 같다
    }
    for (int sizee = 3; sizee <= s.size(); sizee++)
    {
        for (int j = 0; j + sizee <= s.size(); j++)
        {
            if (s[j] == s[j + sizee - 1] && dp[j + 1][sizee - 2])
                dp[j][sizee] = 1;
        }
    }
    fill(dp2, dp2 + 2504, INF);
    cout << go(0) << endl;

    return 0;
}