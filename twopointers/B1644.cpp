#include <bits/stdc++.h>
//************
using namespace std;
#define endl "\n";
bool nat[4000001];
int n,prime[2000001],p,low,high,ret,sum;

int main(){
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if(nat[i])continue;
        for (int j = 2*i; j <=n; j+=i)nat[j]=1;
        
    }
    for (int i = 2; i <= n; i++){ if(!nat[i])prime[p++]=i; }
    while(1){
        if(sum>=n)sum-=prime[low++];
        else if(high == p)break;
        else sum+=prime[high++];
        if(sum == n)ret++;
    }
    
    printf("%d",ret);
    
    return 0;
}