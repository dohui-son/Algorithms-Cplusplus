#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
using namespace std;
#define endl "\n";
string s, temp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    temp = s;

    reverse(temp.begin(), temp.end());
    if (temp == s)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n";
// string str;
// char a, b;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> str;
//     int j = str.size() - 1;
//     for (int i = 0; i < str.size() / 2; i++)
//     {
//         a = str[i];
//         b = str[j];
//         if (a != b)
//         {
//             cout << 0 << endl;
//             exit(0);
//         }
//         j--;
//     }
//     cout << 1 << endl;

//     return 0;
// }