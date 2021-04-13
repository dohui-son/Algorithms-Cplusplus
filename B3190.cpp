//#include <iostream>
//#include <deque>
//#include<vector>
//#include <queue>
////뱀문제 성공
//using namespace std;
//
//#define endl "\n";
//
//
//vector<vector<int>> board;
//int N, sec;
//queue<int> dir_t;
//queue<char> dir; // 0왼L
//deque<vector<int>> snake;
//
//bool finish = false;
//int play();
//int xx[4] = { 0,1,0,-1 };//위 오른 아래 왼
//int yy[4] = { -1,0,1,0 };
//
//
//void snakesnake(int d) {
//
//
//
//	vector<int> head = snake[0];
//	int next_y = head[0] + yy[d];
//	int next_x = head[1] + xx[d];
//
//	if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= N)
//	{
//		finish = true;
//		return;
//	}
//	if (board[next_y][next_x] == 1) {
//		finish = true;
//		return;
//	}
//
//	if (board[next_y][next_x] != -1) {
//
//		board[snake.back()[0]][snake.back()[1]] = 0;
//		snake.pop_back();
//	}
//
//	snake.push_front({ next_y, next_x });
//
//	board[next_y][next_x] = 1;
//
//
//
//
//
//}
//
//
//
//int play() {
//
//	int time = dir_t.front();
//	int direction = 1;
//
//
//
//
//	while (!finish) {
//
//		sec++;
//		if (time + 1 == sec) { //저장된 초에 따라 뱀 움직이기
//
//			if (!dir.empty()) {
//				if (dir.front() == 'L')
//				{
//					direction = (direction + 3) % 4;
//				}
//				else {
//					direction = (direction + 1) % 4;
//				}
//
//				snakesnake(direction);
//			}
//
//			dir_t.pop();
//			if (!dir_t.empty()) {
//				time = dir_t.front();
//				dir.pop();
//			}
//
//		}
//		else {
//			snakesnake(direction);
//
//		}
//
//
//		
//		/*cout << endl;
//		cout << "sec  " << sec << endl;
//		for (vector<int> i : board) {
//			for (int k : i) cout << k << " ";
//			cout << endl;
//		}*/
//
//
//
//	}
//
//	return sec;
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//	int input;
//	cin >> N >> input;
//	board = vector<vector<int>>(N, vector<int>(N));
//	board[0][0] = 1;
//
//
//	int first, second;
//	for (int i = 0; i < input; i++)
//	{
//		cin >> first >> second;
//		board[first - 1][second - 1] = -1;
//	}
//	cin >> input;
//	snake.push_front({ 0,0 });
//	char d;
//	for (int i = 0; i < input; i++)
//	{
//		cin >> first >> d;
//		dir_t.push(first);
//		dir.push(d);
//	}
//
//	cout << play();
//
//
//
//	return 0;
//}