//#include<iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//#define endl '\n'
//
//int n, ret = -987654321;
//string s;
//vector<int> num;
//vector<char> oper;
//
//int cal(char a, int b, int c) {
//	if (a == '+')return b + c;
//	if (a == '-')return b - c;
//	if (a == '*')return b * c;
//}
//
//void go(int idx, int pre_res) {
//	if (idx == num.size() - 1) {
//		ret = max(ret, pre_res);
//		return;
//	}
//	go(idx + 1, cal(oper[idx], pre_res, num[idx + 1]));
//
//	if (idx + 2 <= num.size() - 1) {
//		int tmp = cal(oper[idx + 1], num[idx + 1], num[idx + 2]);
//		go(idx + 2, cal(oper[idx], pre_res, tmp));
//	}
//	return;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr); cout.tie(nullptr);
//	cin >> n >> s;
//	for (int i = 0; i < n; i++)
//	{
//		if (i % 2 == 0)num.push_back(s[i] - '0');
//		else oper.push_back(s[i]);
//	}
//
//	go(0, num[0]);
//	cout << ret;
//
//
//
//	return 0;
//}
