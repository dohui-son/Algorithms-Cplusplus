//#include <iostream>
//#include <vector>
//#include<string>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//#define endl "\n"
//int N, M, ans = 0;
//string str;
//vector<vector<char>> g(50,vector<char>(50));
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { 1,0,-1,0 };
//
//
//void BFS(int x, int y) {
//	queue<pair<int, int>>q;
//	q.push({ x,y });
//	vector<vector<int>>visit(50, vector<int>(50, false));
//	visit[x][y] = 1;
//	while (!q.empty())
//	{
//		pair<int, int>now = q.front();
//		q.pop();
//		ans = max(ans, visit[now.first][now.second]);
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = dx[i] + now.first;
//			int ny = dy[i] + now.second;
//			if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
//			if (visit[nx][ny] || g[nx][ny] =='W')continue;
//			q.push({ nx,ny });
//			visit[nx][ny] = visit[now.first][now.second]+1;
//			
//
//		}
//
//
//
//	}
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> str;
//		for (int j = 0; j < M; j++)
//		{
//			g[i][j] = str[j];
//		}
//
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++) {
//			if (g[i][j] == 'L')BFS(i,j);
//		}
//
//	}
//	cout << ans - 1;
//
//	return 0;
//}