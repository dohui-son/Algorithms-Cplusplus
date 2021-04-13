//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <deque>
//#include <queue>
//
//using namespace std;
//#define endl "\n"
//vector<vector<int>>g(102, vector<int>(102, 0));
//int M, N, K;
//int answer = 0;
//vector<int> ans;
//vector<vector<int>>visit(102, vector<int>(102, 0));
//
//int dy[4] = { -1,0,1,0 };
//int dx[4] = { 0,-1,0,1 };
//
//void BFS(int yy, int xx) {
//	int tmp = 1;
//	g[yy][xx] =2;
//	visit[yy][xx] = 1;
//	queue<pair<int, int>>q;
//	q.push(make_pair(yy, xx));
//	
//	while (!q.empty())
//	{
//		pair<int, int> now = q.front();
//		q.pop();
//		
//		for (int i = 0; i < 4; i++)
//		{
//			int ny = dy[i] + now.first;
//			int nx = dx[i] + now.second;
//			if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
//			if (visit[ny][nx] == 0 && g[ny][nx] == 0) {
//				tmp++;
//				g[ny][nx] = 2;
//				visit[ny][nx] = 1;
//				q.push(make_pair(ny, nx));
//			}
//		}
//	}
//	ans.push_back(tmp);
//}
//
//
//void solution() {
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (g[i][j] == 0 && visit[i][j] == 0) {
//				answer++;
//				BFS(i,j);
//			}
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr); 
//	cin >> M >> N >> K;
//	int lx = 0, ly = 0, rx = 0, ry = 0;
//	for (int i = 0; i < K; i++)
//	{
//		cin >> lx >> ly >> rx >> ry;
//		for (int j = lx; j < rx; j++)
//		{
//			for(int k= ly; k<ry; k++)
//			{
//				g[k][j] = 1;
//			}
//		}
//	}
//
//	solution();
//
//	cout << endl;
//	cout << answer << endl;
//
//	sort(ans.begin(), ans.end());
//	for (int i = 0; i < ans.size(); i++)
//	{
//		cout << ans[i] << " ";
//	}
//
//
//
//	return 0;
//}