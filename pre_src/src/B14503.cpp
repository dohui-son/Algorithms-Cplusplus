//#include <iostream>
//#include <vector>
////성공했지만 많이 찝찝함. 2시간 5분 소요-----------문제이해하기 힘들었음
//using namespace std;
//#define endl "\n";
//
//int N, M, r, c, d;
//int g[51][51];
//int visit[51][51];
//bool finish = false;
//
//int xx[4] = { -1,0,1,0 };
//int yy[4] = { 0,1,0,-1 };
//
//void clean() {
//	visit[r][c] = 1;
//	while (!finish)
//	{
//		for (int dd = 3; dd >= 0; dd--)
//		{
//			
//
//			int dir = (d + dd) % 4;
//			int n_x = xx[dir] + r;
//			int n_y = yy[dir] + c;
//			if (n_x < 0 || n_y < 0 || n_x>N || n_y >M) {//청소할 공간이 없다면 그방향으로 회전하고 2번
//				//왼쪽으로 회전
//				d = dir;
//				dd++;
//				continue;
//			}
//			if (visit[n_x][n_y] == 0 && g[n_x][n_y] != 1) {
//				d = dir;
//				visit[n_x][n_y] = 1;
//				r = n_x;
//				c = n_y;
//				dd=4;
//			}
//			else
//			{
//				
//				int flag = 0;
//				for (int i = 0; i < 4; i++)
//				{
//					if (r + xx[i] < 0 || c + yy[i] < 0 || r + xx[i] >= N || c + yy[i] >= M)continue;
//					if (visit[r + xx[i]][c + yy[i]] == 0 && g[r + xx[i]][c + yy[i]] != 1) {
//						flag = 1;
//						
//						/*r = r + xx[i];
//						c = c + yy[i];
//						continue;*/
//					}
//
//				}
//				if (flag == 0) {
//					//사방이 청소 다되어있거나 벽
//						//후진 못함 + 후진 확인도 못함
//					if (r + xx[(d + 2) % 4] < 0 || r + xx[(d + 2) % 4] >= N || c + yy[(d + 2) % 4] < 0 || c + yy[(d + 2) % 4] >= M)return;
//					if (g[r + xx[(d + 2) % 4]][c + yy[(d + 2) % 4]] == 1)return;//후진못함
//
//					//후진가능
//					r = r + xx[(d + 2) % 4];
//					c = c + yy[(d + 2) % 4];
//					dd++;
//				}
//
//
//
//
//
//
//
//			}
//		}
//
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	cin >> N >> M >> r >> c >> d;
//	
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++) {
//			cin >> g[i][j];
//		}
//
//	}
//	clean();
//	int ans = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++) {
//			if (visit[i][j] == 1)ans++;
//		}
//
//	}
//
//	cout << ans;
//
//
//
//
//
//
//	return 0;
//}