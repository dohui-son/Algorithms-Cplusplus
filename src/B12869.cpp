//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//#define endl "\n"
//const int INF = 987654321;
//vector<vector<vector<int>>> memo(61,vector<vector<int>>(61,vector<int>(61,-1)));
//
//int scvThree(int a, int b, int c) {
//	if (a < 0)return scvThree(0, b, c);
//	if (b < 0)return scvThree(a, 0, c);
//	if (c < 0)return scvThree(a, b, 0);
//	if (a == 0 && b == 0 && c == 0)return 0;
//
//	int& ret = memo[a][b][c];
//	if (ret != -1)return ret;
//
//	ret = INF;
//	ret = min(ret, scvThree(a - 9, b - 3, c - 1) + 1);
//	ret = min(ret, scvThree(a - 9, b - 1, c - 3) + 1);
//
//	ret = min(ret, scvThree(a - 1, b - 9, c - 3) + 1);
//	ret = min(ret, scvThree(a - 1, b - 3, c - 9) + 1);
//
//	ret = min(ret, scvThree(a - 3, b - 9, c - 1) + 1);
//	ret = min(ret, scvThree(a - 3, b - 1, c - 9) + 1);
//
//	return ret;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	int N = 0;
//	int input[3] = { 0, };
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> input[i];
//	}
//
//	cout << scvThree(input[0], input[1], input[2]);
//	
//
//
//	return 0;
//}