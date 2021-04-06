#include <iostream>
#include <vector>
#include <algorithm>
//#include "../print.hpp"

#define endl "\n";

using namespace std;

int p_num, n_num, hr;
vector<vector<int>> guest;
vector<int> ans;


void cal_financially(){
    
    for(int i = n_num-1; i>-1; i--){
        
        for(int j = 0 ; j<p_num ; j++){
            if(guest[i][1] != j)continue;
            if(ans[j]+guest[i][0] <= hr)ans[j]+=guest[i][0];

        }
    }


}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    
    
    cin >> p_num >> n_num >> hr;
    guest = vector<vector<int>>(n_num);
    int tmp1, tmp2;
    ans = vector<int>(p_num);
    for (int i = 0; i < n_num; i++)
    {
        cin >> tmp1 >> tmp2;
        //if(tmp2 > hr)continue;
        guest[i].push_back(tmp2);
        guest[i].push_back(tmp1-1);
    }
    sort(guest.begin(),guest.end());
   

    cal_financially();
    for(int i = 0; i<p_num;i++){
        cout << i+1 <<" " << ans[i]*1000 << endl;
    }

    return 0;
}