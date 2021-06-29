#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

int h[9];
vector<int> v;

void go(int next)
{
    if (v.size() == 7)
    {
        int tmp = 0;
        for (int i = 0; i < 7; i++)
            tmp += v[i];
        if (tmp == 100)
        {
            sort(v.begin(), v.end());
            for (int i = 0; i < 7; i++)
                cout << v[i] << endl;
            exit(0);
        }
    }
    for (int i = next; i < 9; i++)
    {
        v.push_back(h[i]);
        go(next + 1);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (size_t i = 0; i < 9; i++)
        cin >> h[i];
    go(0);

    return 0;
}

//dohui's solution - success

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n";

// vector<int> v = vector<int>(9, 0);
// int s;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     for (int i = 0; i < 9; i++)
//     {
//         cin >> v[i];
//         s += v[i];
//     }
//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = i + 1; j < 9; j++)
//         {
//             s -= v[i];
//             s -= v[j];
//             if (s == 100)
//             {
//                 v[i] = 0;
//                 v[j] = 0;
//                 break;
//             }
//             s += v[i];
//             s += v[j];
//         }
//     }
//     sort(v.begin(), v.end());

//     for (int i = 2; i < 9; i++)
//     {
//         cout << v[i] << endl;
//     }

//     return 0;
// }