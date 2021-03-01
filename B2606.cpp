#include <iostream>
#include <vector>
#include <queue>

#define endl "\n";

using namespace std;
int computer, nodes;
vector<vector<int>> g;
vector<int> visit;

void BFS()
{
    queue<int> q;
    q.push(0);
    visit[0] = 1;
    int ans = 0;
    while (!q.empty())
    {
        int now = q.front();

        ans++;
        q.pop();
        for (int i = 0; i < computer; i++)
        {
            if (g[now][i] == 0 || visit[i] == 1)
                continue;

            q.push(i);
            visit[i] = 1;
        }
    }
    cout << ans - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> computer >> nodes;
    g = vector<vector<int>>(computer, vector<int>(computer, 0));
    visit = vector<int>(computer, 0);
    for (int i = 0; i < nodes; i++)
    {
        int idx1, idx2;
        cin >> idx1 >> idx2;
        g[idx1 - 1][idx2 - 1] = 1;
        g[idx2 - 1][idx1 - 1] = 1;
    }
    BFS();

    return 0;
}