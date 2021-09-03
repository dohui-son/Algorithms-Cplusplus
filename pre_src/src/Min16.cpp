//#include <iostream>
//#include <vector>
//
//using namespace std;
//#define endl "\n"
//
////char vect[7] = "abcdef";
////void spin(int times);
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//
//
//
//	////1--------------------------------------------------
//	//char vect[8] = "ATBACK";
//	//int n;
//	////문자열길이구하기
//	//for (int i = 0; i < 8; i++)
//	//{
//	//	if (vect[i] == '\0') { // 널문자
//	//		n = i; 
//	//		break;
//	//	}
//	//}
//	////n~3까지
//	//for (int i = n; i >= 3; i--) {
//	//	vect[i] = vect[i - 1];
//	//}
//	//vect[3] = 'Q';
//	//cout << vect;
//
//
//	/*char vect[10] = "ABCDEFCG";
//	int n;
//	for (int i = 0; i < 10; i++)
//	{
//		if (vect[i] == '\0') {
//			n = i;
//			break;
//		}
//	}
//	for (int i = 3; i <= n-1; i++)
//	{
//		vect[i] = vect[i + 1];
//	}
//	for (int i = n - 2; i >= 0; i--) {
//		cout << vect[i];
//	}*/
//
//	//
//	
//	
//	////spin(3);
//	////cout << vect;
//	//int vect[15] = {3,7,1};
//	////0이되면 3으로
//	//for (int i = 3; i < 15; i++) {
//	//	if (i == 7)
//	//		int dbug = 1; //디버그코드 삽입 기법
//	//	vect[i] = vect[i - 3] + vect[i - 2] / vect[i-1];
//	//	if (vect[i] == 0)vect[i] = 3;
//	//}
//
//	//int vect[6] = { 3,7,1,4,2,9 };
//	//int ans[6];
//	//ans[0] = vect[0];
//	//for (int i = 1; i < 6; i++)
//	//{
//	//	ans[i] = vect[i] + ans[i - 1];
//	//}
//
//	vector<vector<int>> v(4,vector<int>(4));
//	v[0][3] = 4;
//	v[1][3] = 2;
//	v[2][3] = 3;
//	v[3][3] = 0;
//	v[3][0] = 6;
//	v[3][1] = 7;
//	v[3][2] = 1;
//	v[3][3] = 0;
//
//	for (int i = 2; i >=0; i--)
//	{
//		for (int j = 2; j >= 0; j--)
//		{
//			v[i][j] = v[i][j+1];
//			if (v[i + 1][j] > v[i][j + 1])v[i][j] = v[i + 1][j];
//			cout << v[i][j] << endl;
//		}
//		
//
//	}
//
//	
//포인터연산 참고*********
	//char a, b, c;
	//char* p1, * p2, * p3;

	//cin >> a >> b >> c;

	//p1 = &a;
	//p2 = &b;
	//p3 = &c;

	//if (*p1 >= *p2 && *p1 >= *p3) cout << *p1;
	//else if (*p2 >= *p1 && *p2 >= *p3) cout << *p2;
	//else cout << *p3;

//
//	
//	
//	 
//
//
//
//	return 0; // 리턴줄 한번 클릭하고 컨트롤 f10
//
//}
//
////void spin(int times) {
////	while (times-- ) {
////		char tmp= vect[5];
////		for (int i = 4; i >= 0; i--)vect[i+1] = vect[i];
////		vect[0] = tmp;
////		
////	}
////}