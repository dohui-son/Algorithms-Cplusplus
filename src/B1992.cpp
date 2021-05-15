////#ifdef _MSC_VER
////#define _CRT_SECURE_NO_WARNINGS
////#endif // _MSC_VER
////#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//
//using namespace std;
//#define endl '\n';
//char g[67][67] = { ' ', };
//queue<char> q;
//int N;
//
//void DFS(int sx, int sy, int size) {
//
//	if (size == 1) {
//		q.push(g[sx][sy]);
//		return;
//	}
//	if (size >= 2) {
//		char start = g[sx][sy];
//		int flag = 0;
//		for (int i = sx; i < sx + size; i++)
//		{
//			for (int j = sy; j < sy + size; j++)
//			{
//				if (start != g[i][j] && size >= 2 && sx + size / 2 < N && sy + size / 2 < N) {
//					flag = 1;
//					q.push('(');
//					DFS(sx, sy, size / 2);
//					DFS(sx , sy + (size / 2), size / 2);
//					DFS(sx + (size / 2), sy , (size / 2));
//					DFS(sx + size / 2, sy + size / 2, size / 2);
//					q.push(')');
//					return;
//				}
//			}
//		}
//		q.push(start);
//		return;
//	}
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
//		cin >> str;
//		for (int j = 0; j < N; j++)
//		{
//			g[i][j] = str[j];
//		}
//	}
//	DFS(0, 0, N);
//	while (!q.empty())
//	{
//		printf("%c", q.front());
//		q.pop();
//	}
//
//	return 0;
//}