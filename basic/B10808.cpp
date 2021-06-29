//알파벳 개수
#include <bits/stdc++.h>
#define endl "\n";
using namespace std;
map<char, int> m;
string str, abc = "abcdefghijklmnopqrstuvwxynz";
int ans[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> str;
    for (int i = 0; i < 26; i++)
    {
        m.insert(make_pair(str[i], 0));
    }
    for (int i = 0; i < str.size(); i++)
    {
        m[str[i]]++;
    }
    for (auto mm : m)
        cout << mm.second << " ";

    return 0;
}

//dohui's solution
// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n";

// string alpha = "abcdefghijklmnopqrstuvwxyz";
// vector<int> ans = vector<int>(26, 0);
// string str;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> str;
//     int idx = 0;
//     for (int i = 0; i < str.size(); i++)
//     {
//         idx = alpha.find(str[i]);
//         ans[idx]++;
//     }

//     for (int i = 0; i < 26; i++)
//         cout << ans[i] << " ";
//     return 0;
// }