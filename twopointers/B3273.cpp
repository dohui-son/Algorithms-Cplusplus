////두수의 합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
int n, x, l, r, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> x;
    sort(v.begin(), v.end());
    r = n - 1;
    while (l < r)
    {
        if (v[l] + v[r] == x)
            ans++, r--;
        else if (v[l] + v[r] < x)
            l++;
        else
            r--;
    }
    cout << ans << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// #define endl "\n";
// int n, ans, x;

// int main()
// {
//     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }
//     cin >> x;
//     sort(v.begin(), v.end());
//     int l = 0, r = n - 1;
//     while (l < r)
//     {
//         if (v[l] + v[r] == x) ans++, r--;

//         else if (v[l] + v[r] < x) l++;
//         else r--;
//     }
//     cout << ans;

//     return 0;
// }
