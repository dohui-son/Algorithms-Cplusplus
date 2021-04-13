//#include<iostream>
//#include<vector>
//#include<deque>
//
//해결
//using namespace std;
//#define endl "\n";
//
//int N, ans = 0;
//
//vector<vector<bool>> visit(102, vector<bool>(102, false));
//int yy[4] = { 0,-1,0,1 };
//int xx[4] = { 1,0,-1,0 };
//
//void square_chk(int yy) {
//	for (int i = 0; i < 102; i++)
//	{
//		if ((i + 1) >= 102 || (yy + 1) >= 102)continue;
//		if (visit[yy][i] == true && visit[yy][i + 1] == true && visit[yy + 1][i] == true && visit[yy + 1][i + 1] == true)ans++;
//	}
//}
//
//void dragon_curve(int x, int y, int d, int g) {
//	deque<int>dq;
//
//
//	for (int i = 0; i <= g; i++)
//	{
//		if (i == 0) {
//
//			dq.push_back(d);
//			int ny = y + yy[d];
//			int nx = x + xx[d];
//			if (ny >= 0 && nx >= 0 && ny < 102 && nx < 102) {
//				visit[ny][nx] = true;
//				y = ny;
//				x = nx;
//			}
//
//		}
//
//		else {
//			int j = dq.size() - 1;//계산 0 /1 /2/ 2/ 3/ 3/ 3/3 이렇게 디큐에 들어가있음
//
//
//			for (int k = j; k >= 0; k--) // 계산 필요
//			{
//				dq.push_back((dq[k] + 1) % 4);
//				int ny = y + yy[(dq[k] + 1) % 4];
//				int nx = x + xx[(dq[k] + 1) % 4];
//				if (ny < 0 || nx < 0 || ny >= 102 || nx >= 102)continue;
//				visit[ny][nx] = true;
//				y = ny;
//				x = nx;
//			}
//
//		}
//
//	}
//
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//
//	cin >> N;
//	int tmpx, tmpy, tmpd, tmpg;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> tmpx >> tmpy >> tmpd >> tmpg;
//		dragon_curve(tmpx, tmpy, tmpd, tmpg);
//		visit[tmpy][tmpx] = true;
//
//
//	
//
//	}
//	for (int i = 0; i < 102; i++)
//	{
//		square_chk(i);
//
//	}
//
//
//	cout << ans;
//
//
//	return 0;
//}