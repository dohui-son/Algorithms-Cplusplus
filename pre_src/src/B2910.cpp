//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//#define endl "\n"
//map<int64_t, int64_t> freq;
//map<int64_t, int64_t>first_idx;
//int64_t N, C;
//
//
//bool cmp(pair<int64_t, int64_t>& a, pair<int64_t, int64_t>& b) {
//	if (b.second < a.second) return true;
//	else if (b.second > a.second)return false;
//	else if (b.second == a.second)return first_idx[b.first] > first_idx[a.first];
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> N >> C;
//	int64_t num = 0;
//	for (int64_t i = 0; i < N; i++)
//	{
//		cin >> num;
//		if (freq.find(num) != freq.end())freq[num]++;
//		else {
//			freq.insert({ num,1 });
//			first_idx.insert({ num, i });
//		}
//	}
//	vector<pair<int64_t, int64_t>> ans;
//	for (auto m : freq) {
//		ans.push_back({ m.first, m.second });
//	}
//	sort(ans.begin(), ans.end(), cmp);
//	for (auto a : ans) {
//		int64_t tmp = a.second;
//		while (tmp != 0) {
//			cout << a.first << " ";
//			tmp--;
//		}
//	}
//
//
//
//
//
//	return 0;
//}