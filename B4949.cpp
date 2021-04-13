//#include <iostream>
//#include <string>
//#include <stack>
//#include <vector>
//
//using namespace std;
//#define endl "\n"
//string str;
//vector<bool> ans;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	while (getline(cin,str)) {
//		if (str[0] == '.' && str.size() == 1)break;
//
//		stack<char> st;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] == '(' || str[i] == '[')st.push(str[i]);
//			if (str[i] == ')' || str[i] == ']') {
//				if (st.empty()) {
//					st.push(str[i]);
//					break;
//				}
//				else {
//					if (st.top() == '(' && str[i] ==')')st.pop();
//					else if(st.top() == '[' && str[i] == ']')st.pop();
//				}
//			}
//		}
//		if (st.empty())ans.push_back(true);
//		else ans.push_back(false);
//	}
//
//	for (bool i : ans) {
//		if (i)cout << "yes" << endl;
//		else cout << "no" << endl;
//	}
//
//	return 0;
//
//}