#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, l, g[101][101], ans;

int horizontal(int y, int x, int ll, int visited)
{ //가로 //
    if (x == n || y == n)
        return 1;
    if (ll)
    { //아직 경사로를 놓은 영역에서 벗어나지 못하고 있음, 무조건 경사로 놔야함
        if (g[y][x] == g[y][x - 1])
            horizontal(y, x + 1, ll - 1, visited | (1 << x));
        else
            return 0;
    }
    else
    { // 전에부터 경사로 아직 안 놨을때
        if (g[y][x] == g[y][x - 1])
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        //ans+=go(i,j);
        //horizontal(i,1,0,0);
        for (int j = 0; j < n; j++)
        {
            //ans+=go(i,j);
        }
    }
    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;
// int n,l,a[104][104],b[104][104], ret;

// void solve(int a[104][104]){
//     for (int i = 0; i < n; i++)
//     {
//         int cnt = 1;, j=0;
//         for (int j = 0; j < n-1; j++)
//         {
//             if(a[i][j] == a[i][j+1])cnt++;
//             else if(a[i][j]+1 == a[i][j+1] && cnt >=l) cnt=1;
//             else if(a[i][j]-1==a[i][j+1] && cnt >=0 ) cnt=-l+1;
//             else break;
//         }
//         if(j==n-1 && cnt>=0)ret++;
//     }return ;
// }

// int main(){
//     scanf("%d %d", &n, &l);
//     for (int i = 0; i < n; i++)
//     {
//         for(int j = 0; j<n; j++){
//             scanf("%d", & a[i][j]);
//             }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for(int j = 0; j<n; j++){
//             b[i][j] = a[j][i];
//             }
//     }
//     solve(a); solve(b);
//     printf("%d \n", ret);
//     return 0;
// }