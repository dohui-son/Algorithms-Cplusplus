//#include <iostream>
//#include <vector>
//
//using namespace std;
//#define endl "\n";
//int64_t N, ans = 0, B,C;
//vector<int64_t> A;
//
//
//
//void count_dir(int dir_idx) {
//	
//	
//	A[dir_idx] -= B;
//	ans++;
//
//	if (A[dir_idx] <= 0) return;
//	else {
//		if (A[dir_idx] <= C) {
//			ans ++;
//			return;
//		}
//		if (A[dir_idx] % C == 0)ans =ans+ (A[dir_idx] / C);
//		else
//		{
//			ans =ans+ (A[dir_idx] / C) + 1;
//		}
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
//	cin >> N;
//	A = vector<int64_t>(N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> A[i];
//		
//	}
//	cin >> B >> C;
//
//	for (int i = 0; i < N; i++)count_dir(i);
//	
//
//	cout << ans;
//
//	return 0;
//}
//
