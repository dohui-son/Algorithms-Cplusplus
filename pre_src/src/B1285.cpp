#include<bits/stdc++.h>


//가로만 뒤집어준다음에 세로는 뒤집을곳을 최적화되게 뒤집을거라서 
//가로 한줄 뒤집는거당 세로는 최적의 뒤집는 방법 하나만 있음 ==> 핵심 아이디어!!!!!!
#define maxn 200005
typedef long long ll;
using namespace std;
const int INF = 987654321;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, a[44], ret = INF;
string s;
void go(int here) 
{
   if (here == n + 1) { //n번 시도째
       int sum = 0;
       for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
           int cnt = 0;
           for (int j = 1; j <= n; j++) if (a[j] & i)cnt++;  //세로에 T가 몇개있냐 // 논리연산이 아닌 비트연산 and이고 cnt가 그 행의 1의 개수
           sum += min(cnt, n - cnt);                         // 001 -> true;
       }                                                     //  10 -> true;
       ret = min(ret, sum);                                  // 000 -> false;
       return;
   }
   a[here] = ~a[here];  //not연산
   go(here + 1);
   a[here] = ~a[here];
   go(here + 1);
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   cin >> n;
   for (int i = 1; i <= n; i++) {
       cin >> s;
       int value = 1; 
       for (int j = 0; j < s.size(); j++) {
           if (s[j] == 'T')a[i] |= value;   // a[i] = a[i]||value;
           value *= 2;
       }
   }
   go(1);
   cout << ret << "\n";
   return 0;
}

// a^b 가 a xor b 연산.
//unsigned int는 2 배로 쉬프트됨

// a=<< 1 ;
