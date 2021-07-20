#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define endl "\n"

string input, bomb, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> input >> bomb;
    for (int i = 0; i < input.size(); i++)
    {
        ans += input[i];
        if (ans.size() >= bomb.size() && ans.substr(ans.size() - bomb.size(), bomb.size()) == bomb)
        {

            ans.erase(ans.end() - bomb.size(), ans.end());
        }
    }
    if (ans.size())
        cout << ans << endl;
    else
        cout << "FRULA" << endl;

    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;
// #define endl "\n";
// string input, bomb, res;
// std::string::size_type n;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> input >> bomb;

//     for (int i = 0; i < input.size(); i++)
//     {
//         res += input[i];
//         if (res.size() >= bomb.size() && res.substr(res.size() - bomb.size(), bomb.size()) == bomb)
//         {
//             res.erase(res.end() - bomb.size(), res.end());
//         }
//     }
//     if (res.size())
//         cout << res;
//     else
//         cout << "FRULA";

//     return 0;
// }