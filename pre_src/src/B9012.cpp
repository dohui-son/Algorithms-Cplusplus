//#include <iostream>
//#include <vector>
//#include<stack>
//#include <string>
//#include <queue>
//
//using namespace std;
//#define endl "\n";
//int N;
//string str;
//queue<string> input;
//queue<bool> ans;
//
//void sol() {
//	while (!input.empty())
//	{
//		stack<char> st;
//		string now = input.front();
//		input.pop();
//
//		//1번 문제임에도 코드가 지저분하면 한번 검토필요
//		for (int i = 0; i < now.size(); i++)
//		{
//			
//			if(now[i] == '(') { 
//				st.push(now[i]); 
//			}
//			else if (now[i] == ')' )
//			{
//				if (st.size() >0)
//				{
//					st.pop();
//				}
//				else {
//					st.push(now[i]);
//					break;
//				}
//			}
//		}
//		if (st.empty())ans.push(true);
//		else ans.push(false);
//
//
//
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> str;
//		input.push(str);
//	}
//
//	sol();
//	while (ans.size())
//	{
//		if (ans.front()) { cout << "YES" << endl; }
//		else cout << "NO" << endl;
//		ans.pop();
//	}
//
//
//
//	return 0;
//}
