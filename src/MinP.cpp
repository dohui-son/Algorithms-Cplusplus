//#include <iostream>
//#include<queue>
//#include <algorithm>
//
//using namespace std;
//#define endl "\n";
//int N, M;
//queue<vector<int>> cctvq;
//vector<vector<int>> visit;
//int ans = 987654321;
//
//void BT(queue<vector<int>>& q, vector<vector<int>>& visit_chk);
//void install(int r, int c, int angle, vector<vector<int>>& visit3);
//
//
//void install(int r, int c, int angle, vector<vector<int>>& visit3) {
//	
//
//	switch (angle)
//	{
//	case 0:
//		for (int i = r; i >= 0; i--)
//		{
//			if (visit3[i][c] == 6)break;
//			if (visit3[i][c] == 0) visit3[i][c] = 7;
//		}
//		break;
//	case 1:
//		for (int i = c; i < M; i++)
//		{
//			if (visit3[r][i] == 6)break;
//			if (visit3[r][i] == 0) visit3[r][i] = 7;
//		}
//		break;
//	case 2:
//		for (int i = r; i < N; i++)
//		{
//			if (visit3[i][c] == 6)break;
//			if (visit3[i][c] == 0) visit3[i][c] = 7;
//		}
//		break;
//	case 3:
//		for (int i = c; i >= 0; i--)
//		{
//			if (visit3[r][i] == 6)break;
//			if (visit3[r][i] == 0) visit3[r][i] = 7;
//		}
//		break;
//
//	}
//
//}
//
//
//void BT(queue<vector<int>>& q, vector<vector<int>>& visit_chk) {
//	if (q.empty())
//	{
//		
//
//
//		int view = 0;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++) {
//				if (visit_chk[i][j] == 0)view++;
//			}
//		}
//		ans = min(ans, view);
//		return;
//	}
//	else {
//
//		vector<int>cctv = q.front();
//		int cctvnum = cctv[0];
//		int x = cctv[1];
//		int y = cctv[2];
//		queue<vector<int>> qq = q;
//		
//		vector<vector<int>> visit2 = visit_chk;
//		vector<vector<int>> visit3 = visit_chk;
//		vector<vector<int>> visit4 = visit_chk;
//		vector<vector<int>> visit5 = visit_chk;
//		qq.pop();
//		switch (cctvnum)
//		{
//		case 1:
//			for (int i = 0; i < 4; i++)
//			{
//				//BT(queue<vector<int>>& q, vector<vector<int>>& visit_chk )
//				//void install(int r, int c, int angle, vector<vector<int>>&visit3)
//
//
//				if (i == 0) {
//					install(x, y, i, visit2);
//					BT(qq, visit2);
//				}
//				if (i == 1) {
//					install(x, y, i, visit3);
//					BT(qq, visit3);
//
//				}
//				if (i == 2) {
//					install(x, y, i, visit4);
//					BT(qq, visit4);
//				}
//				if (i == 3) {
//					install(x, y, i, visit5);
//					BT(qq, visit5);
//				}
//
//
//
//				
//
//				
//
//			
//			}
//			break;
//		case 2:
//			for (int i = 0; i < 2; i++)
//			{
//				if (i == 0) {
//					install(x, y, 0, visit2);
//					install(x, y, 2, visit2);
//					BT(qq, visit2);
//				}
//				else
//				{
//					install(x, y, 1, visit3);
//					install(x, y, 3, visit3);
//					BT(qq, visit3);
//
//				}
//			}
//			break;
//		case 3:
//			for (int i = 0; i < 4; i++)
//			{
//				if (i == 0) {
//					install(x, y, 0, visit2);
//					install(x, y, 1, visit2);
//					BT(qq, visit2);
//				}
//				else if (i == 1)
//				{
//					install(x, y, 1, visit3);
//					install(x, y, 2, visit3);
//					BT(qq, visit3);
//				}
//				else if (i == 2)
//				{
//					install(x, y, 2, visit4);
//					install(x, y, 3, visit4);
//					BT(qq, visit4);
//				}
//				else if (i == 3)
//				{
//					install(x, y, 0, visit5);
//					install(x, y, 3, visit5);
//					BT(qq, visit5);
//				}
//			}
//			break;
//		case 4:
//			for (int i = 0; i < 4; i++)
//			{
//				if (i == 0) {
//					install(x, y, 0, visit2);
//					install(x, y, 1, visit2);
//					install(x, y, 3, visit2);
//
//					BT(qq, visit2);
//				}
//				else if(i ==1)
//				{
//					install(x, y, 2, visit3);
//					install(x, y, 1, visit3);
//					install(x, y, 3, visit3);
//
//					BT(qq, visit3);
//				}
//				else if(i ==2)
//				{
//					install(x, y, 2, visit4);
//					install(x, y, 0, visit4);
//					install(x, y, 3, visit4);
//
//					BT(qq, visit4);
//				}
//				else
//				{
//					install(x, y, 2, visit5);
//					install(x, y, 0, visit5);
//					install(x, y, 1, visit5);
//
//					BT(qq, visit5);
//				}
//			}
//			break;
//		case 5:
//			for (int i = 0; i < 4; i++)
//			{
//				install(x, y, i, visit2);
//			}
//			BT(qq, visit2);
//
//			break;
//		}
//
//
//	}
//}
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	cin >> N >> M;
//	visit = vector<vector<int>>(N, vector<int>(M));
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> visit[i][j];
//			if (visit[i][j] > 0 && visit[i][j] < 6)cctvq.push({ visit[i][j] , i,j });
//		}
//
//	}
//
//	BT(cctvq, visit);
//	//BT(queue<vector<int>>& q, vector<vector<int>>& visit_chk )
//
//	cout << ans;
//
//
//
//
//	return 0;
//}