//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//#define endl "\n";
//int64_t T;
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> T;
//	int64_t num = 0;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> num;
//		int64_t t = 0, f = 0;
//		//
//		
//		for (int64_t k = 2; k <= num; k*=2)
//		{
//			t+= num / k;
//		}
//		for (int64_t j = 5; j <= num; j*=5)
//		{
//			f += num / j;
//		}
//		cout << min(t, f) << endl;
//		
//		//�õ���� !! ���Ǵ� �޸��������̼�
//		//�ð��ʰ� (+ for���̸�)  for ���� ++/--���� �پ� �����鼭 �����غ���
//
//	}
//
//
//
//	return 0;
//}