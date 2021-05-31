#include<bits/stdc++.h>

using namespace std;
int n, s,f,ans=1;
vector<pair<int,int>>v;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> f;
        v.push_back({f,s});
    }
    sort(v.begin(), v.end());
    s = v[0].second;
    f = v[0].first;
    for (int i = 1; i < n; i++)
    {
        if(v[i].second < f)continue;
        ans++;
        s = v[i].second;
        f = v[i].first;
    }
    cout << ans;

    return 0;
}