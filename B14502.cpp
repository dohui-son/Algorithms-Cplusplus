//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <deque>
//#include <queue>
//
//using namespace std;
//
//#define endl "\n";
//int N, M, ans=0; // 세로 가로
//vector<vector<int>>g(9, vector<int>(9,0));
//deque<pair<int, int>> cand;
//deque<pair<int, int>>virus;
//
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { 1,0,-1,0 };
//
//
//void spread(vector<vector<int>> gg) {
//	queue<pair<int, int>>q;
//	vector<vector<int>>visit(9, vector<int>(9, 0));
//	for (int i = 0; i < virus.size(); i++)
//	{
//		
//		q.push(virus[i]);
//		visit[virus[i].first][virus[i].second] = 1;
//		while (!q.empty())
//		{
//			pair<int, int> now = q.front();
//			q.pop();
//			for (int j = 0; j < 4; j++)
//			{
//				int nx = dx[j] + now.first;
//				int ny = dy[j] + now.second;
//				if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
//
//				if (gg[nx][ny] == 1 )continue;
//				if (visit[nx][ny] == 0 && gg[nx][ny] == 0) {
//
//					visit[nx][ny] = 1;
//					gg[nx][ny] = 2;
//					q.push({ nx,ny });
//				}
//
//			}
//			
//
//		}
//	}
//
//	int tmp = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (gg[i][j] == 0)tmp++;
//		}
//	}
//	ans = max(ans, tmp);
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> g[i][j];
//			if (g[i][j] == 0)cand.push_back(make_pair(i, j));
//			else if (g[i][j] == 2)virus.push_back(make_pair(i, j));
//		}
//
//	}
//	pair<int, int> tmp1, tmp2, tmp3;
//	for (int i = 0; i < cand.size(); i++)
//	{
//		for (int j = i+1; j < cand.size(); j++)
//		{
//			for (int t = j+1; t < cand.size(); t++)
//			{
//				tmp1 = cand[i];
//				tmp2 = cand[j];
//				tmp3 = cand[t];
//				g[tmp1.first][tmp1.second] = 1;
//				g[tmp2.first][tmp2.second] = 1;
//				g[tmp3.first][tmp3.second] = 1;
//				spread(g);
//				g[tmp1.first][tmp1.second] = 0;
//				g[tmp2.first][tmp2.second] = 0;
//				g[tmp3.first][tmp3.second] = 0;
//
//			}
//		}
//	}
//	cout << ans;
//
//	return 0;
//}
