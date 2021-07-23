#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl "\n"
int n, ans;
struct Board
{
    int a[24][24];
    void _rotate90()
    {
        int tmp[24][24] = {{
            0,
        }};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp[i][j] = a[n - j - 1][i];
            }
        }
        memcpy(a, tmp, sizeof(a));
    }

    void _move()
    {
        int tmp[24][24];
        for (int i = 0; i < n; i++)
        {
            int idx = -1, flag = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 0)
                    continue;
                if (a[i][j] == tmp[i][idx] && flag)
                    tmp[i][idx] *= 2, flag = 0;
                else
                    tmp[i][++idx] = a[i][j], flag = 1;
            }
            for (idx++; idx < n; idx++)
                tmp[i][idx] = 0;
        }
        memcpy(a, tmp, sizeof(a));
    }
    void maxim()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, a[i][j]);
            }
        }
    }
};

void BT(Board b, int here)
{
    if (here == 5)
    {
        b.maxim();
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        Board c = b;
        c._move();
        BT(c, here + 1);
        b._rotate90();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Board b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b.a[i][j];
        }
    }

    BT(b, 0);
    cout << ans << endl;
    return 0;
}