#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;
int dp[1004][2][34], n, m, b[1004];

int go(int tt, int tree, int cnt)
{
    if (cnt < 0)
        return -1e9;
    if (tt == n)
        return cnt == 0 ? 0 : -1e9;
    int &ret = dp[tt][tree][cnt];
    if (~ret)
        return ret;
    return ret = max(go(tt + 1, tree ^ 1, cnt - 1), go(tt + 1, tree, cnt)) + (tree == b[tt] - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill(&dp[0][0][0], &dp[0][0][0] + 1004 * 2 * 34, -1);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << max(go(0, 0, m), go(0, 1, m - 1)) << endl;

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// #include <iostream>
// #include <vector>
// #include <algorithm>

// #define endl "\n"
// using namespace std;

// int dp[1004][2][34], n, m, b[1004];
// int go(int idx, int tree, int cnt)
// {
//     if (cnt < 0)
//         return -1e9;
//     if (idx == n)
//         return cnt == 0 ? 0 : -1e9;
//     int &ret = dp[idx][tree][cnt];
//     if (~ret)
//         return ret;
//     return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     fill(&dp[0][0][0], &dp[0][0][0] + 1004 * 2 * 34, -1);
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> b[i];
//     }
//     cout << max(go(0, 1, m - 1), go(0, 0, m)) << endl;

//     return 0;
// }