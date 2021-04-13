//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//#define endl "\n"
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	vector<int> input(100,0);
//	
//	int start=99, end=0, A,B,C, tmp1,tmp2;
//
//	cin >> A >> B >> C;
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> tmp1 >> tmp2;
//		if (start > tmp1-1)start = tmp1-1;
//		if (end < tmp2-1)end = tmp2-1;
//		for (int j = tmp1-1; j < tmp2-1; j++)input[j]++;
//	}
//	tmp1 = 0;
//	for (int i = start; i < end; i++)
//	{
//		switch (input[i])
//		{
//		case 1:
//			tmp1 += A;
//			break;
//		case 2:
//			tmp1 += B*2;
//			break;
//		case 3:
//			tmp1 += C*3;
//			break;
//		}
//	}
//
//	cout << tmp1;
//
//
//
//	return 0;
//
//}