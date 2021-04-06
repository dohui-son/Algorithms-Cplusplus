#include <iostream>
#include <algorithm>
#include <cstring>
//시간복잡도 : N^3
//점화식 : d[i][j] = d[i][k] + d[k+1][j] + sum[j] - sum[i-1]

using namespace std;
#define endl "\n";

int T, K;
int file[501];
int s[501];
int d[501][501];

int merge(int i, int j)
{
    if (i == j)
        return 0;
    int &ret = d[i][j];
    if (ret == -1)
    {
        for (int k = i; k <= j - 1; k++)
        {
            int temp = merge(i, k) + merge(k + 1, j) + s[j] - s[i - 1];
            if (ret == -1 || ret > temp)
            {
                ret = temp;
            }
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> K;
        memset(d, -1, sizeof(d));
        for (int t = 1; t <= K; t++)
        {
            cin >> file[t];
            s[t] = file[t] + s[t - 1];
        }
        cout << merge(1, K) << endl;
    }

    return 0;
}