#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

//카카오기출-외벽점검
//팁 : make the circle linear
vector<int> changeStartIdx(vector<int> weak, int start, int n){
    if(start ==0)return weak;
    vector<int> _ret;
    for (int i = start; i < weak.size(); i++)_ret.push_back(weak[i]);
    for (int i = 0; i < start; i++)_ret.push_back(weak[i]+n);
    return _ret;
}
int solution(int n, vector<int>weak,vector<int>dist){
    int ret = INF;
    sort(dist.begin(), dist.end());
    do{
        for (int j = 0; j < weak.size(); j++)
        {
            vector<int>_weak = changeStartIdx
        }
        
    }
}