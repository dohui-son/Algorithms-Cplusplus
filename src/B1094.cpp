#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
int x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 0; i < 7; i++)
        if (x & (1 << i))
            ans++;
    cout << ans;
    return 0;
}

//다른 풀이
#include <bits/stdc++.h>
using namespace std;
int x, ret = 1;
int main()
{
    cin >> x;
    while (x != 1)
    {
        if (x & 1)
            ret++;
        x /= 2;
    }
    cout << ret << '\n';
    return 0;
}