#include <iostream> //내가 직접 짠 코드
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int n, k, ans, yy, xx, dd, ff, flag;

vector<vector<int> > g(14, vector<int>(14, 0));
vector<vector<vector<int> > > m(14, vector<vector<int> >(14, vector<int>(0, 0)));

struct Mal
{
    int y, x, dir, floor;
};
vector<Mal> mal;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    mal.push_back({0, 0, 0});
    for (int i = 0; i < k; i++)
    {
        cin >> yy >> xx >> dd;
        yy--, xx--, dd--;
        mal.push_back({yy, xx, dd});
        m[yy][xx].push_back(i + 1);
    }

    while (ans < 1001)
    {
        for (int i = 1; i <= k; i++)
        {
            if (m[mal[i].y][mal[i].x][0] != i)
                continue;
            int x = mal[i].x;
            int y = mal[i].y;
            int ny = dy[mal[i].dir] + y;
            int nx = dx[mal[i].dir] + x;
            if (ny < 0 || nx < 0 || ny >= n || nx >= n || g[ny][nx] == 2)
            {
                if (mal[i].dir < 2)
                {
                    if (mal[i].dir < 1)
                        mal[i].dir = 1;
                    else
                        mal[i].dir = 0;
                }
                else
                {
                    if (mal[i].dir < 3)
                        mal[i].dir = 3;
                    else
                        mal[i].dir = 2;
                }
                ny = dy[mal[i].dir] + y;
                nx = dx[mal[i].dir] + x;
                if (ny < 0 || nx < 0 || ny >= n || nx >= n || g[ny][nx] == 2)
                    continue;
                else
                {
                    if (g[ny][nx] == 0)
                    {

                        for (int i = 0; i < m[y][x].size(); i++)
                        {
                            m[ny][nx].push_back(m[y][x][i]);
                            mal[m[y][x][i]].y = ny;
                            mal[m[y][x][i]].x = nx;
                        }
                        m[y][x].erase(m[y][x].begin(), m[y][x].end());
                    }
                    else if (g[ny][nx] == 1)
                    { //red

                        reverse(m[y][x].begin(), m[y][x].end());
                        for (int i = 0; i < m[y][x].size(); i++)
                        {
                            m[ny][nx].push_back(m[y][x][i]);
                            mal[m[y][x][i]].y = ny;
                            mal[m[y][x][i]].x = nx;
                        }
                        m[y][x].erase(m[y][x].begin(), m[y][x].end());
                    }
                }
            }
            else if (g[ny][nx] == 0)
            {
                for (int i = 0; i < m[y][x].size(); i++)
                {
                    m[ny][nx].push_back(m[y][x][i]);
                    mal[m[y][x][i]].y = ny;
                    mal[m[y][x][i]].x = nx;
                }
                m[y][x].erase(m[y][x].begin(), m[y][x].end());
            }
            else if (g[ny][nx] == 1)
            { //red

                reverse(m[y][x].begin(), m[y][x].end());
                for (int i = 0; i < m[y][x].size(); i++)
                {
                    m[ny][nx].push_back(m[y][x][i]);
                    mal[m[y][x][i]].y = ny;
                    mal[m[y][x][i]].x = nx;
                }
                m[y][x].erase(m[y][x].begin(), m[y][x].end());
            }
        }

        ans++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j].size() >= 4)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            break;
    }
    if (ans > 1000)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}