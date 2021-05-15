//#include <iostream>//샘코드보기---성공
//#include <vector>
//#include <map>;
//#include <string>
//#include <queue>
//using namespace std;
//#define endl "\n"
//string str;
//queue<bool> ans;
//deque<string> input;
//map<char, char> m;
//
//void solution() {
//
//	int flag = 0;
//
//	for (int i = 0; i < input.size(); i++)
//	{
//		flag = 0;
//		string str2;
//		for (int j = 0; j < input[i].size() - 1; j++)
//		{
//			str2 += m[input[i][j]];
//			if (input[i].size() > 1 && input[i][j] == input[i][j + 1] && input[i][j] != 'e' && input[i][j] != 'o') {
//				flag = 1;
//				ans.push(false);
//				break;
//			}
//		}
//		str2 += m[input[i][input[i].size() - 1]];
//		if (flag == 0) {
//			if (str2.find("1") == -1) { 
//				ans.push(false);
//			}
//			else {
//				if (str2.size() >= 3) {
//
//					if ( str2.find("000") == -1 && str2.find("111") == -1) {
//						ans.push(true);
//					
//						continue;
//					}
//					else {
//						ans.push(false);
//					
//						continue;
//					}
//				}
//				ans.push(true);
//
//			}
//		}
//		
//
//	}
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	while (cin >> str) {
//
//		if (str == "end")break;
//		input.push_back(str);
//		
//	}
//	//a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
//	m.insert({ 'a','1' }); m.insert({ 'b','0' }); m.insert({ 'c','0' });
//	m.insert({ 'd','0' }); m.insert({ 'e','1' }); m.insert({ 'f','0' });
//	m.insert({ 'g','0' }); m.insert({ 'h','0' }); m.insert({ 'i','1' });
//	m.insert({ 'j','0' }); m.insert({ 'k','0' }); m.insert({ 'l','0' });
//	m.insert({ 'm','0' }); m.insert({ 'n','0' }); m.insert({ 'o','1' });
//	m.insert({ 'p','0' }); m.insert({ 'q','0' }); m.insert({ 'r','0' });
//	m.insert({ 's','0' }); m.insert({ 't','0' }); m.insert({ 'u','1' });
//	m.insert({ 'v','0' }); m.insert({ 'w','0' }); m.insert({ 'x','0' });
//	m.insert({ 'y','0' }); m.insert({ 'z','0' });
//	solution();
//
//	int idx = 0;
//	while (!ans.empty())
//	{
//		cout << "<" << input[idx] << "> is ";
//		if (ans.front()) {//true;
//			cout << "acceptable." << endl;
//		}
//		else { cout << "not acceptable." << endl; }
//		ans.pop();
//		idx++;
//	}
//
//
//
//	return 0;
//}