#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int r,c,ans;
char g[21][21];
int dy[] = {0,-1,0,1};
int dx[] = {-1,0,1,0};

void go(int y, int x, int cnt, int visited){
    ans = max(cnt,ans);
    for (int i = 0; i < 4; i++)
    {
        int ny = y+dy[i]; int nx = x+dx[i];
        if(ny<0|| nx<0 || ny>=r || nx>=c)continue;
        int next = (1<< (int)(g[ny][nx]-'A'));
        if((visited&next)==0)go(ny,nx,cnt+1,next|visited);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)cin >> g[i][j];
    }
    go(0,0,1,1<<(int)(g[0][0]-'A'));
    cout << ans << endl;
    return 0;
}


// #include <bits/stdc++.h>

// using namespace std;
// #define endl "\n";

// int r,c,ret,ny,nx;
// char a[21][21];

// const int dy[]={-1,0,1,0};
// const int dx[]={0,1,0,-1};

// void go(int y,int x, int num, int cnt){
//     ret = max(ret,cnt);
//     for (int i = 0; i < 4; i++)
//     {
//         ny = y+dy[i], nx = x+dx[i];
//         if(ny <0 || nx <0 || ny >=r || nx>= c)continue ;
//         int next = (1<< (int)(a[ny][nx]-'A'));
//         if((num & next) == 0)go(ny, nx, num|next, cnt+1); // num이랑 next가 다른 수일때 두 경우의 수를 모두 합해서 넘겨줌
//     }
//     return ;
// }



// int main(){
//     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

//     cin >> r>>c;
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)cin >> a[i][j];
        
//     }
//     go(0,0,1<<(int)(a[0][0] - 'A'),1);
//     cout << ret;
//     return 0;
// }