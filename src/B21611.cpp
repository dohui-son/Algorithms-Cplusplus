#include <bits/stdc++.h>
using namespace std;

int n, m, shy, shx;
uint64_t ans;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int yy[] = {1, 0, -1, 0};
const int xx[] = {0, 1, 0, -1};
vector<vector<int> > g;
vector<pair<int, int> > magic;
string str, str2;
int cnt = 0;
char pre;

void bomb()
{
    cnt = 0;
    pre = '\0';
    for (int i = 0; i < str.size(); i++)
    {
        if (pre != str[i] && cnt < 4)
        {
            cnt = 1;
            pre = str[i];
            str2.push_back(str[i]);
        }
        else if (pre != str[i] && cnt >= 4)
        {
            ans += pre * cnt;
            str = str.substr(0, str.size() - cnt);
            if (str.empty())
                return;
            pre = str.back();
            cnt = 0;
            for (int i = str.size() - 1; i >= 0; i--)
            {
                if (str[i] == pre)
                    cnt++;
                else
                    break;
            }
        }
    }
}

void putin(int input)
{
    char c = input + '0';
    if (str.empty())
    {
        pre = c;
        cnt = 1;
        str.push_back(input);
    }
    else if (c == pre)
    {
        cnt++;
    }
    else if (c != pre && cnt >= 4)
    {
        ans += pre * cnt;
        str = str.substr(0, str.size() - cnt);
        if (str.empty())
            return;
        pre = str.back();
        cnt = 0;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] == pre)
                cnt++;
            else
                break;
        }
    }
    else if (c != pre && cnt < 4)
    {
        pre = c;
        cnt = 1;
    }
    return;
}

void dfs(int y, int x, int kan, int kdx, int dir)
{
    if (y == 0 && x == 0)
    {
        putin(g[y][x]);
        return;
    }
    if (kan == 0)
    {
        dfs(y, x, kdx / 2 + 1, kdx + 1, (dir + 1) % 4);
        return;
    }
    if (g[y][x] != 0)
        putin(g[y][x]);
    dfs(y + yy[dir], x + xx[dir], kan - 1, kdx, dir);
    return;
}

void magician(int idx)
{
    for (int i = 1; i <= magic[idx].second; i++)
    {
        int ny = shy + dy[magic[idx].first] * i;
        int nx = shx + dx[magic[idx].first] * i;
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        g[ny][nx] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    shy = shx = n / 2;
    g.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    int d = 0, dis = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> d >> dis;
        magic.push_back({--d, dis});
    }
    for (int k = 0; k < m; k++)
    {
        magician(k);
        str.clear();
        cnt = 0;
        pre = '\0';
        dfs(shy, shx - 1, 1, 1, 0); //void dfs(int y, int x, int kan, int kdx, int dir)
        str2.clear();
        while (1)
            if (bomb())
                break; //bomb가 더 터질 것 없으면 true;

        //refill();
    }

    return 0;
}