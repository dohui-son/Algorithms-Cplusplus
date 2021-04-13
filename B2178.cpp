//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
//#include <stdio.h>
//#include <vector>
//#include <queue>
//
//
//
//
//using namespace std;
//#define endl "\n"
//
//int N, M;
//int g[101][101];
//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,-1,0,1 };
//
//
//int main() {
//
//	scanf("%d %d", &N, &M);
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)scanf("%1d", &g[i][j]);
//	}
//
//
//	queue<pair<int, int>>q;
//	q.push(make_pair(0, 0));
//
//	int ans = 0;
//	while (!q.empty()) {
//
//		pair<int, int>now = q.front();
//		q.pop();
//		if (now.first == N - 1 && now.second == M - 1) 
//		{
//			ans = g[N - 1][M - 1];
//			break;
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = now.first + dx[i];
//			int ny = now.second + dy[i];
//			if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
//
//			if (g[nx][ny] == 1) {
//				g[nx][ny] += g[now.first][now.second];
//				q.push(make_pair(nx, ny));
//			}
//		}
//	}
//
//	printf("%d", ans);
//	return 0;
//}