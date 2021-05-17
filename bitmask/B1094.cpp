#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

int x;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> x;
    int ans = 0;

    for (int i = 0; i < 7; i++)
    {
        if(x & (1 << i))ans++;
    }
    cout << ans;
    




    return 0;
}