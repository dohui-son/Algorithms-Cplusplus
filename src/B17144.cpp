////한번에 성공 집중력 분산으로 2시간 30분걸림
//#include <iostream>
//#include <vector>
//#include<queue>
//
//
//using namespace std;
//#define endl "\n"
//int R, C, T;
//vector<vector<int>> g;
//int xx[4] = { -1,0,1,0 };
//int yy[4] = { 0,1,0,-1 };
//vector<int> px(2,-1);
//
//
//void spread(queue<vector<int>>& qq, vector<vector<bool>>& visited) {
//	while (!qq.empty())
//	{
//		int x = qq.front()[0];
//		int y = qq.front()[1];
//		qq.pop();
//		visited[x][y] = false;
//		int next = g[x][y] / 5;
//		int count = 0;
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = xx[i] + x;
//			int ny = yy[i] + y;
//			if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
//			if (g[nx][ny] == -1)continue;
//			if (visited[nx][ny] == true) spread(qq, visited);
//			g[nx][ny] += next;
//			count++;
//		}
//		g[x][y] = g[x][y] - (next * count);
//	}
//}
//
//
//void dirt() {
//	vector<vector<bool>>visit;
//	visit = vector<vector<bool>>(R, vector<bool>(C,false));
//	queue<vector<int>> q;
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			if (g[i][j] == -1 || g[i][j] == 0)continue;
//			
//			q.push({ i,j });
//			visit[i][j] = true;
//		}
//	}
//	//먼지퍼뜨리기
//	spread(q, visit);
//}
//
//void purify_upper() {
//	for (int i = px[0]-1; i > 0; i--)
//	{
//		
//			g[i][0] = g[i - 1][0];
//			g[i - 1][0] = 0;
//		
//	}
//	//g[px[0]][0] = -1;
//
//	// right to left
//	for (int i = 0; i < C-1; i++)
//	{
//		
//			g[0][i] = g[0][i + 1];
//			g[0][i + 1] = 0;
//		
//	}
//	//right down(px[0]) to right upper[0]
//	for (int i = 0; i < px[0] ; i++)
//	{
//		g[i][C - 1] = g[i + 1][C-1];
//		g[i + 1][C - 1]= 0;
//
//	}
//
//	for (int i = C-1; i >1; i--)
//	{
//		g[px[0]][i] = g[px[0]][i - 1];
//		g[px[0]][i - 1] = 0;
//	}
//}
//void purify_down() {
//	for (int i = px[1]+1; i <R-1; i++)
//	{
//		g[i][0] = g[i + 1][0];
//		g[i + 1][0] = 0;
//	}
//	//g[px[1]][0] = -1;
//	for (int i = 0; i < C-1; i++)
//	{
//		g[R - 1][i] = g[R - 1][i + 1];
//		g[R - 1][i + 1] = 0;
//	}
//	for (int i = R-1; i > px[1]; i--)
//	{
//		g[i][C - 1] = g[i - 1][C - 1];
//		g[i - 1][C - 1] = 0;
//	}
//	for (int i = C-1; i > 1; i--)
//	{
//		g[px[1]][i] = g[px[1]][i - 1];
//		g[px[1]][i - 1] = 0;
//	}
//}
//
//
//void process() {
//	dirt();
//	purify_upper();
//	purify_down();
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	cin >> R >> C >> T;
//	g = vector<vector<int>>(R, vector<int>(C));
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			cin >> g[i][j];
//
//			if (g[i][j] == -1 && px[0] == -1) {
//				px[0] = i;
//			
//			}
//			if (g[i][j] == -1 && px[0] != -1) {
//				px[1] = i;
//		
//			}
//		}
//	}
//	for (int i = 0; i < T; i++)
//	{
//		process();
//	}
//	int ans=0;
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			if (g[i][j] > 0) ans += g[i][j];
//		}
//	}
//	cout << ans;
//
//	
//	return 0;
//}