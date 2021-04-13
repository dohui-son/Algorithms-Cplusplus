//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <queue>
//
//using namespace std;
//#define endl "\n"
//int n, m, ans = 0;
//vector<pair<int,int>>l;
//vector<vector<char>> g(60,vector<char>(60));
//vector<vector<int>>visit(60, vector<int>(60));
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { 1,0,-1,0 };
//void ans_update(int sx, int sy);
//
//void most(pair<int, int> start) {
//	queue<vector<int>>q;
//	q.push({start.first,start.second,1});
//	visit[start.first][start.second] = 1;
//
//	int fx = 0;
//	int fy = 0;
//	int fd = 0;
//
//	while (!q.empty())
//	{
//		int x = q.front()[0];
//		int y = q.front()[1];
//		int dis = q.front()[2];
//		q.pop();
//		if(fd < dis){
//			fx = x;
//			fy = y;
//			fd = dis;
//		}
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			int nd = dis + 1;
//			
//			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
//			if (visit[nx][ny] == 0 && g[nx][ny] =='L') 
//			{
//				visit[nx][ny] = nd;
//				q.push({ nx,ny,nd });
//			}
//
//		}
//	}
//	ans_update(fx, fy);
//}
//
//void ans_update(int sx,int sy) {
//	vector<vector<int>>v(60, vector<int>(60));
//	queue<pair<int, int>>q;
//	q.push({ sx,sy });
//	v[sx][sy] = 1;
//
//	int ret = 1;
//	while (!q.empty())
//	{
//		pair<int, int>now= q.front();
//		q.pop();
//		ret = max(ret, v[now.first][now.second]);
//		
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = now.first + dx[i];
//			int ny = now.second + dy[i];
//			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
//			if (g[nx][ny] == 'L' && v[nx][ny] == 0) {
//				v[nx][ny] += v[now.first][now.second] + 1;
//				q.push({ nx,ny });
//			}
//		}
//	}
//	ans = max(ret - 1, ans);
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> n >> m;
//	string str;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> str;
//		for (int j = 0; j < m; j++)
//		{
//			g[i][j] = str[j];
//			if (g[i][j] == 'L')l.push_back(make_pair(i, j));
//		}
//	}
//	for (int i = 0; i < (int)l.size(); i++)
//	{
//		if (visit[l[i].first][l[i].second] == 0) { most(l[i]); }
//	}
//	cout << ans;
//	return 0;
//}