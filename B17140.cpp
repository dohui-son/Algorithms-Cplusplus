//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//
// ///////////////////////디버깅 한번 해보기
////계속 컬럼만 길어짐
//using namespace std;
//#define endl "\n"
//
//int rh=3, ch=3;
//int r=3, c=3, k, ans;
//vector<vector<int>> v(100,vector<int>(100, 0));
//
//
//bool cmp(pair<int, int>& a, pair<int, int>& b) {
//	if (a.second == b.second) return a.first <= b.first;
//	return a.second < b.second;
//}
//
//
//void cal_row() {
//	for (int i = 0; i < ch; i++)
//	{
//		map<int, pair<int, int>> m;
//		int next_total = 0;
//		for (int j = 0; j < rh; j++)
//		{
//			if (v[j][i] == 0)continue;
//			next_total++;
//			if (m.find(v[j][i]) == m.end())m.insert({ v[j][i], make_pair(v[j][i], 1) });
//			else {
//				m[v[j][i]].second++;
//			}
//		}
//		vector<pair<int, int>>sorted;
//		for (auto mm : m)sorted.push_back(mm.second);
//		sort(sorted.begin(), sorted.end(),cmp);
//
//
//		if (rh >= next_total * 2) 
//		{
//			int j = 0;
//			while(j < next_total)
//			{
//				for (auto mm : m)
//				{
//					int k = 0;
//					while (k < mm.second.second) {
//						if (j == 99) {
//							rh = 100;
//							break;
//						}
//						v[j][i] = mm.first;
//						j++;
//						if (j == 99) {
//							rh = 100;
//							break;
//						}
//						v[j][i] = mm.second.second;
//						j++;
//						k++;
//					}
//					if (j == 99) {
//						rh = 100;
//						break;
//					}
//				}
//				if (j == 99) {   //******************8
//					rh = 100;
//					break;
//				}
//			}
//			while (j <100)
//			{
//				v[j][i] = 0;
//				j++;
//			}
//		}
//		else { //rh < next_total * 2
//			int next_rh = 0;
//
//			int j = 0;
//			while(j < next_total*2)
//			{
//				for (auto mm : m) {
//					int k = 0;
//					while (k < mm.second.second)
//					{
//						v[j][i] = mm.first;
//						j++;
//						if (j == 99) {
//							rh = 100;
//							break;
//						}
//						v[j][i] = mm.second.second;
//						j++;
//						if (j == 99) {
//							rh = 100;
//							break;
//						}
//						k++;
//					}
//					if (j == 99) {
//						rh = 100;
//						break;
//					}
//				}
//			}
//			if(j <=99)rh = j+1;
//			while (j < 100)
//			{
//				v[j][i] = 0;
//				j++;
//			}
//		}
//	}
//	
//}
//void cal_col() {
//	for (int i = 0; i < rh; i++)
//	{
//		map<int, pair<int, int>> m;
//		int next_total = 0;
//		for (int j = 0; j < ch; j++)
//		{
//			if (v[i][j] == 0)continue;
//			next_total++;
//			if (m.find(v[i][j]) == m.end())m.insert({ v[i][j], make_pair(v[i][j], 1) });
//			else {
//				m[v[i][j]].second++;
//			}
//		}
//		vector<pair<int, int>>sorted;
//		for (auto mm : m)
//		{
//			sorted.push_back(mm.second);
//		}
//		sort(sorted.begin(), sorted.end(), cmp);
//
//
//		if (ch >= next_total * 2)
//		{
//			int j = 0;
//			while (j < next_total)
//			{
//				for (auto mm : m)
//				{
//					int k = 0;
//					while (k < mm.second.second) {
//						if (j == 99) {
//							ch = 100;
//							break;
//						}
//						v[i][j] = mm.first;
//						j++;
//						if (j == 99) {
//							ch = 100;
//							break;
//						}
//						v[i][j] = mm.second.second;
//						j++;
//						k++;
//					}
//					if (j == 99) {
//						ch = 100;
//						break;
//					}
//				}
//				/*if (j == 99) {   //******************8
//					rh = 100;
//					break;
//				}*/
//			}
//			while (j < 100)
//			{
//				v[i][j] = 0;
//				j++;
//			}
//		}
//		else { //rh < next_total * 2
//			int next_rh = 0;
//
//			int j = 0;
//			while (j < next_total * 2)
//			{
//				for (auto mm : m) {
//					int k = 0;
//					while (k < mm.second.second)
//					{
//						v[i][j] = mm.first;
//						j++;
//						if (j == 99) {
//							ch = 100;
//							break;
//						}
//						v[i][j] = mm.second.second;
//						j++;
//						if (j == 99) {
//							ch = 100;
//							break;
//						}
//						k++;
//					}
//					if (j == 99) {
//						ch = 100;
//						break;
//					}
//				}
//			}
//			if(ch <=99)ch = j + 1;
//			while (j < 100)
//			{
//				v[i][j] = 0;
//				j++;
//			}
//		}
//
//
//
//
//
//
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
//	cin >> r >> c >> k;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cin >> v[i][j];
//		}
//
//	}
//	r -= 1;
//	c -= 1;
//
//	while (v[r][c] != k || ans<100) {
//		if (rh >= 100)rh = 99;
//		if (ch >= 100)ch = 99;
//		if (rh >= ch) {
//			
//			cal_row();
//		}
//		else {
//			
//			cal_col();
//		}
//		
//		ans++;
//	}
//	cout << ans;
//	return 0;
//
//
//}