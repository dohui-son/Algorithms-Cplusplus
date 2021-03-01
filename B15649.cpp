#include <iostream>
#include <vector>
#include <queue>

#define endl "\n";

using namespace std;
int N,M;
vector<vector<int>> ans;
vector<vector<int>> temp;


void find_seq(int n, int m){ // n까지 m개 
    // 1 <= M <= N <= 8
    queue<pair<int , int>> stack;
    

    for(int i = 0; i<N; i++){
        while(!stack.empty()){
           
        }


    }


}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    
    cin >> N>>M;
    
    find_seq(N,M);
    cout << ans;

    return 0;
}