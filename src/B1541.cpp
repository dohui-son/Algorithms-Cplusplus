#include <iostream>
#include <vector>
#include <string>

#define endl "\n";


using namespace std;
string input;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    
    cin >> input;
    int result = 0;
    bool minus=false;
    string temp;

    for (int i = 0; i < input.size(); i++)
    {
        if(input[i]!='-'&&input[i]!='+')temp+=input[i];
        else{//숫자가 아닌 부호를 만남
        
            int num = stoi(temp);
            temp =""; //str초기화방법
            if(minus){
                result-=num;

            }
            else{
                result+=num;
            }
            if(input[i]=='-'){
                minus = true;
            }
            
        }
        
    }
    int num = stoi(temp);
            temp =""; //str초기화방법
            if(minus){
                result-=num;

            }
            else{
                result+=num;
            }

    cout <<result;

    return 0;
}