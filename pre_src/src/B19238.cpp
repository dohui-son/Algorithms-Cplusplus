////맞음
//
////study
////struct tmp { // priority queue 오버라이딩------------------------학습 메모
////	bool operator()(int& a, int& b) {
////		return a <= b;
////	}
////};
////
////bool cmp(int& a, int& b) { // sort함수에서 기준함수??만들어서 전달해줄 시에 먼저 와야할 요소가 어떤 애들인지 알려주는 함수를 만들어준것일 뿐
////	//정렬의 
////	return a <= b;
////}
//
//
//
//
//#include<iostream>
//#include <vector>
//#include <deque>
//#include <map>
//#include<queue>
//
//
//
//
//
//
//
//using namespace std;
//#define endl "\n"
//
//int N, M;
//int tx = 0, ty = 0, gas;
//map<pair<int, int>, pair<int, int>> guest;
//vector<vector<int>>g(23, vector<int>(23, 0));
//int gx, gy;
//
//
//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,-1,0,1 };
//int rest;
//
//int find(int& xx, int& yy) {
//	queue<vector<int>> q;
//	q.push({ tx,ty,0 });
//
//	vector<vector<int>>visit(23, vector<int>(23, 0));
//	visit[tx][ty] = 1;
//
//	queue<vector<int>>person;
//
//	while (!q.empty())
//	{
//		//for문 for문 도는 횟수는 큐 사이즈만큼 --> 지금 큐에 들었는 애들은 거리가 동일*******
//		int qq = q.size();
//		for (int i = 0; i < qq; i++)
//		{
//			int x = q.front()[0];
//			int y = q.front()[1];
//			int dis = q.front()[2];
//			q.pop();
//			if (g[x][y] == 2) {
//				person.push({ x,y,dis });
//				continue;
//			}
//			for (int i = 0; i < 4; i++)
//			{
//				int nx = dx[i] + x;
//				int ny = dy[i] + y;
//				int nd = dis + 1;
//				if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
//				if (g[nx][ny] == 1 || visit[nx][ny] == 1)continue;
//				visit[nx][ny] = 1;
//
//				q.push({ nx,ny,nd });
//
//			}
//		}
//		if (!person.empty())break;
//	}
//
//	if (person.empty())return -1;
//
//
//	int shortest = -1;
//	while (!person.empty())
//	{
//		vector<int> p = person.front();
//		person.pop();
//		if (shortest == -1) {
//			xx = p[0];
//			yy = p[1];
//			shortest = p[2];
//		}
//		else {
//			if (( xx > p[0]) || (xx == p[0] && yy > p[1])) {
//				xx = p[0];
//				yy = p[1];
//				shortest = p[2];
//			}
//		}
//	}
//	return shortest;
//
//
//}
//int find2(int tox, int toy) {
//
//	queue<vector<int>>q;
//	q.push({ tx,ty,0 });
//
//	vector<vector<bool>>visit(23, vector<bool>(23, false));
//	visit[tx][ty] = true;
//
//	while (!q.empty()) {
//		vector<int> now = q.front();
//		q.pop();
//		if (now[0] == tox && now[1] == toy)return now[2];
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = dx[i] + now[0];
//			int ny = dy[i] + now[1];
//			int nd = now[2] + 1;
//			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
//			if (visit[nx][ny] || g[nx][ny] == 1)continue;
//
//			visit[nx][ny] = true;
//			q.push({ nx,ny,nd });
//		}
//	}
//	return -1;
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> N >> M >> gas;
//	int tmp1, tmp2;
//	rest = M;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> g[i][j];
//		}
//
//	}
//
//
//	cin >> tmp1 >> tmp2;
//	tx = tmp1 - 1;
//	ty = tmp2 - 1;
//
//	int tmp3, tmp4;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
//		g[--tmp1][--tmp2] = 2;
//		--tmp3;
//		--tmp4;
//		guest.insert({ make_pair(tmp1, tmp2), make_pair(tmp3, tmp4) });
//
//	}
//
//	for (int i = 0; i < M; i++)
//	{
//		int dist = find(gx, gy);
//		if (gas <= dist || dist == -1) {
//			cout << -1;
//			return 0;
//		}
//		gas -= dist;
//		rest--;
//		g[gx][gy] = 0;
//
//
//
//		tx = gx;
//		ty = gy;
//		pair<int, int> g = guest[{gx, gy}];
//		gx = g.first;
//		gy = g.second;
//
//		dist = find2(gx, gy);
//		if (gas < dist || dist == -1) {
//			cout << -1;
//			return 0;
//		}
//		gas = gas - dist + dist * 2;
//		tx = gx;
//		ty = gy;
//	}
//	cout << gas;
//
//
//
//
//	return 0;
//
//}