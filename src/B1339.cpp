#include <bits/stdc++.h>
using namespace std;

int64_t ans, n, arr[27];
vector<long long> v;
string str;
int value = 9;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> n;
    // 글자를 개수 생각해서 저장
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
    // 각 글자수를 sort
    for (int i = 0; i < 27; ++i)
        if (arr[i] != 0)
            v.push_back(arr[i]);
    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans += v[i] * value;
        value--;
    }
    cout << ans << '\n';

    return 0;
}