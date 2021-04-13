//#include <iostream>
//#include <vector>
//#include <deque>
//
//using namespace std;
//#define endl "\n"
//
//int64_t N, M;
//deque<int64_t>dq;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> N >> M;
//	int64_t tmp = 0;
//	
//	for (int i = 0; i < N; i++)
//	{
//		cin >> tmp;
//		dq.push_back(tmp);
//		
//	}
//	int ans = 0;
//	for (int i = 0; i < dq.size(); i++)
//	{
//		if (dq[i] == -1)continue;
//		for (int j = i+1; j < dq.size(); j++)
//		{
//			if (dq[j] == -1)continue;
//			if (dq[i] + dq[j] == M) {
//				ans++;
//				dq[j] = -1;
//			}
//		}
//	}
//	cout << ans;
//	return 0;
//}
