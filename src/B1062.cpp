#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m, words[51];
string s;
int count(int mask)
{
    int cnt = 0;
    for (int word : words)
        if (word && (word & mask) == word)
            cnt++;
    return cnt;
}

int go(int idx, int k, int mask)
{
    if (k < 0)
        return 0;
    if (idx == 26)
        return count(mask);
    int ret = go(idx + 1, k - 1, mask | (1 << idx));
    if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a')
    {
        ret = max(ret, go(idx + 1, k, mask));
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (char str : s)
            words[i] |= (1 << (str - 'a'));
    }
    cout << go(0, m, 0) << endl;

    return 0;
}