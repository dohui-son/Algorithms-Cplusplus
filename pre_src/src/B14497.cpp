//#include <iostream>
//#include <vector>
//#include<algorithm>
//#include <queue>
//
//using namespace std;
//#define endl "\n"
//int n,m;//°¡·Î°¡ m
//vector<vector<char>>g(301, vector<char>(301));
//int sy, sx, fy, fx;
//int dy[4] = { 0,1,0,-1 };
//int dx[4] = { 1,0,-1,0 };
//string str;
//int ans;
//vector<vector<int>>visit(301, vector<int>(301,0));
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	cin >> n >>m>>sx>>sy>>fx>>fy;
//	sx--; sy--; fx--; fy--;
//	
//	for (int i = 0; i < n; i++)
//	{
//		cin >> str;
//		for (int j = 0; j < m; j++)g[i][j] = str[j];
//	}
//	
//	queue<pair<int, int>>q;
//	q.push({ sx, sy });
//	visit[sx][sy] = 1;
//
//	
//	
//	while (!q.empty())
//	{
//		
//		int qsize = q.size();
//		//cout << qsize;
//		for (int i = 0; i < qsize; i++)
//		{
//			pair<int, int> now = q.front();
//			q.pop();
//			if (now.first == fx && now.second == fy) {
//				//cout << "answer";
//				//ans--;
//				cout << ans;
//				return 0;
//			}
//			for (int i = 0; i < 4; i++)
//			{
//				int nx = dx[i] + now.first;
//				int ny = dy[i] + now.second;
//				//cout << nx << " " << ny << endl;
//				if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
//				//cout << "visit  " << visit[nx][ny] << endl;
//				while (1)
//				{
//					
//					if (visit[nx][ny] == 0) {
//						
//						visit[nx][ny] = 1;
//						q.push({ nx,ny });
//						//cout << "size  "<< q.size() << endl;
//					}
//					if (g[nx][ny] == '1') {
//						g[nx][ny] == '0';
//						break;
//					}
//					nx += dx[i];
//					ny += dy[i];
//					cout << nx << "    " << ny << endl;
//					if (nx < 0 || ny < 0 || nx >= n || ny >= m)break;
//					
//
//				}
//				
//
//				
//
//			}
//		}
//		ans++;
//	}
//	
//	
//
//	return 0;
//}