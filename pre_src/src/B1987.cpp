#include <bits/stdc++.h>

using namespace std;
#define endl "\n";
int r,c;
vector<vector<char>>g(21,vector<char>(21));
//타블렛에 쓰면 자동으로 insert되도록-->어려움


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> r >> c;
    string str;
    for (int i = 0; i < r; i++)
    {
        cin >> str;
        for (int j = 0; j < c; j++)
        {
            g[i][j] = str[j];
        }
    }
    //아스키코드 
    






    return 0;
}