





////////////////////////////////////
#include<iostream>
#include<vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}

/////////////////////////////////////////////
// ////B1912연속합
// #include<iostream>
// #include<vector>
// #include <algorithm>
// #define endl "\n"
// using namespace std;

// int n,sum,a,ret = -1001;
// int main(){
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &a);
//         sum += a;
//         ret = max(ret,sum);
//         if(sum < 0)sum =0;
//     }printf("%d\n",ret);
//     return 0;
// }


////////////////////////////////////////////////////////////////////
////B15684감시카메라
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #define endl "\n"
// using namespace std;
// int n, m, a[10][10], temp[10][10], ans = 987654321;
// vector<pair<int, int> > v;
// const int dy[] = {-1, 0, 1, 0};
// const int dx[] = {0, 1, 0, -1};

// vector<pair<int, int> > extendCCTV(int vdx, int dir)
// {
//     vector<pair<int, int> > ch;
//     int x = v[vdx].second;
//     int y = v[vdx].first;

//     switch (a[y][x])
//     {
//     case 1:
//         while (1)
//         {
//             int ny = y + dy[dir];
//             int nx = x + dx[dir];
//             if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6)
//             {
//                 if (a[ny][nx] == 0)
//                 {
//                     ch.push_back({ny, nx});
//                     a[ny][nx] = 8;
//                 }
//                 y = ny;
//                 x = nx;
//             }
//             else
//                 break;
//         }
//         break;
//     case 2:
//         for (int i = 0; i <= 2; i += 2)
//         {
//             int yy = y;
//             int xx = x;
//             while (1)
//             {
//                 int ny = yy + dy[(dir + i) % 4];
//                 int nx = xx + dx[(dir + i) % 4];
//                 if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6)
//                 {
//                     if (a[ny][nx] == 0)
//                     {
//                         ch.push_back({ny, nx});
//                         a[ny][nx] = 8;
//                     }
//                     yy = ny;
//                     xx = nx;
//                 }
//                 else
//                     break;
//             }
//         }
//         break;
//     case 3:
//         for (int i = 0; i < 2; i++)
//         {
//             int yy = y;
//             int xx = x;
//             while (1)
//             {
//                 int ny = yy + dy[(i + dir) % 4];
//                 int nx = xx + dx[(i + dir) % 4];
//                 if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6)
//                 {
//                     if (a[ny][nx] == 0)
//                     {
//                         ch.push_back({ny, nx});
//                         a[ny][nx] = 8;
//                     }
//                     yy = ny;
//                     xx = nx;
//                 }
//                 else
//                     break;
//             }
//         }

//         break;
//     case 4:
//         for (int i = 0; i < 3; i++)
//         {
//             int yy = y;
//             int xx = x;
//             while (1)
//             {
//                 int ny = yy + dy[(i + dir) % 4];
//                 int nx = xx + dx[(i + dir) % 4];
//                 if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6)
//                 {
//                     if (a[ny][nx] == 0)
//                     {
//                         ch.push_back({ny, nx});
//                         a[ny][nx] = 8;
//                     }
//                     yy = ny;
//                     xx = nx;
//                 }
//                 else
//                     break;
//             }
//         }

//         break;
//     case 5:
//         for (int i = 0; i < 4; i++)
//         {
//             int yy = y;
//             int xx = x;
//             while (1)
//             {
//                 int ny = yy + dy[(i + dir) % 4];
//                 int nx = xx + dx[(i + dir) % 4];
//                 if (ny >= 0 && nx >= 0 && ny < n && nx < m && a[ny][nx] != 6)
//                 {
//                     if (a[ny][nx] == 0)
//                     {
//                         ch.push_back({ny, nx});
//                         a[ny][nx] = 8;
//                     }
//                     yy = ny;
//                     xx = nx;
//                 }
//                 else
//                     break;
//             }
//         }
//         break;
//     }

//     return ch;
// }

// void dfs(int here)
// {
//     if (here == v.size())
//     {
//         int ret = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (a[i][j] == 0)
//                     ret++;
//             }
//         }
//         ans = min(ret, ans);
//         return;
//     }
//     for (int i = 0; i < 4; i++)
//     {
//         vector<pair<int, int> > change = extendCCTV(here, i);
//         dfs(here + 1);
//         for (auto cc : change)
//             a[cc.first][cc.second] = 0;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> a[i][j];
//             if (a[i][j] != 6 && a[i][j] != 0)
//                 v.push_back({i, j});
//         }
//     }
//     dfs(0);
//     cout << ans << endl;
//     return 0;
// }
