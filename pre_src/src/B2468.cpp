//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//
//using namespace std;
//
//int N , small=200, big, ans=1;
//vector<vector<int>>g(101, vector<int>(101, 0));
//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,-1,0,1 };
//
//void BFS(vector<vector<bool>>& v, int x, int y,int rained){
//	queue<pair<int, int>> q;
//	q.push(make_pair(x, y));
//	v[x][y] = true;
//	while (!q.empty())
//	{
//		pair<int, int> now = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = now.first + dx[i];
//			int ny = now.second + dy[i];
//			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
//			if (v[nx][ny] == true || g[nx][ny] <= rained) continue;
//
//			v[nx][ny] = true;
//			q.push(make_pair(nx, ny));
//
//		}
//
//	}
//	
//}
//
//void solution(int rain) {
//	vector<vector<bool>> visit(101,vector<bool>(101,false));
//	int tmp = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (visit[i][j] == false && g[i][j] > rain) {
//				tmp++;
//				BFS(visit, i, j, rain);
//			}
//		}
//	}
//	if (ans < tmp)ans = tmp;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> g[i][j];
//			if (small >= g[i][j])small = g[i][j];
//			if(big <= g[i][j])big = g[i][j];
//		}
//	}
//
//	for (int i = small-1; i < big+1; i++)
//	{
//		solution(i);
//	}
//
//	cout << ans;
//
//
//	return 0;
//}