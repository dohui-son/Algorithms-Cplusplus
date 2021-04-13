//#include <iostream>
//#include <vector>
//#include <queue>
//#include <string>
//
//using namespace std;
//
//#define endl "\n"
//
//int H, W;
//int g[102][102];
//int visit[102][102];
//queue<pair<int, int>>cloud;
//
//int num = 0;
//void flew() {
//	while (!cloud.empty())
//	{
//		
//		pair<int, int > now = cloud.front();
//		cloud.pop();
//		if (now.second == W - 1)continue;
//
//		if (g[now.first][now.second + 1] == -1)g[now.first][now.second + 1] = g[now.first][now.second] + 1;
//		cloud.push({ now.first,now.second+1 });
//	}
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	string tmp;
//	cin >> H >> W;
//
//	for (int i = 0; i < H; i++)
//	{
//
//		cin >> tmp;
//		for (int j = 0; j < tmp.size(); j++) 
//		{
//			if (tmp[j] == 'c') {
//				cloud.push(make_pair(i, j));
//				g[i][j] = 0;
//			}
//			else g[i][j] = -1;
//		}
//	}
//	
//	flew();
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < W; j++)cout << g[i][j] << " ";
//		cout << endl;
//
//	}
//
//
//
//	return 0;
//}