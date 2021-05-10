#include <bits/stdc++.h>

using namespace std;
#define endl "\n";

int r,c,ret,ny,nx;
char a[21][21];

const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};

void go(int y,int x, int num, int cnt){
    ret = max(ret,cnt);
    for (int i = 0; i < 4; i++)
    {
        ny = y+dy[i], nx = x+dx[i];
        if(ny <0 || nx <0 || ny >=r || nx>= c)continue ;
        int next = (1<< (int)(a[ny][nx]-'A'));
        if((num & next) == 0)go(ny, nx, num|next, cnt+1); // num이랑 next가 다른 수일때 두 경우의 수를 모두 합해서 넘겨줌
    }
    return ;
}



int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> r>>c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)cin >> a[i][j];
        
    }
    go(0,0,1<<(int)(a[0][0] - 'A'),1);
    cout << ret;
    return 0;
}