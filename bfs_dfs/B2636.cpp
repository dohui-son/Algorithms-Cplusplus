#include <bits/stdc++.h>

using namespace std;
#define endl "\n";

int r,c,rest,t;
vector<vector<int>> g;
int dy[4] = { -1,0,1,0};
int dx[4] = {0,-1,0,1};


void BFS(){
    int now = 0;
    while(rest - now > 0){
        t++;
        rest -= now;
        now = 0;
        vector<vector<bool>> visit = vector<vector<bool>>(r,vector<bool>(c,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        visit[0][0] = true;
        while (!q.empty())
        {
            pair<int,int> turn = q.front(); q.pop();
            for (int i = 0; i < 4; i++)
            {
                int ny = dy[i] + turn.first;
                int nx = dx[i] + turn.second;
                if(ny<0 || nx<0 || ny>=r || nx>= c)continue;
                if(!visit[ny][nx] && g[ny][nx]==1){
                    visit[ny][nx] = true;
                    g[ny][nx]=0;
                    now++;
                }
                if(!visit[ny][nx] && g[ny][nx] == 0){
                    q.push({ny,nx});
                    visit[ny][nx] = true;
                }
            }
            
        }
        
        
    }
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> r >>c;
    g = vector<vector<int>>(r,vector<int>(c,0));
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >>g[i][j];
            if(g[i][j])rest++;
        }
    }

    BFS();
    cout << t << endl 
    cout << rest<<endl;
    


    return 0;
}