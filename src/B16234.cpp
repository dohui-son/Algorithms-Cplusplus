//// **********한번 인구이동이 일어날때도 한 지도에서 여러 연합이 존재할 수 있다.
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//#define endl "\n"
//int N, L, R, ans = 0;
//vector<vector<int>>g(53, vector<int>(53, 0));
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { 1,0,-1,0 };
//vector<vector<bool>>v(53, vector<bool>(53, false));
//
//void BFS(int xx, int yy, vector<vector<bool>>& visited) {
//	queue<pair<int, int>> q;
//	int sum = 0;
//	vector<pair<int, int>> to_open;
//	q.push({ xx,yy });
//	visited[xx][yy] = true;
//	while (!q.empty())
//	{
//		pair<int, int>now = q.front();
//		to_open.push_back(now);
//		sum += g[now.first][now.second];
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = now.first + dx[i];
//			int ny = now.second + dy[i];
//			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
//			if (visited[nx][ny])continue;
//			if (abs(g[nx][ny] - g[now.first][now.second]) >= L && abs(g[nx][ny] - g[now.first][now.second]) <= R) {
//				q.push({ nx,ny });
//				visited[nx][ny] = true;
//			}
//		}
//	}
//
//	int num = (int)to_open.size();
//	if (num >= 2) {
//		int new_gen = sum / num;
//		for (int i = 0; i < num; i++)
//		{
//			g[to_open[i].first][to_open[i].second] = new_gen;
//		}
//	}
//}
//
//bool is_open(int xx, int yy, vector<vector<bool>>& visited) 
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = xx + dx[i];
//		int ny = yy + dy[i];
//		if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
//
//		if (!visited[nx][ny]) {
//			int val = abs(g[nx][ny] - g[xx][yy]);
//			if (val >= L && val <= R)return true;
//		}
//	}
//	return false;
//}
//
//void solution() {
//	bool chk_res = true;
//	int sx = 0, sy = 0;
//	while (chk_res) {
//		
//		chk_res = false;
//		int j = sy;
//		vector<vector<bool>>visit(53, vector<bool>(53, 0));
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (!visit[i][j]) {
//					if (is_open(i, j, visit)) 
//					{
//						chk_res = true;
//						visit[i][j] = true;
//						BFS(i, j, visit);
//					}
//				}
//			}
//			
//		}
//		if(chk_res)ans++;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N >> L >> R;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> g[i][j];
//		}
//	}
//	solution();
//	cout << ans;
//
//
//
//	return 0;
//}