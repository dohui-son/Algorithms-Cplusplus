//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//#define endl "\n"
//
//
//int row, col, max_hr,before_max;
//vector<vector<int>>g;
//vector<vector<bool>>visit,setting;
//int xx[4] = { 0,-1,0,1 };
//int yy[4] = { -1,0,1,0 };
//queue<pair<int, int>>q,strip;
//
//
//
//pair<int,int> BFS_melt(){
//	int hr;
//	int pieces = 0;
//	
//	while (!q.empty())
//	{
//		
//		
//		int x = q.front().first;
//		int y = q.front().second;
//		q.pop();
//		bool flag = true;
//		int count_four = 0;
//		
//		for (int i = 0; i < 4; i++)
//		{
//			
//			int n_x = x + xx[i];
//			int n_y = y + yy[i];
//			
//			if (n_x < 0 || n_y < 0 || n_x >= row || n_y >= col)continue;
//			if (visit[n_x][n_y] == true)continue;
//			if (g[n_x][n_y] == 0) {
//				flag = false;
//				continue;
//			}
//			count_four++;
//			q.push(make_pair(n_x, n_y));
//			visit[n_x][n_y]=1;
//		}
//		if (flag==false || count_four != 4) {
//			strip.push(make_pair(x, y));
//		}
//		 if(flag == true && count_four == 4){ 
//			 hr = ++g[x][y];
//			 pieces++;
//		 }
//	}
//	pair<int,int> ret = make_pair(hr, pieces);
//	return ret;
//}
//void melt() {
//	while (!strip.empty())
//	{
//		g[strip.front().first][strip.front().second]=0;
//		strip.pop();
//	}
//}
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//	cin >> row >> col;
//	g = vector<vector<int>>(row, vector<int>(col));
//	visit = vector<vector<bool>>(row, vector<bool>(col,false));
//
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			cin >> g[i][j];
//		}
//	}
//	pair<int, int> ans;
//	int ans1=0, ans2=0;
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			if (g[i][j] != 0 && visit[i][j] != true) {
//				q.push(make_pair(i, j));
//				visit[i][j] = true;;
//				
//				ans = BFS_melt();
//				melt();
//				visit = setting;
//				if (ans.second != 0) {
//					ans1 = ans.first;
//					ans2 = ans.second;
//
//				}
//			}
//			
//		}
//
//	}
//
//	cout << ans1 << endl;
//	cout << ans2 << endl;
//
//	
//	
//
//
//	return 0;
//}
