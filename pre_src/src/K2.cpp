//#include <bits/stdc++.h>
//#include <iostream>
//
//using namespace std;
//vector<vector<string>> p= vector<vector<string>>(5,vector<string>(5,"00000"));
//
//
////int dx[8] = {0,1,1,1,0,-1,-1,-1};
////int dy[8] = {-1,-1,0,1,1,1,0,-1};
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { -1,0,1,0 };
//
//bool BFS(vector<string>& g, vector<vector<bool>>& vis, int y, int x) {
//	queue<pair<int, int>> q;
//	vector<vector<bool>>v(5, vector<bool>(5, false));
//	v[y][x] = true;
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = dy[i] + y;
//		int nx = dx[i] + x;
//
//		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)continue;
//		v[ny][nx] = true;
//		if (g[ny][nx] == 'X') continue;
//		if (g[ny][nx] == 'P')return false;
//		q.push({ ny,nx });
//	}
//	while (!q.empty())
//	{
//		pair<int, int>now = q.front(); q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int ny = dy[i] + now.first;
//			int nx = dx[i] + now.second;
//
//			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)continue;
//			v[ny][nx] = true;
//			if (v[ny][nx])continue;
//
//			if (g[ny][nx] == 'P')return false;
//
//		}
//
//	}
//	return true;
//
//}
//
//int sol(vector<string>& pp) {
//	vector<vector<bool>>visit(5, vector<bool>(5, false));
//	//pp[i][j]
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			if (pp[i][j] == 'P') {
//				if (!BFS(pp, visit, i, j))return 0;
//			}
//		}
//
//	}
//	return 1;
//
//}
//
//vector<int> solution(vector<vector<string>> places) {
//	vector<int> answer;
//	for (int i = 0; i < 5; i++)
//	{
//		answer.push_back(sol(places[i]));
//
//	}
//
//
//	return answer;
//}
//
//int main() {
//	string str;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			cin >> str;
//			for (int k = 0; k < 5; k++)
//			{
//				p[i][j][k] = str[k];
//			}
//		}
//		
//	}
//	
//	vector<int> aa= solution(p);
//	for (auto i : aa)cout << i << " ";
//	
//
//	return 0;
//	
//}