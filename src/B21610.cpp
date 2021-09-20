#include <iostream> //숏코딩
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, A[50][50], d, s, pcnt = 4;
    int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    bool chk[50][50] = {
        0,
    };
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];
    pii points[2500];
    points[0] = {N - 1, 0};
    points[1] = {N - 1, 1};
    points[2] = {N - 2, 0};
    points[3] = {N - 2, 1};
    while (M--)
    {
        cin >> d >> s;
        --d;
        for (int i = 0; i < pcnt; ++i)
        {
            int r = points[i].first, c = points[i].second;
            r = (r + s * dr[d]) % N;
            c = (c + s * dc[d]) % N;
            if (r < 0)
                r += N;
            if (c < 0)
                c += N;
            points[i] = {r, c};
            chk[r][c] = 1;
            A[r][c]++;
        }
        for (int i = 0; i < pcnt; ++i)
        {
            int r = points[i].first, c = points[i].second;
            for (int j = 1; j < 8; j += 2)
            {
                int nr = r + dr[j], nc = c + dc[j];
                if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                    continue;
                if (A[nr][nc])
                {
                    A[r][c]++;
                }
            }
        }
        pcnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (chk[i][j])
                {
                    chk[i][j] = 0;
                }
                else if (A[i][j] >= 2)
                {
                    points[pcnt++] = {i, j};
                    A[i][j] -= 2;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ans += A[i][j];
    cout << ans << "\n";
    return 0;
}

// #include <bits/stdc++.h> //맞음 내 답
// using namespace std;
// int n, m, a[53][53];
// pair<int, int> mm[102]; // d,s
// int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
// int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
// int cy[5], cx[5];
// int fy[] = {-1, 1, -1, 1};
// int fx[] = {-1, -1, 1, 1};

// bool v[54][54];
// set<pair<int, int> > se;
// int ans = 0;

// void c_move_rain(int idx)
// {

//     vector<pair<int, int> > moolboksa;
//     int d = mm[idx].first;
//     int s = mm[idx].second;

//     for (auto ss : se)
//     {
//         int ny = (dy[d] * s) % n + ss.first;
//         int nx = (dx[d] * s) % n + ss.second;

//         if (ny < 0)
//             ny += n;
//         else if (ny >= n)
//             ny -= n;
//         if (nx < 0)
//             nx += n;
//         else if (nx >= n)
//             nx -= n;

//         v[ny][nx] = 1;
//         a[ny][nx]++;
//         moolboksa.push_back({ny, nx}); // se.erase({x,y})하면 segmentation fault가 뜬다.
//     }
//     se.clear();

//     for (int i = 0; i < moolboksa.size(); i++)
//     {
//         int y = moolboksa[i].first, x = moolboksa[i].second;
//         for (int i = 0; i < 4; i++)
//         {
//             int ny = y + fy[i];
//             int nx = x + fx[i];
//             if (ny < 0 || nx < 0 || ny >= n || nx >= n)
//                 continue;
//             if (a[ny][nx] > 0)
//                 a[y][x]++;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (a[i][j] >= 2 && v[i][j] == 0)
//             {
//                 se.insert({i, j});
//                 a[i][j] -= 2;
//             }
//             ans += a[i][j];
//         }
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
//         for (int j = 0; j < n; j++)
//         {
//             cin >> a[i][j];
//         }
//     }

//     int d = 0, s = 0;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> d >> s;
//         d--;
//         mm[i] = {d, s};
//     }
//     cy[0] = n - 1;
//     cy[1] = n - 1;
//     cy[2] = n - 2;
//     cy[3] = n - 2;
//     cx[0] = 0;
//     cx[1] = 1;
//     cx[2] = 0;
//     cx[3] = 1;
//     for (int i = 0; i < 4; i++)
//     {
//         se.insert({cy[i], cx[i]});
//     }

//     for (int i = 0; i < m; i++)
//     {
//         ans = 0;
//         c_move_rain(i);
//         memset(v, 0, sizeof(v));
//     }
//     cout << ans << '\n';

//     return 0;
// }