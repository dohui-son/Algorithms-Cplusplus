#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include "../print.hpp"

#define endl "\n";

using namespace std;


string k_str;
int N;
vector<vector<char>>skills;
string ans;


void skill_connection(){
    for(int i = 0; i< N; i++)
    {
        int visited = 0;
        for(int j = 0; j < N;j++){

            if(skills[i][1] == skills[j][0]){
                ans = ans + skills[i][0] +" " + skills[i][1]+" "+skills[j][1] + "\n";
                visited = 1;
                
                
            }
        }
        if(visited == 0){
            for(int j = 0; j < skills[i].size();j++){
                if(skills[i][0] == skills[j][1])visited=1;
            }
            if(visited == 0)ans = ans + skills[i][0] +" "+ skills[i][1]+"\n";
        

        

        }

        
    }
}



int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);




    getline(cin, k_str);
    cin >> N;
    
    skills = vector<vector<char>>(N);
    char input1, input2;
    for (int i = 0; i < N; i++) {
        cin >> input1 >> input2;
        skills[i].push_back(input1);
        skills[i].push_back(input2);
        
    }
    skill_connection();
    cout << ans;

    return 0;
}