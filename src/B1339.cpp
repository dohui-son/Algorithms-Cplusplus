#include <bits/stdc++.h>
using namespace std;

int64_t ans, n, arr[27];
vector<int64_t> v;
string str;
int val = 9;
//ABC + BCD 인 경우는 A 100개, B 10+100개, C 1+10개, D 1개 있는 것
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        int cnt = 1;
        for (int j = str.size() - 1; j >= 0; j--)
        {
            arr[str[j] - 'A'] += cnt;
            cnt *= 10;
        }
    }
    for (int i = 0; i < 27; ++i)
        if (arr[i] != 0) v.push_back(arr[i]);
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans += v[i] * val;
        val--;
    }
    cout << ans << '\n';
    return 0;
}