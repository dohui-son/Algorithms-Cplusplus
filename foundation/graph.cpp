#include <bits/stdc++.h>
using namespace std;
int V; //vertex

//인접행렬  O(V^2)
bool a[1004][1004];
void f(){
    for(int i=0; i<V; i++){
        for(int j=0; j< V; j++){
            //i부터 j까지 갈 수 있는 간선있나
            if(a[i][j]){ //로직
            }
        }
    }
}

//인접리스트 O(V + E)
vector<int> adj[1004];
void f(int here){
    //1에서 2까지 갈 수 있다면
    adj[1].push_back(2);
    for(int i=0; i<V; i++){
        //i에서 there까지 갈 수 있다.
        for(int there: adj[i]){
            //로직
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}