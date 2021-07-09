#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int n, cnt[26];
string s, ret;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        cnt[s[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (cnt[i] >= 5)
            ret += i + 'a';
    if (ret.size())
    {
        cout << ret << endl;
    }
    else
    {
        cout << "PREDAJA" << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n";
// int N;
// map<char, int> m;
// string str;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> N;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> str;
//         if (m.find(str[0]) == m.end())
//             m.insert(make_pair(str[0], 1));
//         else
//             m[str[0]]++;
//     }

//     int flag = 1;
//     for (auto mm : m)
//     {
//         if (mm.second >= 5)
//         {
//             flag = 0;
//         }
//     }
//     if (flag){ cout << "PREDAJA" << endl; }
//     else{ for(auto mm : m){if(mm.second>=5)cout << mm.first;}}

//     return 0;
// }