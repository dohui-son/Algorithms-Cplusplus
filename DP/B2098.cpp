#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"
#define MAX_N 16
const int INF = 987654321;

int n, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];
int go(int here, int visited)
{
    if (visited == (1 << n) - 1) return dist[here][0] ? dist[here][0] : INF;
    int &ret = dp[here][visited];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i < n; i++)
    {
        if (visited & (1 << i)) continue;
        if (dist[here][i] == 0) continue;
        ret = min(ret, go(i, visited | (1 << i)) + dist[here][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    fill(&dp[0][0], &dp[0][0] + MAX_N * MAX_N, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }
    cout << go(0, 1) << endl;
    return 0;
}