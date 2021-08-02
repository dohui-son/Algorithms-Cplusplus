#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

#define endl "\n"
using namespace std;
map<int, int> m;
int a, b, ans;
int64_t tmp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        cin >> tmp;
        m[tmp]++;
    }
    for (int i = 0; i < b; i++)
    {
        cin >> tmp;
        m[tmp]++;
    }
    for (auto i : m)
        if (i.second == 1)
            ans++;
    cout << ans << endl;
    return 0;
}