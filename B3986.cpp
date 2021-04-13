//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//
//using namespace std;
//#define endl "\n"
//int N;
//vector<int> vect(100);
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	
//	string str;
//	
//	queue<int> q;
//	char c;
//	int ans = 0;
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> str;
//		stack<int> st;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (st.empty()) { st.push(str[i]); }
//			else if (st.top() == str[i]) 
//			{
//				st.pop();
//			}
//			else {
//				st.push(str[i]);
//			}
//		}
//		if (st.empty())ans++;
//		
//	}
//	cout << ans;
//
//	return 0;
//}