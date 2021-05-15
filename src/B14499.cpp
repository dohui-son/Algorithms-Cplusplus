////성공
//#include <iostream>
//#include <vector>
//#include <deque>
//
//using namespace std;
//#define endl "\n";
//int N, M, x,y,K;
//vector<vector<int>>graph;
//int command[1001] = {0,};
//deque<int> dice(6);//bottom 동 서 북 남 top
//
//int xx[4] = { 0,0,-1,1 };
//int yy[4] = { 1,-1,0,0 }; //동서북남
//void play();
//void play_dice(int direction, int n_x, int n_y);
//
//void play_dice(int direction, int n_x, int n_y) {
//	//주사위 돌려주기
//
//	int tmp1 , tmp2;
//	switch (direction)
//	{
//	case 0: //동
//		tmp1 = dice[0];// 바닥
//		dice[0] = dice[1];
//		tmp2 = dice[5]; //위
//		dice[5] = dice[2];
//		dice[2] = tmp1;
//		dice[1] = tmp2;
//		break;
//	case 1: //서
//		tmp1 = dice[0];// 바닥
//		dice[0] = dice[2];
//		tmp2 = dice[5]; //위
//		dice[5] = dice[1];
//		dice[1] = tmp1;
//		dice[2] = tmp2;
//		break;
//	case 2: //북
//		tmp1 = dice[0];// 바닥
//		dice[0] = dice[3];
//		tmp2 = dice[5]; //위
//		dice[5] = dice[4];
//		dice[4] = tmp1;
//		dice[3] = tmp2;
//
//		break;
//	case 3: //남
//		tmp1 = dice[0];// 바닥
//		dice[0] = dice[4];
//		tmp2 = dice[5]; //위
//		dice[5] = dice[3];
//		dice[3] = tmp1;
//		dice[4] = tmp2;
//
//		break;
//	}
//	//바닥이랑 지도처리해주기
//	if (graph[n_x][n_y] == 0) {
//		graph[n_x][n_y] = dice[0];
//		
//	}
//	else{
//		dice[0] = graph[n_x][n_y];
//		graph[n_x][n_y] = 0;
//	}
//	cout << dice[5] << endl;
//
//}
//
//
//void play() {
//	int dir;
//	int i=0;
//	while (i<K)
//	{
//		dir = command[i]-1;
//		i++;
//		int next_x = x + xx[dir];
//		int next_y = y + yy[dir];
//		if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) {
//			continue;
//		}
//		else {
//			play_dice(dir, next_x, next_y);
//			x = next_x;
//			y = next_y;
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//	
//
//	
//	cin >> N >> M >> x >> y >> K;
//	graph = vector<vector<int>>(N, vector<int>(M));
//	dice.push_back(0);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> graph[i][j];
//			
//		}
//	}
//	
//	for (int i = 0; i < K; i++)
//	{
//		cin >> command[i];
//		
//		
//
//	}
//
//	play();
//
//
//
//	return 0;
//}