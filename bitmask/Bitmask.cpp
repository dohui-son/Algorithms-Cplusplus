#include <bits/stdc++.h>
using namespace std; 

void t1(int t){
	int idx = 0; 
	int temp = t; 
	temp &= ~(1 << idx);
	cout << "불좀꺼줄래? T1 : " << temp << "\n";
}
void t2(int t){
	int idx = 0; 
	int temp = t; 
	temp ^= (1 << idx);
	cout << "XOR T2 : " << temp << "\n";
}
void t3(int t){
	int idx = (t & -t); 
	cout << "최하위 켜져있는 인덱스 T3: " << idx << "\n";
}
void t4(int t){
	int n = 4;  
	cout << "크기가 n인 모든 집합의 모든 비트 켜기 T4 : " << (1 << n) - 1 << "\n";
}
void t5(int t){
	int idx = 1; 
	int temp = t;
	temp |= (1 << idx);  
	cout << "idx번째 불켜기 T5 : " << temp << "\n";
}

void t6(int t){
	int idx = 0; 
	int temp = t;  
	string a = temp & (1 << idx) ? "yes" : "no";
	cout << "idx번째 비트가 있는지 확인하기 T6 : " << a << "\n";
}

int main() { 
	int t = 5; // 101 
	t1(t);
	t2(t);
	t3(t);
	t4(t);
	t5(t);
	t6(t); 
    return 0;
}
/*
불좀꺼줄래? T1 : 4
XOR T2 : 4
최하위 켜져있는 인덱스 T3: 1
크기가 n인 모든 집합의 모든 비트 켜기 T4 : 15
idx번째 불켜기 T5 : 7
idx번째 비트가 있느지 확인하기 T6 : yes
*/
