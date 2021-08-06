#include <iostream> /// 그리디임
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

int n;
double psum[10001], a[10001], ret, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    double b = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > b * a[i])
            b = a[i];
        else
            b *= a[i];
        ret = max(b, ret);
    }
    printf("%.3f", ret + 0.00001);
//     소수점 아래의 자릿수 = %f 점의 오른쪽에 있는 값.
// 그 자릿수를 맞추기 위해 자동으로 값을 반올림하여 출력한다.

    return 0;
}