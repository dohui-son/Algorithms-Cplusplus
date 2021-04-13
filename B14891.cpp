//#include <iostream>
//#include <vector>
//
////ret += gear1[(right1 + 6) % 8];
////ret += gear2[(right2 + 6) % 8] * 2;
////ret += gear3[(right3 + 6) % 8] * 4;      //중요한 방식 다음에 이런식으로 써먹기***********************
////ret += gear4[(left4 + 2) % 8] * 8;
////무한루프 조심하기 출력이 안되고 끝날때 무한루프일수도 있음
//
//
//
//using namespace std;
//#define endl "\n";
//vector<int> gear1(8);
//vector<int> gear2(8);
//vector<int> gear3(8);
//vector<int> gear4(8);
//int K; // 최대 100
//vector<vector<int>> input;
//
//int right1=2, left2=6, right2=2, left3=6, right3=2, left4=6;
//
//
//void rotate1(int dir, int from);
//void rotate2(int dir, int from);
//void rotate3(int dir, int from);
//void rotate4(int dir, int from);
//int cal_ans();
//
//
//void  rotate(int g, int d)
//{
//	switch (g)
//	{
//	case 1:
//		rotate1(d,0);
//		break;
//	case 2:
//		rotate2(d,0);
//		break;
//	case 3:
//		rotate3(d,0);
//		break;
//	case 4:
//		rotate4(d, 0);
//		break;
//	}
//}
//
//void rotate1(int dir ,int from) { //0처음굴려진 바퀴
//
//	int otherd = -1;
//	if (dir == -1)otherd = 1;
//	if (from!=2 && gear1[right1] != gear2[left2]) { rotate2(otherd, 1); }
//
//	if (dir == 1) { //시계방향
//		if (right1 == 0)right1 = 7;
//		else { right1--; }
//	}
//	else {//반시계방향
//		if (right1 == 7)right1 = 0;
//		else { right1++; }
//	}
//}
//void rotate2(int dir, int from) { //0처음굴려진 바퀴
//
//	int otherd = 1;
//	if (dir == 1)otherd = -1;
//
//	if (from !=1 && gear2[left2] != gear1[right1])rotate1(otherd, 2);
//	if (from != 3 &&gear2[right2] != gear3[left3])rotate3(otherd, 2);
//
//	if(dir == 1){//시계방향
//		if (right2 == 0) {
//			right2 = 7;
//			left2--;
//			return;
//		}
//		if (left2 == 0) {
//			left2 = 7;
//			right2--;
//			return;
//		}
//		left2--;
//		right2--;
//	}
//	else {//반시계방향
//		if (right2 == 7) {
//			right2 = 0;
//			left2++;
//			return;
//		}
//		if (left2 == 7) {
//			left2 = 0;
//			right2++;
//			return;
//		}
//		left2++;
//		right2++;
//
//	}
//}
//void rotate3(int dir , int from) { //0처음굴려진 바퀴
//	int otherd = 1;
//	if (dir == 1)otherd = -1;
//
//
//	if (from !=2 && gear3[left3] != gear2[right2])rotate2(otherd, 3);
//	if (from != 4 && gear3[right3] != gear4[left4])rotate4(otherd, 3);
//
//	if (dir == 1) {//시계
//		if (right3 == 0) {
//			right3 = 7;
//			left3--;
//			return;
//		}
//		if (left3 == 0) {
//			left3 = 7;
//			right3--;
//			return;
//		}
//		right3--;
//		left3--;
//	}
//	else {//반시계
//		if (left3 == 7) {
//			left3 = 0;
//			right3++;
//			return;
//		}
//		if (right3 == 7)
//		{
//			right3 = 0;
//			left3++;
//			return;
//		}
//		right3++;
//		left3++;
//	}
//
//}
//void rotate4(int dir, int from) {
//
//	int otherd = 1;
//	if (dir == 1)otherd = -1;
//
//	if (from != 3 && gear4[left4] != gear3[right3])rotate3(otherd , 4);
//
//	if (dir == 1) {//시계
//		if (left4 == 0)left4 = 7;
//		else { left4--; }
//	}
//	else {
//		if (left4 == 7)left4 = 0;
//		else {
//			left4++;
//		}
//
//	}
//
//}
//
//int cal_ans() {
//	int ret = 0;
//	
//	ret += gear1[(right1 + 6) % 8];
//	ret += gear2[(right2 + 6) % 8] * 2;
//	ret += gear3[(right3 + 6) % 8] * 4;      //중요한 방식 다음에 이런식으로 써먹기***********************
//	ret += gear4[(left4 + 2) % 8] * 8;
//	
//	return ret;
//}
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//	int K;
//
//	string gears;
//	for (int i = 0; i < 4; i++)
//	{
//		cin >> gears;
//		for (int j = 0; j < 8; j++)
//		{
//			if (gears[j] == '1' && i == 0)gear1[j] = 1;
//			if (gears[j] == '1' && i == 1)gear2[j] = 1;
//			if (gears[j] == '1' && i == 2)gear3[j] = 1;
//			if (gears[j] == '1' && i == 3)gear4[j] = 1;
//		}
//	}
//	cin >> K;
//
//	int gnum, direction;
//	input = vector<vector<int>>(K, vector<int>(2));
//	for (int i = 0; i < K; i++)
//	{
//		cin >> input[i][0] >> input[i][1];
//	}
//	for (int i = 0; i < K; i++)
//	{
//		rotate(input[i][0], input[i][1]);
//	}
//	
//
//	//답계산하기
//	int ans = cal_ans();
//	cout << ans;
//
//	return 0;
//}