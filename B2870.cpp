//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//#define endl "\n";
//int N;
//vector<string> str;
//vector<int> num;
//
//void solution() {
//
//	for (int i = 0; i < str.size(); i++)
//	{
//		
//		for (int j = 0; j < str[i].size(); j++)
//		{
//			string s;
//			while (str[i][j] < 96 && j < str[i].size())
//			{
//				
//				s += str[i][j];
//				j++;
//			}
//			
//			if (!s.empty())num.push_back(stoi(s));
//			
//		}
//	}
//	
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N;
//	
//	string tmp;
//	for (int i = 0; i < N; i++) {
//		cin >> tmp;
//		str.push_back(tmp);
//		
//	}
//	solution();
//	if (!num.empty()) {
//		sort(num.begin(), num.end());
//		for (auto n : num)cout << n << endl;
//	}
//
//	return 0;
//
//}