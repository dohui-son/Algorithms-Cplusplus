#include<bits/stdc++.h>
//다시 한번 더 보기
using namespace std;

int n,d,p,ans;
vector<pair<int,int>> v;
priority_queue<int, vector<int>,greater<int>>pq;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i = 0 ; i<n; i++)
    {
        cin >> p >> d;
        v.push_back({d,p});
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)
    {
        pq.push(v[i].second);
        if(pq.size() > v[i].first)pq.pop();
    }

    while(pq.size()){
        ans+=pq.top(); pq.pop();
    }
    

    
    cout << ans;


    return 0;
    
} 