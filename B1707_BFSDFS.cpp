#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 20000 + 1
#define RED 1
#define BLUE 2

using namespace std;

int K, V, E;
vector<int> g[MAX_SIZE];
int visited[MAX_SIZE];

#define endl "\n";

void bfs(int start);
bool isBipartiteG();

bool isBipartiteG()
{
    for (int i = 0; i <= V; i++)
    {
        int g_size = g[i].size();
        for (int j = 0; j < g_size; j++)
        {
            int next = g[i][j];
            if (visited[i] == visited[next])
            {
                return 0;
            }
        }
    }
    return 1;
}

void bfs(int start)
{
    queue<int> q;
    int color = RED;
    visited[start] = color;
    q.push(start);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (visited[now] == RED)
        {
            color = BLUE;
        }
        else if (visited[now] == BLUE)
        {
            color = RED;
        }
        int g_size = g[now].size();
        for (int i = 0; i < g_size; i++)
        {
            int next = g[now][i];
            if (!visited[next])
            {
                visited[next] = color;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> K;
    int input1, input2;
    while (K--)
    {
        //입력
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            cin >> input1 >> input2;
            g[input1].push_back(input2);
            g[input2].push_back(input1);
        }
        //탐색
        for (int i = 0; i <= V; i++)
        {
            if (!visited[i])
            {
                bfs(i);
            }
            //(undireted일수도있음)아직도 방문안했으면 bfs
        }
        if (isBipartiteG() == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        for (int i = 0; i <= V; i++)
        {
            g[i].clear();
        }
        memset(visited, false, sizeof(visited));
    }

    return 0;
}