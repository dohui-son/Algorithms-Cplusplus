#include <bits/stdc++.h>
using namespace std;
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> str;
    bool yes = true;
    for (int i = 0; i < str.size(); i++)
    {
        if (i + 1 < str.size())
        {
            if (str[i] == 'p' && str[i + 1] == 'i')
            {
                i++;
                continue;
            }
            else if (str[i] == 'k' && str[i + 1] == 'a')
            {
                i++;
                continue;
            }
        }
        if (i + 2 < str.size())
        {
            if (str[i] == 'c' && str[i + 1] == 'h' && str[i + 2] == 'u')
            {
                i += 2;
                continue;
            }
        }
        yes = false;
        break;
    }
    if (yes)
        cout << "YES"
             << "\n";
    else
        cout << "NO"
             << "\n";

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// string s;
// bool flag = 0;
// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	cin >> s;
// 	for(int i = 0; i < s.size(); i++){
// 		if(i < s.size() - 1 && s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka") i += 1;
// 		else if(i < s.size() - 2 && s.substr(i, 3) == "chu") i += 2;
// 		else flag = 1;
// 	}
// 	if(flag) cout << "NO\n";
// 	else cout << "YES\n";
//     return 0;
// }