#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n";
int n, start, link;
int s[21][21];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }

    return 0;
}