#include <bits/stdc++.h>
using namespace std;
int n, k, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (k >= n)
    {
        cout << "0"
             << "\n";
        return 0;
    }
    sort(v.begin(), v.end());
    vector<int> dis(n - 1);
    for (int i = 0; i < n - 1; i++)
        dis[i] = v[i + 1] - v[i];
    sort(dis.begin(), dis.end());
    for (int i = 0; i < n - k; i++)
        ans += dis[i];
    cout << ans << "\n";
    return 0;
}