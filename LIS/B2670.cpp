#include <iostream> /// 그리디임
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

int n;
double a[10001], ret, b;

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

    return 0;
}