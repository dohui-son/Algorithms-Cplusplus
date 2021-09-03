//#include<iostream>
//#include <vector>
//#include<algorithm>
//#include <queue>
//
//using namespace std;
//#define endl "\n";
//int n, ans = 987654321;
//vector<vector<int>> g(12, vector<int>(12));
////3중 for문은 가능한한 지양해야함
//vector<vector<bool>> visit(12, vector<bool>(12, false));
//int dy[4] = { -1,0,1,0 };
//int dx[4] = { 0,-1,0,1 };
//
//bool can_flower(int y, int x) {
//	if (visit[y][x])return false;
//	for (int i = 0; i < 4; i++)
//	{
//		if (visit[y + dy[i]][x + dx[i]])return false;
//	}
//	return true;
//}
//int set_f(int y, int x) {
//	//price를 리턴
//	int ret = g[y][x];
//	visit[y][x] = true;
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		visit[ny][nx] = true;
//		ret += g[ny][nx];
//	}
//	return ret;
//}
//void erase(int y, int x) {
//	visit[y][x] = false;
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		visit[ny][nx] = false;
//	}
//}
//
//void go(int cnt,int sy,int sx, int price ) {
//	if (cnt == 3) 
//	{
//		ans = min(ans, price);
//		return ;
//	}
//	int j = sx;
//	for (int i = sy; i < n-1; i++)
//	{
//		for (; j < n-1; j++)
//		{
//			if (visit[i][j] == true)continue;
//			if (can_flower(i, j)) {
//				int to_sum = set_f(i,j);
//				go(cnt+1, i,j+1, price+to_sum);
//				erase(i,j);
//			}
//		}
//		j = 1;
//
//	}
//
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> g[i][j];
//		}
//	}
//
//	go(0, 1, 1, 0);
//	cout << ans;
//
//
//
//	return 0;
//}
