#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"
const int INF = 987654321;

vector<int> startIdx(int start, vector<int> &w, int n)
{
    if (start == 0)
        return w;
    vector<int> ret;
    for (int i = start; i < w.size(); i++)
        ret.push_back(w[i]);
    for (int i = 0; i < start; i++)
        ret.push_back(w[i] + n);
    return ret;
}

int solution(int n, vector<int> weak, vector<int> dist)
{
    int ans = INF;
    sort(dist.begin(), dist.end());
    do
    {
        for (int i = 0; i < weak.size(); i++)
        {
            vector<int> _weak = startIdx(i, weak, n);
            int idx = 0, cur = _weak[0] + dist[0], flag = 0;
            for (int j = 1; j < _weak.size(); i++)
            {
                if (cur < _weak[j])
                {
                    if (idx + 1 == dist.size())
                    {
                        flag = 1;
                        break;
                    }
                    cur = _weak[j] + dist[++idx];
                }
            }
            if (!flag)
                ans = min(ans, idx + 1);
        }
    } while (next_permutation(dist.begin(), dist.end()));
    return (ans == INF ? -1 : ans);
}

// #include <bits/stdc++.h>
// using namespace std;
// const int INF = 987654321;

// //카카오기출-외벽점검
// //팁 : make the circle linear

// vector<int> changeStartIdx(vector<int>weak, int start, int n){
//     if(start == 0)return weak;
//     vector<int> _ret;
//     for(int i = start; i<weak.size(); i++)_ret.push_back(weak[i]);
//     for(int i = 0; i<start; i++)_ret.push_back(weak[i]+n);
//     return _ret;
// }

// int solution(int n, vector<int> weak, vector<int> dist){
//     int ret = INF;
//     sort(dist.begin(),dist.end());
//     do{
//         for (int j = 0; j < weak.size(); j++)
//         {
//             vector<int>_weak = changeStartIdx(weak,j,n);
//             int idx = 0;
//             int curr = _weak[0] + dist[0];
//             bool flag = 0;
//             for (int i = 1; i < _weak.size(); i++)
//             {
//                 if(_weak[i]>curr)
//                 {
//                      if(idx+1 == dist.size()){
//                         flag = 1;
//                         break;
//                     }
//                     curr = _weak[i]+dist[++idx];
//                 }
//             }
//             if(!flag)ret = min(ret, idx+1);
//         }
//     }while(next_permutation(dist.begin(),dist.end()));
//     return (ret==INF? -1:ret);
// }