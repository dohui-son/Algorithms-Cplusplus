//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <map>
//
//using namespace std;
//#define endl "\n";
//int R, C, ans = 987654321;
//vector<vector<char>>g;
//vector<vector<bool>>visit;
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//map < pair<int, int>, bool >visited;
//
//void BT(int cnt, pair<int, int>j_loc, vector<pair<int,int>> f_v, vector<vector<char>>now_g) {
//	if (cnt != 0) 
//	{
//		int num = f_v.size();
//		for (int i = 0; i < num; i++)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				int nx = f_v[i].first + dx[j];
//				int ny = f_v[i].second + dy[j];
//				if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
//				if (now_g[nx][ny] == '#')continue;
//				if (now_g[nx][ny] == 'J')return;
//
//				if (now_g[nx][ny] == '.') {
//					f_v.push_back({ nx,ny });
//					now_g[nx][ny] = 'F';
//				}
//			}
//		}
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = j_loc.first + dx[i];
//		int ny = j_loc.second + dy[i];
//		if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
//			ans = min(cnt, ans);
//			return;
//		}
//		if (now_g[nx][ny] == '#' || now_g[nx][ny] == 'F')continue;
//		
//		if (now_g[nx][ny] == '.')
//		{
//			if (visited[{nx, ny}])continue; 
//			now_g[j_loc.first][j_loc.second] = '.';
//			now_g[nx][ny] = 'J';
//			visited[{nx, ny}] = true;
//			//BT(int cnt, pair<int, int>j_loc, vector<pair<int,int>> f_v, vector<vector<char>>now_g)
//			BT(cnt + 1, {nx,ny}, f_v,now_g);
//
//			now_g[j_loc.first][j_loc.second] = 'J';
//			now_g[nx][ny] = '.';
//			visited[{nx, ny}] = false;
//		}
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
//	cin >> R >> C;
//	string str;
//	pair<int, int>J;
//	g = vector<vector<char>>(R, vector<char>(C,0));
//	vector<pair<int, int>>fire;
//	
//	
//	for (int i = 0; i < R; i++)
//	{
//		cin >> str;
//		for (int j = 0; j < C; j++)
//		{
//			g[i][j] = str[j];
//			if (g[i][j] == 'J') {
//				J = { i,j };
//				visited.insert({ {i,j},true });
//			}
//			else if (g[i][j] == 'F')fire.push_back({ i,j });
//			else if (g[i][j] == '.')visited.insert({ {i,j},false });
//		}
//	}
//	//BT(int cnt, pair<int, int>j_loc, vector<pair<int,int>> f_v, vector<vector<char>>now_g)
//	BT(0,J,fire,g);
//	if (ans == 987654321)cout << "IMPOSSIBLE";
//	else cout << ans+1;
//
//
//
//	return 0;
//}