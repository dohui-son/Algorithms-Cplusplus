//#include<iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//#define endl "\n"
//int R, C;
//string str;
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { -1,0,1,0 };
//vector<vector<char>> g(1001, (1001, vector<char>(1001)));
//vector<vector<int>>vf(1001, (1001, vector<int>(1001)));
//vector<vector<int>>vp(1001, (1001, vector<int>(1001)));
//queue<pair<int, int>> qq;
//void fbfs(pair<int, int> f) {
//	
//	
//	while (!qq.empty())
//	{
//		pair<int, int> now = qq.front();
//		qq.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int ny = dy[i] + now.first;
//			int nx = dx[i] + now.second;
//			if (ny < 0 || nx < 0 || ny >= R || nx >= C)continue;
//			if (g[ny][nx] == '#' || vf[ny][nx] != 0)continue;
//
//			vf[ny][nx] = vf[now.first][now.second] + 1;
//			qq.push({ ny,nx });
//
//		}
//
//	}
//}
//int pbfs(pair<int,int> p){
//	vp[p.first][p.second] = 1;
//	queue<pair<int, int>>q;
//	q.push(p);
//	while (!q.empty()) {
//		pair<int, int> now = q.front();
//		q.pop();
//
//		if (now.first == 0 || now.second == 0 || now.first == R - 1 ||
//			now.second == C - 1)return vp[now.first][now.second];
//		for (int i = 0; i < 4; i++)
//		{
//			int ny = dy[i] + now.first;
//			int nx = dx[i] + now.second;
//			if (ny < 0 || nx < 0 || ny >= R || nx >= C)continue;
//
//			if (g[ny][nx] == '#' || g[ny][nx] == 'F'
//				|| vp[ny][nx]!=0
//				)continue;
//			if (vf[ny][nx] != 0 && vf[ny][nx] <= vp[now.first][now.second] + 1)continue;
//			vp[ny][nx] = vp[now.first][now.second] + 1;
//			q.push({ ny,nx });
//
//		}
//	}
//	return -1;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> R >> C;
//	pair<int, int>J, F;
//	for (int i = 0; i < R; i++)
//	{
//		cin >> str;
//		for (int j = 0; j < C; j++)
//		{
//			g[i][j] = str[j];
//			if (g[i][j] == 'J')J = make_pair(i,j );
//			if (g[i][j] == 'F') {
//				F = make_pair(i, j);
//				qq.push(F);
//				vf[i][j] = 1;
//				
//			}
//		}
//	}
//	fbfs(F);
//
//
//
//
//	int ret= pbfs(J);
//	//for (int i = 0; i < C; i++)
//	//{
//	//	for (int j = 0; j < R; j++)
//	//	{
//	//		cout <<vp[i][j] << " ";
//
//	//	}
//	//	cout << endl;
//
//	//}
//	if (ret == -1)cout << "IMPOSSIBLE";
//	else cout << ret;
//	
//
//	return 0;
//}