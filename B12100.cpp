////ctrl k c
////ctrl k u
////**************************play함수 꼭 열심히보기
////처음에 실패했지만 맞은 코드
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//int N,ans=-1,max_5;
//vector<vector<int>>g, test;
//
//
//
//void play(vector<vector<int>>&board, int direction) { ////위0 오1 아래2 왼3
//    queue<int> q;
//
//    //숫자들을 큐에 집어놓고 각 행의
//    //해당방향 끝에서부터 숫자를 넣기 시작
//    switch (direction)
//    {
//        //위쪽
//    case 0:
//        for (int i = 0; i < N; i++)
//        {
//            for (int j = 0; j < N; j++)
//            {
//                if (board[j][i]) q.push(board[j][i]);
//                board[j][i] = 0;
//            }
//            int idx = 0;
//            while (!q.empty())
//            {
//                int data = q.front();
//                q.pop();
//                if (board[idx][i] == 0) board[idx][i] = data;
//                else if (board[idx][i] == data)
//                {
//                    board[idx][i] *= 2;
//                    idx++;
//                }
//                else
//                {
//                    idx++;
//                    board[idx][i] = data;
//                }
//            }
//        }
//        break;
//        //오른쪽
//    case 1:
//        for (int i = 0; i < N; i++)
//        {
//            for (int j = N - 1; j >= 0; j--)
//            {
//                if (board[i][j])q.push(board[i][j]);
//                board[i][j] = 0;
//            }
//            int idx = N - 1;
//            while (!q.empty())
//            {
//                int data = q.front();
//                q.pop();
//                if (board[i][idx] == 0)board[i][idx] = data;
//                else if (board[i][idx] == data)
//                {
//                    board[i][idx] *= 2;
//                    idx--;
//                }
//                else
//                {
//                    idx--;
//                    board[i][idx] = data;
//                }
//            }
//        }
//        break;
//        //아래쪽
//    case 2:
//        for (int i = 0; i < N; i++)
//        {
//            for (int j = N - 1; j >= 0; j--)
//            {
//                if (board[j][i]) q.push(board[j][i]);
//                board[j][i] = 0;
//            }
//            int idx = N - 1;
//            while (!q.empty())
//            {
//                int data = q.front();
//                q.pop();
//                if (board[idx][i] == 0) board[idx][i] = data;
//                else if (board[idx][i] == data)
//                {
//                    board[idx][i] *= 2;
//                    idx--;
//                }
//                else
//                {
//                    idx--;
//                    board[idx][i] = data;
//                }
//            }
//        }
//        break;
//        //왼쪽
//    case 3:
//        for (int i = 0; i < N; i++)
//        {
//            for (int j = 0; j < N; j++)
//            {
//                if (board[i][j])q.push(board[i][j]);
//                board[i][j] = 0;
//            }
//            int idx = 0;
//            while (!q.empty())
//            {
//                int data = q.front();
//                q.pop();
//                if (board[i][idx] == 0) board[i][idx] = data;
//                else if (board[i][idx] == data)
//                {
//                    board[i][idx] *= 2;
//                    //시중에 나와있는 게임과 달리 여러번 합쳐지지 않는다
//                    idx++;
//                }
//                else
//                {
//                    idx++;
//                    board[i][idx] = data;
//                }
//            }
//        }
//        break;
//    }
//}
//
//void BT(int cnt,vector<vector<int>>& pre_game) { 
//    vector<vector<int>> before_play;
//	if (cnt == 5) {
//        for (int i = 0; i < N; i++)
//            for (int j = 0; j < N; j++)ans = max(pre_game[i][j], ans);
//		return;
//	}
//	else {
//		for (int i = 0; i < 4; i++)//위 오 아래 왼
//		{
//			before_play = pre_game;
//            play(pre_game,i);
//			BT(cnt + 1,pre_game);
//			pre_game= before_play;
//		}
//	}
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//	cin >> N;
//	g = vector<vector<int>>(N, vector<int>(N));
//	
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> g[i][j];
//			ans = max(ans, g[i][j]);
//		}
//	}
//	test = g; //resize할 필요없음
//	BT(0,test);
//	cout << ans;
//
//
//
//
//	return 0;
//}