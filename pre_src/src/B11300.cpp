#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n";

using namespace std;
int N;
vector<int> P;
vector<int> memo;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;
    P = vector<int>(N);
    memo = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    sort(P.begin(), P.end());
    int sum = P[0];
    memo[0]=P[0];
    for(int i = 1 ; i<N; i++){
        
        memo[i] = P[i] + memo[i-1];
        sum +=memo[i];

    }
    cout << sum;
    

    return 0;
}