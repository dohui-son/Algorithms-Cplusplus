//#include <iostream>
//#include <vector>
//#include <deque>
//#include <queue>
//#include <map>
//
//using namespace std;
//#define endl "\n"
//
//int N, H, M;
//vector<vector<int>> ladder(30, vector<int>(10,-1));
//deque<pair<int, int>>dq;
//
//
//bool play() {
//	for (int i = 0; i < N; i++)
//	{
//		int xx = i;
//		
//		for (int j = 0; j < H; j++)
//		{
//			if (ladder[j][xx] != -1) 
//			{
//				xx = ladder[j][xx];
//			}
//		}
//		if (xx != i) { return false; }
//
//	}
//	return true;
//	
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	map<pair<int,int>, int> exclude;
//	cin >> N >> M >> H;
//	
//	int a, b;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b;
//		ladder[a - 1][b - 1] = b;
//		ladder[a - 1][b] = b - 1;
//		exclude.insert({ make_pair(a - 1,b - 1),-1 });
//		exclude.insert({ make_pair(a - 1,b),-1 });
//		
//	}
//	
//	if (play() == true) {
//		cout << 0;
//		exit(0);
//	}
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < N-1; j++)
//		{
//			if (exclude.find({ i,j }) != exclude.end())continue;
//			if (exclude.find({ i,j+1 }) != exclude.end())continue;
//			dq.push_back(make_pair(i, j));
//		}
//	}
//	
//	for (int i = 0; i < dq.size(); i++)
//	{
//		pair<int, int> now = dq[i];
//
//		ladder[now.first][now.second] = now.second + 1;
//		ladder[now.first][now.second+1] = now.second;
//		if (play()) {
//			cout << 1;
//			exit(0);
//		}
//		ladder[now.first][now.second] = -1;
//		ladder[now.first][now.second + 1] = -1;
//	}
//
//	pair<int, int> f,s,t;
//	for (int i = 0; i < dq.size(); i++)
//	{
//		f = dq[i];
//		for (int j = i+1; j < dq.size(); j++)
//		{
//			s = dq[j];
//
//			ladder[f.first][f.second] = f.second + 1;
//			ladder[f.first][f.second+1] = f.second;
//			ladder[s.first][s.second] = s.second + 1;
//			ladder[s.first][s.second+1] = s.second;
//			if (play()) {
//				cout << 2;
//				exit(0);
//			}
//			ladder[f.first][f.second] = -1;
//			ladder[f.first][f.second+1] = -1;
//			ladder[s.first][s.second] = -1;
//			ladder[s.first][s.second+1] = -1;
//		}
//	}
//
//	for (int i = 0; i < dq.size(); i++)
//	{
//		f = dq[i];
//		for (int j = i+1; j < dq.size(); j++)
//		{
//			s = dq[j];
//			for (int k = j+1; k < dq.size(); k++)
//			{
//				t = dq[k];
//
//				ladder[f.first][f.second] = f.second + 1;
//				ladder[f.first][f.second+1] = f.second;
//				ladder[s.first][s.second] = s.second + 1;
//				ladder[s.first][s.second+1] = s.second;
//				ladder[t.first][t.second] = t.second + 1;
//				ladder[t.first][t.second+1] = t.second;
//				if (play()) {
//					cout << 3;
//					exit(0);
//				}
//				ladder[f.first][f.second] = -1;
//				ladder[f.first][f.second+1] = -1;
//				ladder[s.first][s.second] = -1;
//				ladder[s.first][s.second+1] = -1;
//				ladder[t.first][t.second] = -1;
//				ladder[t.first][t.second+1] = -1;
//
//			}
//		}
//	}
//
//	cout << -1;
//
//	return 0;
//}
//
