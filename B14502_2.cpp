//#include <iostream>
//#include <vector>
//#include<algorithm>
//#include<queue>
//using namespace std;
//#define endl "\n"
//int N, M, ans = 0;
//queue<vector<int>> virus;
//vector<vector<int>> g; //N세로 M가로
//int xx[4] = { 0,-1,0,1 };
//int yy[4] = { 1,0,-1,0 };
//
//void ans_update(vector<vector<int>>& ng);
//void spread(vector<vector<int>>& graph);
//void build(int cnt, int sx, int sy, vector<vector<int>>& gg);
//
//
//void ans_update(vector<vector<int>>& ng) {
//	int tmp = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (ng[i][j] == 0)tmp++;
//		}
//
//	}
//	
//	ans = max(ans, tmp);
//}
//
//void spread(vector<vector<int>>& graph ) {
//
//	queue<vector<int>> q = virus;
//	while (!q.empty())
//	{
//		vector<int>vv = q.front();
//		q.pop();
//		int x = vv[0];
//		int y = vv[1];
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + xx[i];
//			int ny = y + yy[i];
//			if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
//			if (graph[nx][ny] == 1 || graph[nx][ny] == 2)continue;
//			graph[nx][ny] = 2;
//			q.push({ nx,ny });
//		}
//	}
//	
//	
//}
//
//
//
//void build(int cnt ,int sx ,int sy, vector<vector<int>>& gg ) {
//	if (cnt == 3) {
//		spread(gg);
//		ans_update(gg);
//		return;
//	}
//
//	int i = sx;
//	int j = sy;
//	for (; i < N; i++)
//	{
//		for (; j < M; j++)
//		{
//			if (gg[i][j] == 0) {
//				vector<vector<int>>g2 = gg;
//				gg[i][j] = 1;
//				build(cnt + 1, i, j, g2);
//			}
//		}
//		j = 0;
//
//	}
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	cin >> N >> M;
//	g = vector<vector<int>>(N, vector<int>(M));
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> g[i][j];
//			if (g[i][j] == 2)virus.push({ i,j });
//		}
//	}
//	//build(int cnt, int sx, int sy, vector<vector<int>>&gg)
//	build(0, 0,0,g);
//	cout << ans;
//
//	return 0;
//}