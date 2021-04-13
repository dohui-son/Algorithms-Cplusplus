//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//#define endl "\n"
//int h[9];
//vector<int> v;
////순열 do while(오름차순, 내림차순) 각각 암기!
//
//void go(int next) {
//	if (v.size() == 7){
//		int tmp = 0;
//		for (int i = 0; i < 7; i++)tmp += v[i];
//		
//		if (tmp == 100) {
//			sort(v.begin(), v.end());
//			for (int i = 0; i < 7; i++) cout << v[i] << endl;
//			exit(0);
//		}
//	}
//	for (int i = next; i < 9; i++)
//	{
//		v.push_back(h[i]);
//		go(next + 1);
//		v.pop_back();
//	}
//}
//
//
//int main() {
//
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//	/*for (int i = 0; i < 9; i++)cin >> h[i];
//	do {
//		int tmp = 0;
//		for (int i = 0; i < 7; i++) tmp += h[i];
//		if (tmp == 100)
//		{
//			sort(h, h + 7);
//			for (int i = 0; i < 7; i++) cout << h[i] << endl;
//			break;
//		}
//	} while (prev_permutation(h, h+9)); */
//	for (int i = 0; i < 9; i++) cin >> h[i];
//	
//	go(0);
//
//	return 0;
//}