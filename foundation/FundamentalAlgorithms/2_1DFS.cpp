#include <bits/stdc++.h>
using namespace std;
int visited[1004][1004];
//레벨별로 탐색하거나 가중치 같은 그래프 내에서 최단거리 알고리즘은 BFS로만 해야한다
void DFS(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || g[ny][nx] == 0)
            continue;
        DFS(ny, nx);
    }
    return;
}

//[인접리스트]****정점간의 관계표현 "인접리스트" 빅오(V+E) "인접행렬" 빅오(V^2)___공간복잡도도 동일
vector<int> adj[1003];
void f(int here)
{
    adj[0].push_back(2); //0에서 2까지 갈수 있다면
    for (int i = 0; i < V; i++)
    {
        //i에서 there까지 갈 수 있다.
        for (int there : adj[i])
        {
            //로직
        }
    }
}