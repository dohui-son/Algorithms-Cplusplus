//***************************����Ʈ ���� ���� �� ���̵��******************
//#include<bits/stdc++.h>
////���θ� �������ش����� ���δ� ���������� ����ȭ�ǰ� �������Ŷ� ���� ���� �����°Ŵ� ���δ� ������ ������ ��� �ϳ��� ����
//#define maxn 200005
//typedef long long ll;
//using namespace std;
//const int INF = 987654321;
//const int dy[] = { -1, 0, 1, 0 };
//const int dx[] = { 0, 1, 0, -1 };
//int n, a[44], ret = INF;
//string s;
//void go(int here) 
//{
//    if (here == n + 1) { //n�� �� �Ŀ� ��������
//        int sum = 0;
//        for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
//            int cnt = 0;
//            for (int j = 1; j <= n; j++) if (a[j] & i)cnt++;  //���ο� T�� ��ֳ� // �������� �ƴ� ��Ʈ���� and�̰� cnt�� �� ���� 1�� ����
//            sum += min(cnt, n - cnt);                         // 001 -> true;
//        }                                                     //  10 -> true;
//        ret = min(ret, sum);                                  // 000 -> false;
//        return;
//    }
//    a[here] = ~a[here];  //not����
//    go(here + 1);
//    a[here] = ~a[here];
//    go(here + 1);
//}
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> s;
//        int value = 1; //2�� 31�� ���� ��
//        for (int j = 0; j < s.size(); j++) {
//            if (s[j] == 'T')a[i] |= value;   // a[i]|= value     // a[i] = a[i]||value;
//            value *= 2;
//        }
//    }
//    go(1);
//    cout << ret << "\n";
//    return 0;
//}
//
//// a^b �� a xor b ������ ���ϴ� ����.
////unsigned int�� 2 ��� ����Ʈ��
//
////a = 1100011;
//// a << 1;
////��� 100010�� ����Ʈ ���� ����� �����ϰ��� �Ѵٸ�,
//// a=<< 1 ;
//
//// a << 3 ; 3ĭ�ű�