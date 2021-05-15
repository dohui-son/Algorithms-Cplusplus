//#include <iostream>
//#include <algorithm>
//#include <map>
//#include <queue>
//#include<string>
//
//using namespace std;
//#define endl "\n"
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	int N, M;
//	string input;
//	map<int, string> is;
//	map<string, int> si;
//	queue<string> q;
//	cin >> N >> M;
//	for (int i = 1; i < N+1; i++)
//	{
//		cin >> input;
//		is.insert({ i , input });
//		si.insert({ input,i  });
//	}
//	for (int i = 0; i < M; i++)
//	{
//		cin >> input;
//		if (input[0] >= 65)
//		{
//			q.push(to_string(si[input]));
//		}
//		else
//		{
//			q.push(is[stoi(input)]);
//			
//		}
//	}
//	while (!q.empty())
//	{
//		cout << q.front()<<endl;
//		q.pop();
//	}
//	return 0;
//}