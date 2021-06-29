

//dohui's solution

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