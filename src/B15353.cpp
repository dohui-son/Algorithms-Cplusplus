#include <bits/stdc++.h>
using namespace std;
string a, b, ans;
int go(string aa, string bb, int plusone)
{
    if (aa.empty() && bb.empty())
    {
        if (plusone)
            ans.push_back('1');
        return 0;
    }
    if (aa.empty())
    {
        ans.push_back(bb[bb.size() - 1]);
        bb.pop_back();
        return go(aa, bb, 0);
    }
    if (bb.empty())
    {
        ans.push_back(aa[aa.size() - 1]);
        aa.pop_back();
        return go(aa, bb, 0);
    }
    int c = aa[aa.size() - 1] - '0' + bb[bb.size() - 1] - '0' + plusone;
    aa.pop_back();
    bb.pop_back();

    if (c <= 9)
    {
        ans.push_back(c + '0');
        return go(aa, bb, 0);
    }
    else
    {
        c -= 10;
        ans.push_back(c + '0');
        return go(aa, bb, 1);
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b;
    go(a, b, 0);
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}