//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	
//	int v[2][3];
//	int v2[6];
//	int num,k=0, minimum,min_idx=0;
//	for (int i = 0; i < 2; i++)
//	{
//		
//		for (int j = 0; j < 3; j++)
//		{
//			cin >> num;
//			v[i][j] = num;
//			v2[k] = num;
//			if (k == 0) { minimum = num; }
//			if (minimum > v2[k]) {
//				minimum = v2[k];
//				min_idx = k;
//			}
//			k++;
//		}
//	}
//
//	num = v2[0];
//	v2[0] = v2[min_idx];
//	v2[min_idx] = num;
//
//	for (int i = 1; i < 5; i++)
//	{
//		minimum = num = v2[i];
//		min_idx = i;
//		for (int j = i+1; j < 6; j++)
//		{
//			if (minimum > v2[j]) {
//				minimum = v2[j];
//				min_idx = j;
//			}
//		}
//		v2[i] = v2[min_idx];
//		v2[min_idx] = num;
//	}
//	num = 0;
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			v[i][j] = v2[num];
//			num++;
//			cout << v[i][j] << " ";
//		}
//		cout << endl;
//
//	}
//	
//	
//	
//
//	return 0;
//}
/////////////////////////////////////////////////////////////////////////
//#include <iostream>
//using namespace std;
//
//#define endl "\n";
//
//int main() {
//
//	char v[3][6] = {
//		"FRQWT",
//		"GASYQ",
//		"ASADB"
//	};
//	int input;
//	cin >> input;
//	for (int i = 0; i < 3; i++)
//	{
//		cout << v[i][input];
//	}
//	
//	return 0;
//}


