//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//#define endl "\n"
//int N, K;	//(1) 슬라이딩 윈도우
//int vect[100000] = {0,};
//int ans = 0, input = 0, pre = 0, ret = -10000000;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	
//	cin >> N >> K;
//	
//	for (int i = 0; i < N; i++)
//	{
//		cin >> input;
//		vect[i] = input;
//		if (i < K) {
//			ans += input;
//			ret = ans;
//		}
//		else {
//			ans = ans + input - vect[i - K];
//			ret = max(ret, ans);
//		}
//	}
//	cout << ret;
//
//
//
//	return 0;
//}
//
////#include <iostream>  //(2)맞은 답, psum
////#include <vector>
////#include <algorithm>
////
////using namespace std;
////#define endl "\n"
////
////int main() {
////	ios::sync_with_stdio(false);
////	cin.tie(nullptr);
////	cout.tie(nullptr);
////	
////	int N, K;
////	cin >> N >> K;
////	vector<int> input(N+1, 0);
////	vector<int>ps(N+1,0);
////	vector<int>ans;
////	for (int i = 1; i < N+1; i++)
////	{
////		cin >> input[i];
////		ps[i] = ps[i - 1] + input[i];
////	}
////	for (int i = N; i >= 0; i--)
////	{
////		if (i - K < 0)break;
////		ans.push_back(ps[i] - ps[i - K]);
////
////	}
////	cout << *max_element(ans.begin(), ans.end());
////
////	return 0;
////}