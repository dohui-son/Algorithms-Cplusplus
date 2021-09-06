#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int yangbun[14][14], a[14][14];
vector<int> trees[14][14];
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring_summer()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (trees[i][j].size() == 0)
                continue;
            sort(trees[i][j].begin(), trees[i][j].end());
            int dead = 0;
            vector<int> tmp;
            for (int tt : trees[i][j])
            {
                if (a[i][j] - tt >= 0)
                {
                    tmp.push_back(tt + 1);
                    a[i][j] -= tt;
                }
                else
                    dead += (tt / 2);
            }
            trees[i][j].clear();
            trees[i][j] = tmp;
            a[i][j] += dead;
        }
    }
}

void fall_winter()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] += yangbun[i][j];
            if (trees[i][j].size() == 0)
                continue;
            for (int tt : trees[i][j])
            {
                if (tt % 5 == 0)
                {
                    for (int d = 0; d < 8; d++)
                    {
                        int ny = dy[d] + i;
                        int nx = dx[d] + j;
                        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                            continue;
                        trees[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> yangbun[i][j];
            a[i][j] = 5;
        }
    }
    int x = 0, y = 0, yr = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> yr;
        x--, y--;
        trees[x][y].push_back(yr);
    }
    while (k--)
    {
        spring_summer();
        fall_winter();
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ans += trees[i][j].size();
    }
    cout << ans << "\n";

    return 0;
}
