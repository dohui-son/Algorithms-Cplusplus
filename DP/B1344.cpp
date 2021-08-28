#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
const int n = 18;

bool isP[20] = {
    1,
};
double a, b, dp[20][20][20];

void eratostenes()
{
    fill(isP, isP + 20, 1);
    isP[0] = 0;
    isP[1] = 0;
    for (int i = 2; i <= 20; i++)
    {
        for (int j = i + i; j <= 20; j += i)
        {
            isP[j] = 0;
        }
    }
}

double go(int idx, int x, int y)
{
    if (idx == n)
        return isP[x] || isP[y] ? 1.0 : 0.0;
    double &ret = dp[idx][x][y];
    if (ret >= 0)
        return ret;
    ret = 0.0;
    ret += go(idx + 1, x + 1, y) * a * (1 - b);
    ret += go(idx + 1, x, y + 1) * (1 - a) * b;
    ret += go(idx + 1, x, y) * (1 - a) * (1 - b);
    ret += go(idx + 1, x + 1, y + 1) * a * b;
    return ret;
}
int main()
{
    scanf("%lf %lf", &a, &b);
    a /= 100;
    b /= 100;
    eratostenes();
    memset(dp, -1, sizeof(dp));
    printf("%.6lf", go(0, 0, 0));
    return 0;
}