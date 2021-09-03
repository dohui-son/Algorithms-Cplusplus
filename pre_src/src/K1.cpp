
#include <iostream>
#include <bits/stdc++.h>
#include <string>

#define endl "\n";

using namespace std;

string ans;

string to_num(int idx, string& str){
    if(idx <= str.size()){
    if(str[idx] < 58) {
        if(idx <str.size()){
            return str[idx] + to_num(idx+1,str);}
        }else{ return str[idx]; }
    else{
        string ret ="";
        int next=idx;
        if(str[idx] == 'z'){
            ret = '0';
            next +=4;
        }
        else if(str[idx] == 'o')
        {
            ret = '1';
            next +=3;

        }
        else if(str[idx] == 't')
         {
            if(str[idx+1] == 'w'){
                ret = '2';
                next +=3;
            }else{
                ret = '3';
                next +=5;
            }
        }
        else if(str[idx] == 'f')
         {
            if(str[idx+1] == 'o'){
                ret = '4';
                next +=4;
            }else{
                ret = '5';
                next +=4;
            }
        }
        else if(str[idx] == 's')
         {
            if(str[idx+1] == 'i'){
                ret = '6';
                next +=3;
            }else{
                ret = '7';
                next +=5;
            }
        }
        else if(str[idx] == 'e')
         {
            ret = '8';
            next +=5;
        }
        else if(str[idx] == 'n')
         {
            ret = '9';
            next +=4;
        }
        if(next >= str.size())return ret;
        
        return ret + to_num(next, str);
    }
    }
}


int solution(string s) {
    int answer = 0;
    for(int i= 0; i< s.size(); i++){ if(58 < s[i])s[i] =tolower(s[i]); }
     
     


    return stoi( to_num (0,s));
    


    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    
    string N;
    cin >> N;
    cout << solution(N);

    return 0;
}