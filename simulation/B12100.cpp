#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;
int ret, n;
struct Board
{
    int a[24][24];
    void _rotate90()
    {
        int temp[24][24];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[i][j] = a[n - j - 1][i];
            }
        }
        memcpy(a, temp, sizeof(a));
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}