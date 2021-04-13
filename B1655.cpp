////실패 (코드는 맞은 코드)
////아이디어만 보지 말고 코드도 꼭 보기
////항상 mid가 left의 top이 mid 인 방식
////핵심 !!!!!left와 right라는 큐를 두개 운영한다
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//#define endl "\n";
//
//vector<int>ans;
//priority_queue<int> l;
//priority_queue<int,vector<int>,greater<int>> r;
//int N;
//
//void mid(int new_num) {
//	if (l.empty() && r.empty())l.push(new_num);
//	else if (l.top() < new_num) //
//	{
//		r.push(new_num);
//		if (r.size() > l.size()) {
//			
//				l.push(r.top());
//				r.pop();
//		}
//	}
//	else if (l.top() >= new_num) {
//		l.push(new_num);
//		if (l.size() - r.size() == 2) {
//			
//				r.push(l.top());
//				l.pop();
//		}
//	}
//	ans.push_back(l.top());
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//	cin >> N;
//	int input;
//	
//	for (int i = 0; i < N; i++)
//	{
//		cin >> input;
//		mid(input);
//	}
//	for (int k : ans)cout << k << endl;
//	return 0;
//}