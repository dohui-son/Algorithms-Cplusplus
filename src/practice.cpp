#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, ans = -1;
vector<vector<int>> g, test;

//void BT(vector<vector<int>>& pre_board, int cnt) {};
//void play(vector<vector<int>>& board, int direction) {};

void play(vector<vector<int>>& board, int direction) {
	queue<int> q;

	switch (direction)
	{
		//위쪽
	case 0 : 
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[j][i] > 0)q.push(board[j][i]);
				board[j][i] = 0;
			}
			int idx = 0;
			while (!q.empty())
			{
				int data = q.front();
				q.pop();
				if (board[idx][i] == 0) {
					board[idx][i] = data;
				}
				else if (board[idx][i] == data) {
					board[idx][i] *= 2;
					idx++;
				}
				else {
					idx++;
					board[idx][i] = data;
				}
			}
		}
		break;
	

		//오른쪽
	case 1: 
		for (int j = 0; j < N; j++)
		{
			for (int i = N - 1; i >= 0; i--)
			{
				if (board[j][i])q.push(board[j][i]);
				board[j][i] = 0;
			}
			int idx = N - 1;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				if (board[j][idx] == 0) { board[j][idx] = data; }
				else if (board[j][idx] == data)
				{
					board[j][idx] *= 2;
					idx--;
				}
				else {
					idx--;
					board[j][idx] = data;
				}
			}

		}
		break;
		//아래
	case 2:
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if (board[j][i] != 0)q.push(board[j][i]);
				board[j][i] = 0;
			}
			int idx = N - 1;
			while (!q.empty())
			{
				int data = q.front();
				q.pop();
				if (board[idx][i] == 0) {
					board[idx][i] = data;
				}
				else if (board[idx][i] == data) {
					board[idx][i] *= 2;
					idx--;
				}
				else {
					idx--;
					board[idx][i] = data;
				}
			}
		}
		break;
		// 왼쪽밀기
	case 3:
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] != 0) q.push(board[i][j]);
				board[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				if (board[i][idx] == 0) { board[i][idx] = data; }
				else if (board[i][idx] == data) {
					board[i][idx] *= 2;
					idx++;
				}
				else {
					idx++;
					board[i][idx] = data;
				}
			}

		}
		break;
	}
}

void BT(vector<vector<int>>&pre_board, int cnt) {
	vector<vector<int>>copied;
	if (cnt == 5) {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ans = max(ans, pre_board[i][j]);
			}
		}
		return;
	}
	else {
		for (int i = 0; i < 4; i++)
		{
			copied = pre_board;
			play(pre_board, i);
			BT(pre_board, cnt + 1);
			pre_board = copied;
		}
	}

}





int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> N;
	g = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> g[i][j];
		}
	}

	test = g;
	BT(test,0);

	cout << ans;


	return 0;
}