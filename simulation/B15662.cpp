#include <bits/stdc++.h> //// 출처 큰돌블로그
using namespace std;
typedef long long ll;
int n, k, a, b, ret;
string s[1004];
void rot(int pos, int dir)
{
    if (!dir)
        rotate(s[pos].begin(), s[pos].begin() + 1, s[pos].end());
    else
        rotate(s[pos].begin(), s[pos].begin() + s[pos].size() - 1, s[pos].end());
}
int findL(int pos)
{
    for (int i = pos; i >= 1; i--)
    {
        if (s[i][6] == s[i - 1][2])
        {
            return i;
        }
    }
    return 0;
}
int findR(int pos)
{
    for (int i = pos; i <= n - 2; i++)
    {
        if (s[i][2] == s[i + 1][6])
        {
            return i;
        }
    }
    return n - 1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        a--;
        b = (b == -1 ? 0 : 1);
        int l = findL(a);
        int r = findR(a);
        int cnt = 0;
        for (int pos = a; pos >= l; pos--)
        {
            rot(pos, cnt % 2 == 0 ? b : !b);
            cnt++;
        }
        cnt = 1;
        for (int pos = a + 1; pos <= r; pos++)
        {
            rot(pos, cnt % 2 == 0 ? b : !b);
            cnt++;
        }
    }
    for (int i = 0; i < n; i++)
        if (s[i][0] == '1')
            ret++;
    cout << ret << "\n";

    return 0;
}
////내가 작성한 정답
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;
// #define endl "\n"
// int t, k, ans;
// vector<vector<int> > gear;
// vector<int> gg(8), visited;
// vector<pair<int, int> > cmd;

// void rotate_g(int gdx, bool ns)
// {
//     visited[gdx] = 1;
//     if (gdx > 0)
//     { //왼쪽 확인
//         if (gear[gdx][6] != gear[gdx - 1][2] && !visited[gdx - 1])
//             rotate_g(gdx - 1, !ns);
//     }
//     if (gdx < t - 1)
//     {
//         //오른쪽 확인
//         if (gear[gdx][2] != gear[gdx + 1][6] && !visited[gdx + 1])
//             rotate_g(gdx + 1, !ns);
//     }
//     copy(&gear[gdx][0], &gear[gdx][0] + 8, &gg[0]);
//     if (ns)
//     { // 1 시계 방향

//         rotate(gg.begin(), gg.begin() + gg.size() - 1, gg.end());
//     }
//     else
//     { // 반시계방향
//         rotate(gg.begin(), gg.begin() + 1, gg.end());
//     }
//     for (int i = 0; i < 8; i++)
//     {
//         gear[gdx][i] = gg[i];
//     }
//     //gg를 gear[gdx][0]에서 gear[gdx][7]까지 복사해주기 --algorithm
//     copy(&gg[0], &gg[0] + 8, &gear[gdx][0]); // 복사할 대상 시작주소,복사할대상 끝주소, 복사되어야할 공간의 첫 주소
// }

// int main()
// {
//     scanf("%d", &t);
//     int tmp = 0, tmp2 = 0;
//     gear = vector<vector<int> >(t, vector<int>(8, 0));
//     visited = vector<int>(t, 0);
//     for (int i = 0; i < t; i++)
//     {
//         for (int j = 0; j < 8; j++)
//         {
//             scanf("%1d", &tmp);
//             gear[i][j] = tmp;
//         }
//     }

//     scanf("%d", &k);
//     for (int i = 0; i < k; i++)
//     {
//         scanf("%d %d", &tmp, &tmp2);
//         tmp--;
//         if (tmp2 == -1)
//             tmp2 = 0;
//         cmd.push_back({tmp, tmp2});
//     }

//     for (int i = 0; i < k; i++)
//     {
//         fill(visited.begin(), visited.end(), 0);
//         rotate_g(cmd[i].first, cmd[i].second);
//     }

//     //12시방향이 S극인 톱니바퀴의 개수를 출력
//     for (int i = 0; i < t; i++)
//     {
//         if (gear[i][0])
//             ans++;
//     }
//     printf("%d\n", ans);

//     return 0;
// }