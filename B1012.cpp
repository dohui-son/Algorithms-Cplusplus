//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//#include <stdio.h>
//#include<vector>
//#include <queue>
//
//using namespace std;
//int T, N, M, K;
//queue<int>ans;
//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,-1,0,1 };
//
//
//void BFS(int x, int y, vector<vector<int>>& ggg) {
//	queue<pair<int, int>>q;
//	q.push(make_pair(x, y));
//	while (!q.empty())
//	{
//		pair<int, int> now = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = now.first + dx[i];
//			int ny = now.second+ dy[i];
//			if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
//			if (ggg[nx][ny] == 1) {
//				ggg[now.first][now.second]=2;
//				ggg[nx][ny] = 2;
//				q.push(make_pair(nx, ny));
//			}
//
//		}
//	}
//}
//
//int solution(vector<vector<int>>& gg) {
//	int ret = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (gg[i][j] == 1) {
//				ret++;
//				BFS(i, j , gg);
//			}
//		}
//	}
//	return ret;
//}
//
//
//int main() {
//
//
//	int x = 0, y = 0;
//	scanf("%d", &T);
//	for (int i = 0; i < T; i++)
//	{
//		vector<vector<int>> g(51,vector<int>(51,0));
//		scanf("%d %d %d", &M, &N, &K);
//		for (int j = 0; j < K; j++)
//		{
//			scanf("%d %d", &x, &y);
//			g[y][x] = 1;
//		}
//		ans.push(solution(g));
//	}
//	
//	while (!ans.empty())
//	{
//		printf("%d \n",ans.front());
//		ans.pop();
//	}
//
//	return 0;
//}