#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
int A, B, C, a, b, ans, cnt[100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B >> C;
    for (int i = 0; i < 3; i++)
    {
        cin >> a >> b;
        for (int j = a; j < b; j++)
            cnt[j]++;
    }

    for (int i = 0; i < 100; i++)
    {
        if (cnt[i])
        {
            if (cnt[i] == 1)
                ans += A;
            else if (cnt[i] == 2)
                ans += B * 2;
            else
                ans += C * 3;
        }
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n";

// int a, b, c, ans;
// vector<int> v(101, 0);

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> a >> b >> c;
//     int s = 0, e = 0, mini = 101, maxi = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         cin >> s >> e;
//         if (s < mini)
//             mini = s;
//         if (e > maxi)
//             maxi = e;
//         for (int j = s; j < e; j++)
//         {
//             v[j]++;
//         }
//     }
//     for (int i = mini; i <= maxi; i++)
//     {
//         switch (v[i])
//         {
//         case 1:
//             ans += a;
//             break;
//         case 2:
//             ans += b * 2;
//             break;
//         case 3:
//             ans += c * 3;
//             break;
//             // default:
//             //     break;
//         }
//     }
//     cout << ans;
//     return 0;
// }