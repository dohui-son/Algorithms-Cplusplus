#include <bits/stdc++.h>
using namespace std;
//비트마스킹 31까지 가능함

typedef long long ll;
const int INF = 987654321;
int n, mp, mf, ms, mv;
int b,c,d,e,ret = INF, sum;
struct A{
    int mp,mf,ms,mv,cost;
}a[16]; //이부분 문법 질문

map<int, vector<vector<int>>> ret_v;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].mp >> a[i].mf >>a[i].ms >> a[i].mv >> a[i].cost;
    }
    for (int i = 1; i < (1 << n); i++) //모든경우의 수
    {
        b=c=d=e=sum=0;
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            if(i & (1 << j)){ // j번째 비트가 있는지 확인하기
                v.push_back(j+1);
                b+=a[j].mp;
                c+=a[j].mf;
                d+=a[j].ms;
                e+=a[j].mv;
                sum+=a[j].cost;
            }
        }
        if(b>= mp && c >= mf && d >= ms && e>= mv){
            if(ret >= sum){
                ret = sum;
                ret_v[ret].push_back(v);
            }
        }
    }
    if(ret == INF)cout << -1<<'\n';
    else{
        sort(ret_v[ret].begin(), ret_v[ret].end());
        cout << ret << "\n";
        for (int a : ret_v[ret][0])
        {
            cout << a << " ";
        }
    }
    
    


    return 0;
}