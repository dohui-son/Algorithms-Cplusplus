#include <iostream>


using namespace std;
#define endl "\n"
#define MAX 9

int n,m;
int v[MAX] = {0,};
int check[MAX] = {0,};



void dfs(int num, int cnt){
    if(cnt == m){
        for(int i = 0; i<m ; i++){
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    else{
        for(int i = num ; i<=n ; i++){
            if(!check[i]){
                check[i] = 1;
                v[cnt] = i;
                dfs(i+1, cnt+1);
                check[i] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m;

    dfs(1,0);
    return 0;
}