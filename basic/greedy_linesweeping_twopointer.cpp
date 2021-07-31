
100, 000
    ////////////////////////////////////////////////////////////
    // #include <iostream> //// 주사위 윷놀이
    // #include <vector>
    // #include <algorithm>
    // using namespace std;
    // #define endl "\n"

    // const int INF = 987654321;
    // int a[14], mal[4], n = 10;
    // int v[104];
    // vector<int> adj[54];

    // int move(int here, int cnt)
    // {
    //     if (here == 100)
    //         return 100;
    //     if (adj[here].size() >= 2)
    //     {
    //         here = adj[here][1];
    //         cnt--;
    //     }
    //     if (cnt)
    //     {
    //         queue<int> q;
    //         q.push(here);
    //         int there = 0;
    //         while (q.size())
    //         {
    //             int x = q.front();
    //             q.pop();
    //             there = adj[x][0];
    //             q.push(there);
    //             if(there == 100)break;
    //             cnt--;
    //             if(cnt == 0)break;
    //         }return there;
    //     }
    //     else return here;
    // }

    // int go(int here)
    // {
    //     if (here == n)
    //         return 0;
    //     int ret = 0;
    //     for (int i = 0; i < 4; i++)
    //     {
    //         int tmp_idx = mal[i];
    //         int mdx = move(tmp_idx, a[here]);
    //         if (isMal(mdx, i))
    //             continue;
    //         mal[i] = mdx;
    //         ret = max(ret, go(here + 1) + v[mdx]);
    //         mal[i] = tmp_idx;
    //     }
    //     return ret;
    // }

    // void add(int here, int there)
    // {
    //     adj[here].push_back(there);
    // }

    // void setMap()
    // {
    //     for (int i = 0; i <= 19; i++)
    //         add(i, i + 1);
    //     add(5, 21);
    //     add(21, 22);
    //     add(22, 23);
    //     add(23, 24);
    //     add(15, 29);
    //     add(29, 30);
    //     add(30, 31);
    //     add(31, 24);

    //     add(10, 27);
    //     add(27, 28);
    //     add(28, 24);
    //     add(24, 25);
    //     add(25, 26);
    //     add(26, 20);
    //     add(20, 100);

    //     v[1] = 2;
    //     v[2] = 4;
    //     v[3] = 6;
    //     v[4] = 8;
    //     v[5] = 10;
    //     v[6] = 12;
    //     v[7] = 14;
    //     v[8] = 16;
    //     v[9] = 18;
    //     v[10] = 20;
    //     v[11] = 22;
    //     v[12] = 24;
    //     v[13] = 26;
    //     v[14] = 28;
    //     v[15] = 30;
    //     v[16] = 32;
    //     v[17] = 34;
    //     v[18] = 36;
    //     v[19] = 38;
    //     v[20] = 40;
    //     v[21] = 13;
    //     v[22] = 16;
    //     v[23] = 19;
    //     v[24] = 25;
    //     v[27] = 22;
    //     v[28] = 24;
    //     v[25] = 30;
    //     v[26] = 35;
    //     v[29] = 28;
    //     v[30] = 27;
    //     v[31] = 26;
    // }
    // int main()
    // {
    //     ios::sync_with_stdio(false);
    //     cin.tie(nullptr);
    //     cout.tie(nullptr);
    //     setMap();
    //     for (int i = 0; i < n; i++)
    //     {
    //         cin >> a[i];
    //     }
    //     cout << go(0) << endl;
    //     return 0;
    // }
    //////////////////////////////////////////////////
    // #include <iostream> ////B1700멀티탭스케줄링 - 페이징기법
    // #include <vector>
    // #include <algorithm>
    // #define endl '\n'
    // using namespace std;
    // const int INF = 987654321;
    // int k, n, a[104], visited[104], cnt;
    // vector<int> v;

    // int main()
    // {
    //     ios::sync_with_stdio(false);
    //     cin.tie(nullptr);
    //     cout.tie(nullptr);
    //     cin >> k >> n;
    //     for (int i = 0; i < n; i++)
    //     {
    //         cin >> a[i];
    //     }
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (!visited[a[i]])
    //         {
    //             if (v.size() == k)
    //             {
    //                 int last_idx = 0, off_idx;
    //                 for (int aa : v)
    //                 {
    //                     int here_pick = INF;
    //                     for (int j = i + 1; j < n; j++)
    //                     {
    //                         if (aa == a[j])
    //                         {
    //                             here_pick = j;
    //                             break;
    //                         }
    //                     }
    //                     if (last_idx < here_pick)
    //                     {
    //                         last_idx = here_pick;
    //                         off_idx = aa;
    //                     }
    //                 }
    //                 visited[off_idx] = 0;
    //                 cnt++;
    //                 v.erase(find(v.begin(), v.end(), off_idx));
    //             }
    //             v.push_back(a[i]);
    //             visited[a[i]] = 1;
    //         }
    //     }
    //     cout << cnt << endl;
    //     return 0;
    // }

    // ////////////////////////////////////
    // #include <iostream>
    // #include <vector>
    // #include <algorithm>
    // #define endl "\n"
    // using namespace std;

    // int main()
    // {
    //     ios::sync_with_stdio(false);
    //     cin.tie(nullptr);
    //     cout.tie(nullptr);

    //     return 0;
    // }

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
