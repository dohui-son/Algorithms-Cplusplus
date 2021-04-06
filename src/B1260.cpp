#include <iostream>
#include <vector>
#include <queue>
//#include "../print.hpp"

#define endl "\n";

using namespace std;

int N, M, V;
vector<vector<int>> g;
vector<int> visit;

void DFS(int v)
{

    visit[v] = 1;
    cout << v + 1 << " ";
    for (int i = 0; i < N; i++)
    {
        if (visit[i] == 0 && g[v][i] == 1)
            DFS(i);
    }
}

void BFS(int v)
{
    queue<int> q;
    q.push(v);
    visit[v] = 1;
    while (!q.empty())
    {
        int now = q.front();
        cout << now + 1 << " ";
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (g[now][i] == 1 && visit[i] == 0)
            {
                q.push(i);
                visit[i] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N >> M >> V;
    g = vector<vector<int>>(N, vector<int>(N, 0));
    visit = vector<int>(N, 0);
    for (int i = 0; i < M; i++)
    {
        int idx1, idx2;
        cin >> idx1 >> idx2;
        g[idx1 - 1][idx2 - 1] = 1;
        g[idx2 - 1][idx1 - 1] = 1;
    }

    DFS(V - 1);

    cout << endl;
    visit.clear();
    visit = vector<int>(N, 0);
    //cout << visit;

    BFS(V - 1);

    return 0;
}