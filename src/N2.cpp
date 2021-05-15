//#include <iostream>
//#include <vector>
//#include <queue>
//#include <map>
//
//
////연구소 --- > 조합 2개 3개정도는 2중3중 for문 돌려도 된다.
//
//
//using namespace std;
//#define endl "\n"
//int n;
//vector <vector<int>>e(100, vector<int>(2, 0));
//vector<vector<bool>>g(101, vector<bool>(101, false));
//vector<int>ans(3, -1);
////map<int, pair<int, int>> m;
//vector<vector<bool>>visit(101, vector<bool>(101, false));
//
//bool BFS(int cut) {
//	queue<int>q;
//	q.
//	//pair<int, int> make_back;
//	
//	
//	q.push(e[cut][0]);
//	while (!q.empty())
//	{
//		int now = q.front(); q.pop();
//		for (int i = 0; i < n; i++)
//		{
//			visit
//
//		}
//
//	}
//
//
//	
//}
//
//
//
//vector<int> BT(int cnt,int next_e) {
//	if (cnt == 3) {
//		sort(ans.begin(), ans.end());
//		return ans;
//	}
//
//	for (int i = next_e; i < n; i++)
//	{
//		if (cnt == 0 && BFS(i)) {
//			int next_node = BFS(i);
//			ans[cnt] = i;
//			g[e[i][0]][e[i][1]] = false;
//			g[e[i][1]][e[i][0]] = false;
//			BT();
//			ans[cnt] = -1;
//			g[e[i][0]][e[i][1]] = true;
//			g[e[i][1]][e[i][0]] = true;
//		}
//		if (cnt >= 1 && BFS(i) )
//		{
//			ans[cnt] = i;
//			g[e[i][0]][e[i][1]] = false;
//			g[e[i][1]][e[i][0]] = false;
//			BT();
//			ans[cnt] = -1;
//			g[e[i][0]][e[i][1]] = true;
//			g[e[i][1]][e[i][0]] = true;
//		}
//
//	}
//
//}
//
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	cin >> n;
//	for (int i = 0; i < n-1; i++)
//	{
//		cin >> e[i][0] >> e[i][1];
//		
//		g[e[i][0]][e[i][1]] = true;
//		g[e[i][1]][e[i][0]] = true;
//	}
//	BT();
//
//	return 0;
//}