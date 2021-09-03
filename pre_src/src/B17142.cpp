////디버깅필요
//#include <iostream>
//#include <vector>
//#include <deque>
//#include<queue>
//#include <algorithm>
//
//// constexpr int wall = -3; 상수선언해서 쓰기
//
//
//using namespace std;
//#define endl "\n"
//int ans = 55000, N, M, tmp = 55000;
//vector<vector <int>> g(50, vector<int>(50, 0));
//deque<pair<int, int>>sleeping;
//vector<bool> active;
//
//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,-1,0,1 };
//
//
//bool spread(int& candidate, vector<vector<int>> ggg, deque<pair<int, int>> yet);
//void BT(int count, int next_idx, deque<pair<int, int>>& unlive, vector<vector<int>>& gg);
//
//
//bool spread(vector<vector<int>> ggg) {
//	tmp = -500000;
//
//	queue<pair<int, int>>q;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++) {
//			if (ggg[i][j] == 0) {
//				q.push(make_pair(i, j));
//				
//			}
//		}
//	}
//	while (!q.empty())
//	{
//		pair<int, int>now = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = dx[i] + now.first;
//			int ny = dy[i] + now.second;
//
//			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
//			if (ggg[nx][ny] == '*' )continue;
//
//			if (ggg[nx][ny] == '+' ) {
//				ggg[nx][ny] = ggg[now.first][now.second] + 1;
//				tmp = max(tmp, ggg[nx][ny]);
//				q.push(make_pair(nx, ny));
//			}
//			else if (ggg[nx][ny] == -1) {
//				ggg[nx][ny] = 0;
//				q.push(make_pair(nx, ny));
//			}
//		}
//	}
//	
//
//
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//
//			if (ggg[i][j] == '$')return false;
//		}
//	}
//
//
//	cout << endl;
//	cout << tmp << endl;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (ggg[i][j] == '*' || ggg[i][j] == '+')cout << (char)ggg[i][j] << " ";
//			else cout << g[i][j] << " ";
//		}
//		cout << endl;
//
//	}
//
//	return true;
//}
//
//
//
//void BT(int count, int next_idx, deque<pair<int, int>>& unlive, vector<vector<int>>& gg, queue<pair<int,int>>& q) {
//	if (count == M) {
//		if (spread(gg))ans = min(ans, tmp);
//		return;
//	}
//	else {
//		for (int i = next_idx; i < unlive.size(); i++)
//		{ // 0,1,2   0,1,3   0,1,4
//			//if (active[i] == true)continue;
//			pair<int, int> now = unlive[i];
//			q.
//		
//			gg[now.first][now.second] = 0;
//			active[i] = true;
//
//			BT(count + 1, i+1, unlive, gg);
//
//			gg[now.first][now.second] = -1;
//			
//			active[i] = false;
//		}
//	}
//
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++) {
//
//			cin >> g[i][j];
//			if (g[i][j] == 0)g[i][j] = '+';
//			if (g[i][j] == 1)g[i][j] = '*';
//			if (g[i][j] == 2) {
//				g[i][j] = -1;
//				sleeping.push_back(make_pair(i, j));
//				active.push_back(false);
//			}
//		}
//
//	}
//	BT(0, 0, sleeping, g);
//	if (ans == 55000)cout << -1;
//	else cout << ans;
//
//
//	return 0;
//}