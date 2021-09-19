#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, b[404], c[22][22], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, ans, pw[5] = {0, 1, 10, 100, 1000};
set<int> s[404];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n * n; i++)
    {
        cin >> b[i];
        for (int j = 1; j <= 4; j++)
        {
            int a;
            cin >> a;
            s[b[i]].insert(a);
        }
    }

    for (int i = 0; i <= n + 1; i++)
        c[0][i] = c[n + 1][i] = c[i][0] = c[i][n + 1] = -1;

    for (int i = 1; i <= n * n; i++)
    {
        tuple<int, int, int, int> mx = {-1, 0, 0, 0};

        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= n; y++)
                if (!c[x][y])
                {
                    int c1 = 0, c2 = 0;
                    for (int d = 0; d < 4; d++)
                    {
                        int k = c[x + dx[d]][y + dy[d]];
                        if (s[b[i]].count(k))
                            c1++;
                        else if (k == 0)
                            c2++;
                    }
                    mx = max(mx, {c1, c2, -x, -y});
                }
        }

        auto [c1, c2, x, y] = mx;
        x = -x, y = -y;

        c[x][y] = b[i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int c1 = 0;
            for (int d = 0; d < 4; d++)
                if (s[c[i][j]].count(c[i + dx[d]][j + dy[d]]))
                    c1++;
            ans += pw[c1];
        }

    cout << ans;
}
// #include <iostream> 긴소스 코드
// #include <vector>
// #include <algorithm>

// #define MAX 25
// using namespace std;

// struct STUDENT
// {
//     int Num;
//     int Friend[4];
// };

// struct POSITION
// {
//     int x;
//     int y;
//     int Nearly_Empty;
//     int Nearly_Friend;
// };

// int N, Answer;
// int MAP[MAX][MAX];
// STUDENT Student_Arr[MAX * MAX];
// vector<STUDENT> Student;

// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};

// void Input()
// {
//     cin >> N;
//     for (int i = 0; i < N * N; i++)
//     {
//         int a, b, c, d, e;
//         cin >> a >> b >> c >> d >> e;
//         Student.push_back({a, {b, c, d, e}});
//         Student_Arr[a].Num = a;
//         Student_Arr[a].Friend[0] = b;
//         Student_Arr[a].Friend[1] = c;
//         Student_Arr[a].Friend[2] = d;
//         Student_Arr[a].Friend[3] = e;
//     }
// }

// bool Cmp(POSITION A, POSITION B)
// {
//     if (A.Nearly_Friend >= B.Nearly_Friend)
//     {
//         if (A.Nearly_Friend == B.Nearly_Friend)
//         {
//             if (A.Nearly_Empty >= B.Nearly_Empty)
//             {
//                 if (A.Nearly_Empty == B.Nearly_Empty)
//                 {
//                     if (A.x <= B.x)
//                     {
//                         if (A.x == B.x)
//                         {
//                             if (A.y < B.y)
//                             {
//                                 return true;
//                             }
//                             return false;
//                         }
//                         return true;
//                     }
//                     return false;
//                 }
//                 return true;
//             }
//             return false;
//         }
//         return true;
//     }
//     return false;
// }

// void Set_Position()
// {
//     for (int i = 0; i < Student.size(); i++)
//     {
//         vector<POSITION> Pos;
//         int Student_Num = Student[i].Num;
//         for (int x = 0; x < N; x++)
//         {
//             for (int y = 0; y < N; y++)
//             {
//                 if (MAP[x][y] != 0)
//                     continue;

//                 int Nearly_Friend = 0;
//                 int Nearly_Empty = 0;
//                 for (int k = 0; k < 4; k++)
//                 {
//                     int nx = x + dx[k];
//                     int ny = y + dy[k];
//                     if (nx < 0 || ny < 0 || nx >= N || ny >= N)
//                         continue;
//                     if (MAP[nx][ny] == 0)
//                         Nearly_Empty++;
//                     else
//                     {
//                         for (int j = 0; j < 4; j++)
//                         {
//                             int Friend_Num = Student[i].Friend[j];
//                             if (MAP[nx][ny] == Friend_Num)
//                             {
//                                 Nearly_Friend++;
//                                 break;
//                             }
//                         }
//                     }
//                 }
//                 Pos.push_back({x, y, Nearly_Empty, Nearly_Friend});
//             }
//         }
//         sort(Pos.begin(), Pos.end(), Cmp);
//         int Pos_x = Pos[0].x;
//         int Pos_y = Pos[0].y;
//         MAP[Pos_x][Pos_y] = Student_Num;
//     }
// }

// int Calculate(int F)
// {
//     if (F == 0)
//         return 0;
//     if (F == 1)
//         return 1;
//     if (F == 2)
//         return 10;
//     if (F == 3)
//         return 100;
//     if (F == 4)
//         return 1000;
// }

// void Calculate_Satisfy()
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             int Student_Num = MAP[i][j];
//             int Friend = 0;
//             for (int k = 0; k < 4; k++)
//             {
//                 int nx = i + dx[k];
//                 int ny = j + dy[k];
//                 if (nx < 0 || ny < 0 || nx >= N || ny >= N)
//                     continue;

//                 for (int l = 0; l < 4; l++)
//                 {
//                     int Friend_Num = Student_Arr[Student_Num].Friend[l];
//                     if (MAP[nx][ny] == Friend_Num)
//                     {
//                         Friend++;
//                         break;
//                     }
//                 }
//             }
//             Answer += Calculate(Friend);
//         }
//     }
// }

// void Solution()
// {
//     Set_Position();
//     Calculate_Satisfy();
//     cout << Answer << endl;
// }

// void Solve()
// {
//     Input();
//     Solution();
// }

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     //    freopen("Input.txt", "r", stdin);
//     Solve();

//     return 0;
// }
