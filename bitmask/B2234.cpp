#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {0, -1,0,1};
const int dx[4] = {-1,0,1,0};
int n , m, cnt, widest,two, memo[2504], vis[51][51],g[51][51];


int dfs(int y, int x, int num){
    if(vis[y][x])return 0;
    vis[y][x] = num;
    int ret = 1;
    for (int i = 0; i < 4; i++)
    {

        if(!(g[y][x] & 1<<i) ){
            int ny = dy[i]+y;
            int nx = dx[i]+x;
            
            ret +=dfs(ny,nx,num);
            
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(vis[i][j] == 0){
                cnt++;
                memo[cnt] = dfs(i,j,cnt);
                widest = max(widest, memo[cnt]);
               
            }
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i+1<m){
                int a = vis[i+1][j];
                int b = vis[i][j];
                if(a!=b)two=max(two,memo[a]+memo[b]);
            }
            if(j+1<n){
                int a = vis[i][j+1];
                int b = vis[i][j];
                if(a!=b)two=max(two,memo[a]+memo[b]);
            }
        }
    }
    
    cout << cnt <<"\n" << widest<< "\n" << two <<endl;
    


    return 0;
}