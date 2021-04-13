////다시풀어야함
//#include <iostream>
//#include <vector>
//#include <map>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//#define endl "\n"
//
//int N,team, mm, ss;
//vector<pair<int, int>> for_sort;
//map<pair<int, int>, int> m;
//pair<int, int>t1,t2;
//bool cmp(pair<int, int>& a, pair<int, int>& b) {
//	if (a.first == b.first)return a.second < b.second;
//	return a.first < b.first;
//	
//}
//
//
//pair<int,int> cal_time(pair<int, int>first, pair<int, int> second) {
//	second.second -= first.second;
//	if (second.second < 0) {
//		second.first--;
//		second.second += 60;
//	}
//	second.first -= first.first;
//	return second;
//}
//void sum_time(pair<int, int> m_s) {
//	if (m_s.second / 60 > 0) {
//		m_s.first += (m_s.second / 60);
//		m_s.second %= 60;
//	}
//	if (m_s.first < 10)cout << 0;
//	cout << m_s.first << ":";
//	if (m_s.second < 10)cout << 0;
//	cout << m_s.second << endl;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N;
//	string str;
//	
//	for (int i = 0; i < N; i++)
//	{
//		cin >> team >> str;
//		mm = stoi(str.substr(0, 2));
//		ss = stoi(str.substr(3, 4));
//		m.insert({ {mm,ss},team });
//		for_sort.push_back({ mm,ss });
//	}
//	sort(for_sort.begin(), for_sort.end(), cmp);
//
//	//for (auto a : for_sort)cout << a.first << "---" << a.second << endl;
//	int t = m[for_sort[0]];
//	pair<int, int> now = for_sort[0];
//	for (int i = 1; i < for_sort.size(); i++)
//	{
//		if (i == for_sort.size())break;
//		//pair<int, int>next = {-1,-1};
//		while (m[for_sort[i]] == t && i < N) {
//			//next = for_sort[i];
//			i++;
//		}
//		if (i == for_sort.size())break;
//		if (t == 1) {
//			pair<int,int>res = cal_time(now, for_sort[i]);
//			t1.first += res.first;
//			t1.second += res.second;
//		}
//		if (t == 2) {
//			pair<int, int>res = cal_time(now, for_sort[i]);
//			t2.first += res.first;
//			t2.second += res.second;
//		}
//		now = for_sort[i];
//		t = m[for_sort[i]];
//	}
//	sum_time(t1);
//	sum_time(t2);
//
//
//
//	return 0;
//}