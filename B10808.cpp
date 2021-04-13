//#include <iostream>
//#include <string>
//#include <map>
//
//using namespace std;
//
//#define endl "\n";
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//	string s;
//	char c[28] = "abcdefghijklmnopqrstuvwxynz";
//	int ans[26] = { 0, };
//	map<char, int> _map;
//	
//	for (int i = 0; i < 27; i++)_map.insert({ c[i], 0 });
//	cin >> s;
//	for (int i = 0; i < s.size(); i++)_map[s[i]]++;
//	for (auto c : _map)cout << c.second << " ";
//
//
//	return 0;
//
//}