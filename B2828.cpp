////실패
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//
//using namespace std;
//
//#define endl "\n";
//int N, M, J;
//int j[22];
//int ans = 90000;
//
//
//void drop_apple(int mst) { //1이 처음사과를 첫칸에 담는 경우의 수
//	int loc = -1;
//	int times = 0;
//	for (int i = 0; i < J; i++)
//	{
//		if (loc == -1)loc = j[i];
//		else {
//			if (j[i] <= loc + M - mst && j[i] >= loc - mst+1)continue; // 안움직여도 담을 수 있음
//			if (j[i] > loc + M - mst) { 
//				times += (j[i] - (loc + M - mst));
//				loc += (j[i] - (loc + M - mst));
//			}
//			else if(j[i] < loc-mst+1 ){
//				times += (loc - mst + 1 - j[i]);
//				loc -= (loc-mst + 1 - j[i]);
//			}
//		}
//	}
//	ans = min(ans, times);
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N >> M >> J;
//	for (int i = 0; i < J; i++)
//	{
//		cin >> j[i];
//	}
//	for (int i = 1; i <= M; i++)
//	{
//		drop_apple(i);
//	}
//	cout << ans;
//
//	
//
//	return 0;
//}