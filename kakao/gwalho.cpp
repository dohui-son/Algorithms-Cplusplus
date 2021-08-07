// #include <bits/stdc++.h>

// using namespace std;
// string ans;
// string input;

// bool chk(string a){ 
//     int cnt = 0; 
//     for(int i = 0; i < a.size(); i++){
//         if(a[i] == '(') cnt++; 
//         else cnt--; 
//         if(cnt < 0) return false; 
//     }
//     return cnt == 0;
// }





// string recur(string pp){
    
//     if(chk(pp))return pp;



    
//     string u,v;
//     int open=0,close=0;

//     if(pp[0]=='(')open++;
//     else close++;
//     u+=pp[0];

//     int i = 1;
//     while (i<pp.size())
//     {
//         if( open != close  )
//         {
//             if(pp[i]=='(')open++; 
//             else close++; 
//             u+=pp[i];
//         }
//         else v+=pp[i];
//         i++;
//     }
//     if(!chk(u)){
//         string ret = "";
//         ret+='(';
//         ret +=recur(v);
//         ret+=')';
//         for(int k = 1; k<u.size()-1; k++){
//             if(u[k]=='(')ret+=')';
//             else ret+='(';
//         }
//         return ret;
//     }
//     else return u+recur(v);    
// }

// string solution(string p) {
//     //올바른 문자열인지 검사후 올바른 문자열이면 리턴
//     return recur(p);
    
    
// }