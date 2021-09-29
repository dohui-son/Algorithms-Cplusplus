#include <cstdio>
#define rep(i, x, n) for (int i = (x); i < (n); i++)
#define repp(i, x, n) for (int i = (x); i <= (n); i++)
int a[9][9], y[5], x[5];
bool dfs(int d)
{
    if (d == 0)
    {
        rep(i, 0, 9)
        {
            int v[3][10] = {};
            rep(j, 0, 9)
            {
                v[0][a[i][j]]++;
                v[1][a[j][i]]++;
                v[2][a[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]]++;
            }
            rep(j, 0, 3) repp(k, 1, 9) if (v[j][k] != 1) return false;
        }
        return true;
    }
    d--;
    repp(k, 1, 9)
    {
        a[y[d]][x[d]] = k;
        if (dfs(d))
            return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int k = 0;
        rep(i, 0, 9) rep(j, 0, 9)
        {
            scanf("%1d", a[i] + j);
            if (a[i][j] == 0)
                y[k] = i, x[k] = j, k++;
        }
        if (dfs(k))
            rep(i, 0, 9)
            {
                rep(j, 0, 9) printf("%d", a[i][j]);
                putchar('\n');
            }
        else
        {
            puts("Could not complete this grid.");
        }
        putchar('\n');
    }
}