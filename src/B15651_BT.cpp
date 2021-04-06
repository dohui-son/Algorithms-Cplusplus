#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
int N, M;
vector<int> v;

void dfs(int cnt){
    if(cnt==M){
        for(int i = 0; i<M ; i++){
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    else{
        for(int i = 1; i<=N; i++){
            v[cnt] = i;
            dfs(cnt+1);
        }
    }
}



int main(){
    cin >> N >> M;
    v = vector<int>(N);
    
    dfs(0);

    return 0;
}