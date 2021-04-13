////¼º°ø
//#include <iostream>
//#include <vector>
//#include <deque>
//
//using namespace std;
//#define endl "\n";
//
//int N, K,ans;
//deque <int> upper, lower, robot;
//void play();
//void convey();
//void processing_robot(int& kk);
//
//void processing_robot(int& kk) {
//	if (ans == 0 && upper[0]>0) {
//
//		robot[0] = 1;
//		upper[0]--;
//		if (upper[0] == 0)kk++;
//	}
//	else {
//		robot[N - 1]=0;
//		for (int i = N-2; i >= 0 ; i--)
//		{
//			if (robot[i] != 0 && upper[i + 1] > 0 && robot[i+1] == 0) {
//				robot[i + 1]++;
//				robot[i]--;
//				--upper[i + 1];
//				if (upper[i + 1] == 0) kk++;
//			}
//		}
//		if (robot.front() == 0 &&upper[0]>0) {
//			robot[0] = 1;
//			upper[0]--;
//			if (upper[0] == 0)kk++;
//		}
//	}
//
//
//}
//
//
//
//void convey() 
//{
//	robot.pop_back();
//	int tmp = upper.back();
//	upper.pop_back();
//	lower.push_back(tmp);
//
//	tmp = lower.front();
//	lower.pop_front();
//	upper.push_front(tmp);
//	robot.push_front(0);
//}
//
//void play() {
//	int durability=0;
//	
//	while (durability < K) {
//		convey();
//		processing_robot(durability);
//
//
//		ans++;
//
//	}
//
//
//
//
//
//
//	
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	cin >> N >> K;
//	int input;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> input;
//		upper.push_back(input);
//		robot.push_back(0);
//	}
//	for (int i = 0; i < N; i++)
//	{
//		cin >> input;
//		lower.push_front(input);
//
//	}
//
//	play();
//	cout << ans;
//
//
//
//	return 0;
//}