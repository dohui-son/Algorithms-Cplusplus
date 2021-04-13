//#include<iostream> // 실패 백준2636치즈
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//#define endl "\n"
//int C, R, times, rest;
//vector<vector<int>>g(102, vector<int>(102, 0));
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//
//
//void melt(vector<vector<int>>&gg) {
//	while (1) {
//		queue<pair<int, int>>q;
//		vector<vector<int>>visit(102, vector<int>(102, 0));
//		
//		int tmp=0;
//		
//		
//		for (int i = 0; i < R; i++)
//		{
//			for (int j = 0; j < C; j++)
//			{
//				if (g[i][j] == 0 && visit[i][j] == 0) {
//					
//					
//					
//						for (int k = 0; k < 4; k++) {
//							int nx = dx[k] + i;
//							int ny = dy[k] + j;
//							if (nx > 0 || ny > 0 || nx >= R || ny >= C)continue;
//
//							if (gg[nx][ny] == 1 && visit[nx][ny] != 1) {
//								gg[nx][ny] = 0;
//								visit[nx][ny] = 1;
//								tmp++;
//						}
//					}
//				}
//
//			}
//		}
//		if (tmp != 0) {
//			rest = tmp;
//			times++;
//		}
//		if (tmp == 0)return;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> C >> R;
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			cin >> g[i][j];
//			if (g[i][j] == 1)rest++;
//		}
//	}
//	melt(g);
//	cout << times << endl;
//	cout << rest << endl;
//
//
//	return 0;
//}