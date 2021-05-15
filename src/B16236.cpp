//#include <iostream>
//#include <vector>
//#include <queue>
//

//¼º°ø

//using namespace std;
//#define endl "\n"
//int N, sx, sy, ss = 2,eaten =0;
//vector<vector<int>>g;
//int dx[4] = { -1,0,0,1 };
//int dy[4] = { 0,-1,1,0 };
//int tmp = 0;
//
//
//void eat(int& xx, int& yy) {
//	eaten++;
//	if (eaten == ss) {
//		ss++;
//		eaten = 0;
//	}
//	
//	g[xx][yy] = 0;
//	sx = xx;
//	sy = yy;
//}
//
//
//bool nearest(int& ffx, int& ffy, int& ll) {
//	
//	queue<vector<int>>q;
//	vector<vector<int>>visit(20, vector<int>(20, 0));
//	int flag = 1;
//	q.push({ sx, sy, 0 });
//	visit[sx][sy] = 1;
//	ll = 9999999;
//	while (!q.empty())
//	{
//		vector<int> now = q.front();
//		int x = now[0];
//		int y = now[1];
//		int much = now[2];
//		
//		q.pop();
//		
//		if (g[x][y] > 0 && g[x][y] < ss) {
//			flag = 0;
//			if (much < ll) {
//				ffx = x;
//				ffy = y;
//				ll = much;
//			}
//			else if (much == ll) {
//				if (x < ffx) {
//					ffx = x;
//					ffy = y;
//					ll = much;
//				}
//				else if (x == ffx && y <ffy) {
//					ffx = x;
//					ffy = y;
//					ll = much;
//				}
//			}
//		
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
//			if (g[nx][ny] > ss || visit[nx][ny] !=0 )continue;
//			
//			visit[nx][ny] = 1;
//			q.push({ nx, ny, much+1 });
//			
//	
//		}
//		
//	
//	}
//	
//	if(flag ==1)return false;
//	return true;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N;
//	N;
//	g = vector<vector<int>>(20, vector<int>(20, 0));
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++) {
//			cin >> g[i][j];
//			if (g[i][j] == 9) {
//				sx = i;
//				sy = j;
//				g[i][j] = 0;
//			}
//		}
//	}
//	int ans=0, fx, fy, l=0;
//
//	bool go = nearest(fx, fy, l);
//
//	while(go)
//	{
//		
//		eat(fx,fy);
//	
//		
//		ans += l;
//		
//		
//		go = nearest(fx, fy, l);
//	}
//
//
//	cout << ans;
//	return 0;
//
//}