#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

vector<int> v = vector<int>(9, 0);
int s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < 9; i++)
    {
        cin >> v[i];
        s += v[i];
    }
    for (int i = 0; i < 9; i++)
    {
        rotate(v.begin(), v.begin() + 1, v.end());
        s -= v[7];
        s -= v[8];
        cout << "s " << s << endl;
        if (s == 100)
            break;
        s += v[7];
        s += v[8];
    }
    v.pop_back();
    v.pop_back();
    sort(v.begin(), v.end());

    for (int i = 0; i < 7; i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}