////ctrl k c
////ctrl k u
////**************************play�Լ� �� ����������
////ó���� ���������� ���� �ڵ�
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//int N,ans=-1,max_5;
//vector<vector<int>>g, test;
//
//
//
//void play(vector<vector<int>>&board, int direction) { ////��0 ��1 �Ʒ�2 ��3
//    queue<int> q;
//
//    //���ڵ��� ť�� ������� �� ����
//    //�ش���� ���������� ���ڸ� �ֱ� ����
//    switch (direction)
//    {
//        //����
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
//        //������
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
//        //�Ʒ���
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
//        //����
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
//                    //���߿� �����ִ� ���Ӱ� �޸� ������ �������� �ʴ´�
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
//		for (int i = 0; i < 4; i++)//�� �� �Ʒ� ��
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
//	test = g; //resize�� �ʿ����
//	BT(0,test);
//	cout << ans;
//
//
//
//
//	return 0;
//}