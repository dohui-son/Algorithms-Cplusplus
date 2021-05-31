#include <bits/stdc++.h>
using namespace std;
//컵라면

int n,d,cn,ans;
vector<pair<int,int>>v;
priority_queue<int,vector<int>,greater<int>>pq;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> cn;
        v.push_back({d,cn});
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)
    {
        ans+=v[i].second;
        pq.push(v[i].second);
        if(pq.size() > v[i].first)
        {
            ans-=pq.top();
            pq.pop();
        }
    }
    cout << ans;

    return 0;
}