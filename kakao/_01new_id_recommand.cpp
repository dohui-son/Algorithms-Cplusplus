#include <bits/stdc++.h>
using namespace std;
//숏코딩
string solution(string new_id)
{
    for (char &ch : new_id)
        if ('A' <= ch && ch <= 'Z')
            ch |= 32;
    string ret;
    for (char &ch : new_id)
    {
        if ('a' <= ch && ch <= 'z' ||
            '0' <= ch && ch <= '9' ||
            strchr("-_.", ch))
            ret += ch;
    }
    new_id = ret;
    ret.clear();
    for (char &ch : new_id)
    {
        if (!ret.empty() && ret.back() == '.' && ch == '.')
            continue;
        ret += ch;
    }
    if (ret.front() == '.')
        ret.erase(ret.begin());
    if (ret.back() == '.')
        ret.pop_back();
    if (ret.empty())
        ret = "a";
    if (ret.size() >= 16)
        ret = ret.substr(0, 15);
    if (ret.back() == '.')
        ret.pop_back();
    while (ret.size() <= 2)
        ret += ret.back();
    return ret;
}

// #include <bits/stdc++.h>나의 풀이

// using namespace std;

// string solution(string new_id) {
//     string answer = "";
//     string str = "";
//     for(int i = 0 ;i<new_id.size();i++){
//         char  now = new_id[i];

//         if( (str.empty() || i==new_id.size()-1 )&& now =='.')continue;
//         if(now>='a' && now<='z')str+=now;
//         else if(now >='A' &&now<='Z'){ str+=(char)((int)now+32); }
//         else if(now >='0' && now<='9'){str+=now;}
//         else if(now == '-' || now=='_'){str+=now;}
//         else if(now == '.'){
//             if(!str.empty() && str[str.size()-1]=='.')continue;
//             int idx = i+1, flag = 0;
//             while(idx<new_id.size()){
//                 if(new_id[idx] == '.'){i++; idx++;flag++;}
//                 break;
//             }
//             str+='.';
//         }
//     }
//     while(!str.empty() && str[str.size()-1]=='.'){str.pop_back();}
//     if(str.empty())str+='a';
//     while(str.size()>=15){
//         if(str.size() == 15 && str[14]!='.')break;
//         str.pop_back();

//     }
//     char last = str[str.size()-1];
//     while(str.size()<=2)str+=last;

//     return str;
// }