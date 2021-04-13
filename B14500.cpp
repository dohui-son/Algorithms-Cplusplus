//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//

//성공

//#define endl '\n';
//
//int N, M, max_val; //세로 가로
//int g[501][501];
//void max_tetrimino();
//void shape_check1(int ii, int jj);
//void shape_check2(int ii, int jj);
//void shape_check3(int ii, int jj);
//void shape_check4(int ii, int jj);
//
//
//void shape_check1(int ii, int jj) { //4 11 14 8
//	int co = g[ii][jj] + g[ii + 1][jj] + g[ii + 2][jj];
//	if (max_val < co + g[ii][jj + 1]) max_val = co + g[ii][jj + 1];
//	if (max_val < co + g[ii + 2][jj + 1])max_val = co + g[ii + 2][jj + 1];
//	if (max_val < co + g[ii + 1][jj + 1])max_val = co + g[ii + 1][jj + 1];
//	if (max_val < co - g[ii][jj] + g[ii][jj + 1] + g[ii + 1][jj + 1])max_val = co - g[ii][jj] + g[ii][jj + 1] + g[ii + 1][jj + 1];
//	if (max_val < co - g[ii + 2][jj] + g[ii + 1][jj + 1] + g[ii + 2][jj + 1])max_val = co - g[ii + 2][jj] + g[ii + 1][jj + 1] + g[ii + 2][jj + 1];
//
//}
//
//
//void shape_check2(int ii, int jj) {//6 번도형 13 번도형
//	int co = g[ii][jj + 1] + g[ii + 1][jj + 1] + g[ii + 2][jj + 1];
//	if (max_val < co + g[ii + 2][jj]) max_val = co + g[ii + 2][jj];
//	if (max_val < co + g[ii][jj]) max_val = co + g[ii][jj];
//	if (max_val < co + g[ii + 1][jj])max_val = co + g[ii + 1][jj];
//}
//
//
//void shape_check3(int ii, int jj) { //5 10
//	int co = g[ii][jj] + g[ii][jj + 1] + g[ii][jj + 2];
//	if (max_val < co + g[ii + 1][jj + 2])max_val = co + g[ii + 1][jj + 2];
//	if (max_val < co + g[ii + 1][jj])max_val = co + g[ii + 1][jj]; //5
//	if (max_val < co + g[ii + 1][jj + 1])max_val = co + g[ii + 1][jj + 1]; //10
//
//}
//
//
//void shape_check4(int ii, int jj) { // 7번, 9번, 12번, 15번
//	int co = g[ii + 1][jj] + g[ii + 1][jj + 1] + g[ii + 1][jj + 2];
//	if (max_val < co + g[ii][jj])max_val = co + g[ii][jj];
//	if (max_val < co + g[ii][jj + 2]) max_val = co + g[ii][jj + 2]; //7
//	if (max_val < co + g[ii][jj + 2] + g[ii][jj + 1] - g[ii + 1][jj + 2])max_val = co + g[ii][jj + 2] + g[ii][jj + 1] - g[ii + 1][jj + 2];
//	//9
//	co += g[ii][jj + 1];
//	if (max_val < co)max_val = co; //12
//	if (max_val < co + g[ii][jj] - g[ii + 1][jj])max_val = co + g[ii][jj] - g[ii + 1][jj];
//	// 15
//
//}
//
//
//void max_tetrimino() {
//	int val;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++) {
//
//			
//			if (j + 3 < M) {
//
//				val = g[i][j] + g[i][j + 1] + g[i][j + 2] + g[i][j + 3];
//				if (val > max_val)max_val = val;
//			}
//			if (i + 3 < N) {
//				val = g[i][j] + g[i + 1][j] + g[i + 2][j] + g[i + 3][j];
//				if (val > max_val)max_val = val;
//			}
//			if (i + 1 < N && j + 1 < M) {
//				val = g[i][j] + g[i][j + 1] + g[i + 1][j] + g[i + 1][j + 1];
//				if (val > max_val)max_val = val;
//			}
//			if (i + 2 < N && j + 1 < M) {
//				shape_check1(i, j);
//				shape_check2(i, j);
//			}
//			if (i + 1 < N && j + 2 < M) {
//				shape_check3(i, j);
//				shape_check4(i, j);
//			}
//
//
//
//
//
//		}
//
//	}
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++) {
//			cin >> g[i][j];
//		}
//	}
//
//	max_tetrimino();
//	cout << max_val;
//
//	return 0;
//
//}