////B20056 디버깅 실패
//
//#include <iostream>
//#include<vector>
//#include<map>
//#include<queue>
//
//using namespace std;
//#define endl "\n"
//vector<vector<int>>visit;
//vector<vector<vector<int>>>g;
//int N, M, K;
//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx2[4] = { -1,1,1,-1 };
//int dy2[4] = { 1,1,-1,-1 };
//
//
//void next_xy(int& x, int& y, bool speed_given, int dir) {
//	int speed = 1;
//	if (dir == -1)dir = g[x][y][2];
//	if (speed_given)speed = g[x][y][1];
//	
//	if (dir % 2 == 0) {
//		dir /= 2;
//		x = x + dx[dir] * (speed % N);
//		y = y + dy[dir] * (speed % N);
//
//	}
//	else {
//		if (dir != 0)dir /= 2;
//		x = x + dx2[dir] * (speed % N);
//		y = y + dx2[dir] * (speed % N);
//
//	}
//	if (x < 0)x = N + x;
//	if (y < 0)y = N + y;
//	if (x >= N)x = x % N;
//	if (y >= N)y = y % N;
//
//}
//
//
//void cmd() {
//	map<pair<int, int>, vector<vector<int>>> m;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (g[i][j][0] > 0) {
//				int nx = i;
//				int ny = j;
//				next_xy(nx, ny,true,-1);
//				m[make_pair(nx, ny)].push_back({ g[i][j][0],g[i][j][1], g[i][j][2]  }); //////*******이줄 문법 문제인듯....
//				if (m[{nx, ny}].size() >= 2)cout << "OOOOOOKK" << endl;
//				g[i][j][0] = 0;
//				g[i][j][1] = 0;
//				g[i][j][2] = 0;
//			}
//		}
//	}
//	
//	for (auto mm : m) {
//		
//		if (mm.second.size() == 1) { // 해당칸에 파이어볼 1개임********이줄 문법 문제인듯....
//			vector<int> now = mm.second.front();
//			mm.second.pop_back();
//			g[mm.first.first][mm.first.second][0] += now[0];
//			g[mm.first.first][mm.first.second][1] += now[1];
//			g[mm.first.first][mm.first.second][2] = now[2];
//		}
//		else {
//			int nm = 0;
//			int ns = 0;
//			int nd = -1; // 0모두 짝수 //1 모두 홀수 // 2
//			int total = mm.second.size(); //////*******이줄 문법 문제인듯....
//			cout <<"total"<< total << endl;
//			
//			while (!mm.second.empty())
//			{
//
//				vector<int> now = mm.second.back();
//				mm.second.pop_back();
//				g[mm.first.first][mm.first.second][0] += now[0];
//				g[mm.first.first][mm.first.second][1] += now[1];
//
//			
//				if (nd == 2)continue;
//				if (nd == -1) {
//					if (now[2] % 2 == 0)nd = 0;
//					else { nd = 1; }
//				}
//				else if (nd == 0) {
//					if (now[2] % 2 != 0)nd = 2;
//				}
//				else if (nd == 1) {
//					if (now[2] % 2 == 0)nd = 2;
//				}
//			}
//			if (nm / 5 <= 0)continue;
//			
//			if (nd < 2) {
//				
//				for (int i = 0; i < 4; i++)
//				{
//					i *= 2;
//					int xx = mm.first.first;
//					int yy = mm.first.second;
//					next_xy(xx, yy, false, i );
//					g[xx][yy][0] += nm / 5;
//					g[xx][yy][1] += ns/total;
//					g[xx][yy][2] = i ;
//
//					
//				}
//			}
//			else {
//				for (int i = 1; i <= 4; i++)
//				{
//					i = i * 2 - 1;
//					int xx = mm.first.first;
//					int yy = mm.first.second;
//					next_xy(xx, yy, false, i);
//					g[xx][yy][0] += nm / 5;
//					g[xx][yy][1] += ns / total;
//					g[xx][yy][2] = i;
//				}
//			}
//
//		}
//
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N >> M >> K;
//	int r, c, m, s, d;
//	g = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(3, 0)));
//	visit = vector<vector<int>>(N, vector<int>(N, 0));
//	for (int i = 0; i < M; i++)
//	{
//		cin >> r >> c >> m >> s >> d;
//		g[r - 1][c - 1][0] = m;
//		g[r - 1][c - 1][1] = s;
//		g[r - 1][c - 1][2] = d;
//		visit[r - 1][c - 1]++;
//	}
//
//
//	for (int i = 0; i < K; i++)
//	{
//		cmd();
//	}
//	
//	int ans = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			ans += g[i][j][0];
//		}
//
//	}
//	return 0;
//}