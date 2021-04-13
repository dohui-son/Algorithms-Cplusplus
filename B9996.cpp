////#include <iostream>
////#include <vector>
////#include <string>
////#include <queue>
////
////using namespace std;
////#define endl "\n"
////
////int main() {
////	ios::sync_with_stdio(false);
////	cin.tie(nullptr);
////	cout.tie(nullptr);
////
////	int num;
////	string str,input;
////	cin >> num>>str;
////	queue<string> q;
////
////	
////	for (int i = 0; i <num; i++)
////	{
////		
////		
////		cin >> input;
////		bool ans = true;
////		int k = 0;
////		while (k< input.size() && k<str.size())
////		{
////			if (str[k] == 42)break;
////			if (input[k] != str[k]) {
////				ans = false;
////				break;
////			}
////			k++;
////		}
////		
////		k = str.size()-1;
////		int j = input.size()-1;
////		while (k>=0 && j>=0)
////		{
////			if (str[k] == '*')break;
////			if (input[j] != str[k] ) { 
////				ans = false; 
////			break; }
////			k--;
////			j--;
////			
////		}
////		if (ans)q.push("DA");
////		else { q.push("NE"); }
////		
////	}
////	while (!q.empty())
////	{
////		cout << q.front() << endl;
////		q.pop();
////	}
////	
////	return 0;
////}
//#include<bits/stdc++.h> 
//using namespace std;
//int n;
//string s, ori_s, pre, suf;
//int main() {
//    cin >> n;
//    cin >> ori_s;
//    int pos = ori_s.find('*');
//    pre = ori_s.substr(0, pos);
//    suf = ori_s.substr(pos + 1);
//    for (int i = 0; i < n; i++) {
//        cin >> s;
//        if (pre.size() + suf.size() > s.size()) {
//            cout << "NE\n";
//        }
//        else {
//            if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
//            else cout << "NE\n";
//        }
//    }
//    return 0;
//}