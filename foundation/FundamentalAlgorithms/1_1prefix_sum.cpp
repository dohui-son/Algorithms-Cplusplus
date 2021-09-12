#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100004;
int a[MAX], b, c, psum[MAX], n, m; //PrefixSum 정적인 구간합 빅오1
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) //인덱스1부터 시작
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i]; //누적합 만드는 중
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b >> c;
        cout << psum[c] - psum[b - 1] << endl; //b에서 c까지의 합*** psum[c]-psum[b-1]
    }
    return 0;
}