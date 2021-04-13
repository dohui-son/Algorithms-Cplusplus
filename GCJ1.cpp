//#include <iostream>
//#include <vector>
//#include <queue>
//#include<algorithm>
//
//using namespace std;
//#define endl "\n"
//
//int T, N;
//
//
//bool is_sorted(vector<int>& vect) {
//	vector<>
//	for (int i = 0; i < vect.size(); i++)
//	{
//
//	}
//}
//
//int rever(vector<int>& v) {
//	int ret = 0;
//	int i = 0;
//	while (next_permutation(v.begin(), v.end()))
//	{
//		
//		if (i == v.size())break;
//
//		
//		
//		int tmp = v[i];
//		if (tmp > *min_element(v.begin() + 1 + i, v.end())) {
//			for (auto vv : v)cout << vv << " ||";
//			v[i] = *min_element(v.begin() + 1 + i, v.end());
//			for (auto vv : v)cout << vv << " |";
//			v[min_element(v.begin() + 1 + i, v.end()) - (v.begin()+1+i)] = tmp;
//			cout << "-----------------";
//			//cout << v[min_element(v.begin() + 1 + i, v.end()) - v.begin()] << endl;
//			//for (auto vv : v)cout << vv << "  ";
//		}
//		
//
//		i++;
//		ret++;
//	}
//
//	return ret;
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	queue<int> q;
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		vector<int> L;
//		cin >> N;
//		int tmp = 0;
//		for (int j = 0; j < N; j++)
//		{
//			cin >> tmp;
//			L.push_back(tmp);
//		}
//		q.push(rever(L));
//
//	}
//	int i = 1;
//	while (!q.empty())
//	{
//		cout << "Case #" << i << ": " << q.front()<<endl;
//		q.pop();
//	}
//
//
//
//	return 0;
//}