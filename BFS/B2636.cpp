#include <bits/stdc++.h>

using namespace std;
#define endl "\n";

int r,c,rest;
vector<vector<int>> g;
int d


void BFS(){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(!visit && !g[i][j]){
                for (int k = 0; k < 4; k++)
                {
                    /* code */
                }
                
            }
        }
        
    }
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> r >>c;
    g = vector<vecotr<int>>(r,vector<int>(c,0));
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >>g[i][j];
            if(g[i][j])rest++;
        }
    }

    BFS();
    cout << rest<<endl;
    


    return 0;
}