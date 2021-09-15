#include <bits/stdc++.h>
using namespace std;
int n, m, a[53][53];
pair<int, int> mm[102]; // d,s
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int cy[5], cx[5];
int fy[] = {-1, 1, -1, 1};
int fx[] = {-1, -1, 1, 1};

bool v[54][54];
set<pair<int, int> > se;
int ans = 0;

void c_move_rain(int idx)
{

    vector<pair<int, int> > moolboksa;
    int d = mm[idx].first;
    int s = mm[idx].second;

    for (auto ss : se)
    {
        int ny = (dy[d] * s) % n + ss.first;
        int nx = (dx[d] * s) % n + ss.second;

        if (ny < 0)
            ny += n;
        else if (ny >= n)
            ny -= n;
        if (nx < 0)
            nx += n;
        else if (nx >= n)
            nx -= n;

        v[ny][nx] = 1;
        a[ny][nx]++;
        moolboksa.push_back({ny, nx}); // se.erase({x,y})하면 segmentation fault가 뜬다.
    }
    se.clear();

    for (int i = 0; i < moolboksa.size(); i++)
    {
        int y = moolboksa[i].first, x = moolboksa[i].second;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + fy[i];
            int nx = x + fx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;
            if (a[ny][nx] > 0)
                a[y][x]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] >= 2 && v[i][j] == 0)
            {
                se.insert({i, j});
                a[i][j] -= 2;
            }
            ans += a[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int d = 0, s = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> d >> s;
        d--;
        mm[i] = {d, s};
    }
    cy[0] = n - 1;
    cy[1] = n - 1;
    cy[2] = n - 2;
    cy[3] = n - 2;
    cx[0] = 0;
    cx[1] = 1;
    cx[2] = 0;
    cx[3] = 1;
    for (int i = 0; i < 4; i++)
    {
        se.insert({cy[i], cx[i]});
    }

    for (int i = 0; i < m; i++)
    {
        ans = 0;
        c_move_rain(i);
        memset(v, 0, sizeof(v));
    }
    cout << ans << '\n';

    return 0;
}