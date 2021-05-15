//#include <iostream>
//#include <cstdio>
//#include <queue>
//
//using namespace std;
//
//typedef struct {
//    int x, y;
//} Ball_posi;
//
//typedef struct {
//    int depth;
//    Ball_posi red, blue;
//} Balls;
//
//struct compare {
//    bool operator()(Balls a, Balls b) {
//        return a.depth > b.depth;
//    }
//};
//
//const int WALL = -1;
//const int PATH = 0;
//const int HOLE = 1;
//
//const int dx[4] = { 1, 0,-1, 0 };
//const int dy[4] = { 0, 1, 0,-1 };
//
//Ball_posi red, blue;
//
//Balls move(Balls cur, int opt, vector<vector<int>>& board) {
//    Balls ret = cur;
//
//    ret.depth++;
//    while (true) {  // move red
//        if (board[ret.red.y][ret.red.x] == WALL) {
//            ret.red.y -= dy[opt];
//            ret.red.x -= dx[opt];
//            break;
//        }
//        if (board[ret.red.y][ret.red.x] == HOLE)
//            break;
//
//        ret.red.y += dy[opt];
//        ret.red.x += dx[opt];
//    }
//    while (true) {  // move blue
//        if (board[ret.blue.y][ret.blue.x] == WALL) {
//            ret.blue.y -= dy[opt];
//            ret.blue.x -= dx[opt];
//            break;
//        }
//        if (board[ret.blue.y][ret.blue.x] == HOLE)
//            break;
//
//        ret.blue.y += dy[opt];
//        ret.blue.x += dx[opt];
//    }
//
//    return ret;
//}
//
//int solution(int N, int M, vector<vector<int>>& board) {   // will use bfs
//    priority_queue<Balls, vector<Balls>, compare> pq;
//    int ret = 2e9;
//
//    pq.push({ 0, {red.x, red.y}, {blue.x, blue.y} });
//    while (!pq.empty()) {
//        Balls cur = pq.top();
//        Balls next;
//        pq.pop();
//
//        for (int i = 0; i < 4; i++) {
//            next = move(cur, i, board);
//            if (next.depth > ret)
//                continue;
//
//            if (cur.red.x == next.red.x && cur.red.y == next.red.y) // 변화 X
//                if (cur.blue.x == next.blue.x && cur.blue.y == next.blue.y)
//                    continue;
//
//            if (next.red.x == next.blue.x && next.red.y == next.blue.y) { // 두 공이 겹침
//                if (board[next.red.y][next.red.x] == HOLE) // 동시에 구멍에 들어감 -> 실패
//                    continue;
//                switch (i) { // 공이 겹치지 않게 예외처리
//                case 0: // x  1
//                    cur.red.x < cur.blue.x ? next.red.x -= 1 : next.blue.x -= 1;
//                    break;
//                case 1: // y  1
//                    cur.red.y < cur.blue.y ? next.red.y -= 1 : next.blue.y -= 1;
//                    break;
//                case 2: // x -1
//                    cur.red.x > cur.blue.x ? next.red.x += 1 : next.blue.x += 1;
//                    break;
//                case 3: // y -1
//                    cur.red.y > cur.blue.y ? next.red.y += 1 : next.blue.y += 1;
//                    break;
//                }
//            }
//            if (board[next.red.y][next.red.x] == HOLE) { // 성공
//                ret = (ret > next.depth ? next.depth : ret);
//            }
//            else if (board[next.red.y][next.red.x] == HOLE) { // 실패
//                continue;
//            }
//
//            if (next.depth == 10) // 이미 실패 // 기울임 횟수 > 10 불가
//                continue;
//
//            pq.push(next);
//        }
//    }
//
//    if (ret == 2e9)
//        return -1;
//    return ret;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int N; cin >> N;    // height
//    int M; cin >> M;    // width
//    vector<vector<int>> board;
//    for (int i = 0; i < N; i++) {   // get board
//        board.push_back({});
//        string line; cin >> line;
//        for (int j = 0; j < M; j++) {
//            char tmp = line[j];
//            int num;
//            if (tmp == '#') {
//                num = WALL;
//            }
//            else if (tmp == '.') {
//                num = PATH;
//            }
//            else if (tmp == 'O') {
//                num = HOLE;
//            }
//            else if (tmp == 'R') {
//                red.x = j;
//                red.y = i;
//                num = PATH;
//            }
//            else { // tmp == 'B'
//                blue.x = j;
//                blue.y = i;
//                num = PATH;
//            }
//            board[i].push_back(num);
//        }
//    }
//
//    cout << solution(N, M, board);
//
//    return 0;
//}