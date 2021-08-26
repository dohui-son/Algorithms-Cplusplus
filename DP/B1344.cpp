#include<bits/stdc++.h>
using namespace std; 

//이번주에 풀었는 문제중 유사한 문제 많았음 꼭 다시 풀어보기
const int n = 18; 
bool isP[20]; 
double a, b, dp[20][20][20]; 
double go(int idx, int x, int y){
    if(idx == n) return isP[x] || isP[y] ? 1.0 : 0.0; 
    double &ret = dp[idx][x][y]; 
    if(ret > -0.5) return ret; 
    ret = 0.0; 
    ret += go(idx + 1, x + 1, y) * a * (1 - b); 
    ret += go(idx + 1, x + 1, y + 1) * a * b; 
    ret += go(idx + 1, x, y + 1) * (1 - a) * b; 
    ret += go(idx + 1, x, y) * (1 - a)* (1 - b); 
    return ret;  
} 
void era(){
    fill(isP, isP + 20, 1);
    isP[0] = 0; isP[1] = 0;  
    for(int i = 2; i <= 20; i++){ 
        for(int j = i + i; j <= 20; j += i){
            isP[j] = 0; 
        }
    }
}
int main(){ 
    scanf("%lf %lf", &a, &b); 
    a /= 100; b /= 100;  
    era();
    memset(dp, -1, sizeof(dp)); 
    printf("%.6lf", go(0, 0, 0));
}