//#include <iostream>
//#include <vector>
//#include <map>
//#include <queue>
//
//using namespace std;
//#define endl "\n"
//
//int T;
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> T;
//	int num;
//	string tmp1, tmp2;
//	deque<vector<int>> dq;
//	
//	for (int i = 0; i < T; i++)
//	{
//		
//		map<string, int> ans;
//		cin >> num;
//		for (int j = 0; j < num; j++)
//		{
//			cin >> tmp1 >> tmp2;
//			if (ans.find(tmp2) != ans.end())ans[tmp2]++;
//			else { ans.insert({ tmp2, 1 }); }
//		}
//		
//		dq.push_back({0});
//		
//		for (auto c : ans) dq[i].push_back(c.second);
//		
//
//
//		int answer = 1;
//		for (int j = 1; j < dq[i].size(); j++) answer *= (dq[i][j]+1);
//		
//		dq[i][0] = answer - 1;
//
//	}
//
//	for (int i = 0; i < dq.size(); i++) cout << dq[i][0] << endl;
//	
//
//
//	return 0;
//}