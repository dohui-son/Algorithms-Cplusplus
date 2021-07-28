#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int n, xx, yy, dd, gg, ans;
int visited[101][101], g[101][101];
struct Input
{
    int y, x, d, g;
};
vector<Input> input;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dragon(int y, int x, int d, int g)
{
    vector<int> dir;
    dir.push_back(d);
    int ly = y, lx = x;
    for (int j = 0; j < g; j++)
    {
        int pre = dir.size() - 1;
        for (int i = pre; i >= 0; i--)
        {
            dir.push_back((dir[i] + 3) % 4);
        }
    }
    for (int i = 0; i < dir.size(); i++)
    {
        int ny = ly + dy[dir[i]];
        int nx = lx + dx[dir[i]];
        visited[ny][nx] = 1;
        ly = ny;
        lx = nx;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> xx >> yy >> dd >> gg;
        visited[yy][xx] = 1;
        if (dd == 0)
            dd = 1;
        else if (dd == 1)
            dd = 0;
        else if (dd == 2)
            dd = 3;
        else if (dd == 3)
            dd = 2;
        input.push_back({yy, xx, dd, gg});
    }
    for (int i = 0; i < n; i++)
    {
        dragon(input[i].y, input[i].x, input[i].d, input[i].g);
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1])
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}

/////////////////////////////////////////////////
// #include <bits/stdc++.h>
// using namespace std;
// //0 1 2 4 8
// //0 / 1 / 2 1 / 2 3 2 1 /
// const int dy[] = {0, -1, 0, 1};
// const int dx[] = {1, 0, -1, 0};
// vector<int> dragon[4][11];
// int cnt, n, x, y, d, g, a[101][101];
// void go(int x, int y, int d, int g)
// {
//     int _x = x;
//     int _y = y;
//     a[_x][_y] = 1;
//     for (int i = 0; i <= g; i++)
//     {
//         for (int dir : dragon[d][i])
//         {
//             _x += dx[dir];
//             _y += dy[dir];
//             a[_x][_y] = 1;
//         }
//     }
//     return;
// }
// void makeDragon()
// {
//     for (int i = 0; i < 4; i++)
//     {
//         dragon[i][0].push_back(i);
//         dragon[i][1].push_back((i + 1) % 4);
//         for (int j = 2; j <= 10; j++)
//         {
//             int _n = dragon[i][j - 1].size();
//             for (int k = _n - 1; k >= 0; k--)
//             {
//                 dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
//             }
//             for (int k = 0; k < _n; k++)
//             {
//                 dragon[i][j].push_back(dragon[i][j - 1][k]);
//             }
//         }
//     }
//     return;
// }
// int main()
// {
//     cin >> n;
//     makeDragon();
//     for (int i = 0; i < n; i++)
//     {
//         cin >> x >> y >> d >> g;
//         go(x, y, d, g);
//     }
//     for (int i = 0; i <= 100; i++)
//     {
//         for (int j = 0; j <= 100; j++)
//         {
//             if (a[i][j] && a[i + 1][j] && a[i + 1][j + 1] && a[i][j + 1])
//                 cnt++;
//         }
//     }
//     cout << cnt << "\n";
//     return 0;
// }
/////////////////////////////////////////////////////////////
// #include<iostream> ////도희 코드 --성공
// #include<vector>
// #include<deque>
// using namespace std;
// #define endl "\n";

// int N, ans = 0;
// vector<vector<bool>> visit(102, vector<bool>(102, false));
// int yy[4] = { 0,-1,0,1 };
// int xx[4] = { 1,0,-1,0 };

// void square_chk(int yy) {
// 	for (int i = 0; i < 102; i++)
// 	{
// 		if ((i + 1) >= 102 || (yy + 1) >= 102)continue;
// 		if (visit[yy][i] == true && visit[yy][i + 1] == true && visit[yy + 1][i] == true && visit[yy + 1][i + 1] == true)ans++;
// 	}
// }

// void dragon_curve(int x, int y, int d, int g) {
// 	deque<int>dq;
// 	for (int i = 0; i <= g; i++)
// 	{
// 		if (i == 0) {
// 			dq.push_back(d);
// 			int ny = y + yy[d];
// 			int nx = x + xx[d];
// 			if (ny >= 0 && nx >= 0 && ny < 102 && nx < 102) {
// 				visit[ny][nx] = true;
// 				y = ny;
// 				x = nx;
// 			}
// 		}
// 		else {
// 			int j = dq.size() - 1;//계산 0 /1 /2/ 2/ 3/ 3/ 3/3 이렇게 디큐에 들어가있음
// 			for (int k = j; k >= 0; k--) // 계산 필요
// 			{
// 				dq.push_back((dq[k] + 1) % 4);
// 				int ny = y + yy[(dq[k] + 1) % 4];
// 				int nx = x + xx[(dq[k] + 1) % 4];
// 				if (ny < 0 || nx < 0 || ny >= 102 || nx >= 102)continue;
// 				visit[ny][nx] = true;
// 				y = ny;
// 				x = nx;
// 			}
// 		}
// 	}
// }

// int main() {
// 	ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

// 	cin >> N;
// 	int tmpx, tmpy, tmpd, tmpg;
// 	for (int i = 0; i < N; i++)
// 	{
// 		cin >> tmpx >> tmpy >> tmpd >> tmpg;
// 		dragon_curve(tmpx, tmpy, tmpd, tmpg);
// 		visit[tmpy][tmpx] = true;
// 	}
// 	for (int i = 0; i < 102; i++) square_chk(i);
// 	cout << ans;
// 	return 0;
// }