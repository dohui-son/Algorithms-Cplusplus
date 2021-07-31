#include <iostream> //최적화문제를 결정문제로 바꿈
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"
#define first f
#define second s
typedef long long ll;
ll n, m, a[300004], ret = 1e18; //long long 최대값 : 1e18
bool check(ll mid)
{
    ll num = 0;
    for (int i = 0; i < m; i++)
    {
        num += a[i] / mid;
        if (a[i] % mid)
            num++;
    }
    return n >= num;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    ll lo = 1, hi = 0, mid = 0;
    for (int i = 0; i < m; i++)
        cin >> a[i], hi = max(hi, a[i]);
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            ret = min(ret, mid); //문제에서 최소를 찾고있나 최대를 찾고 있냐에 따라 달라지는 부분***
            hi = mid - 1;        // --> 이 문제는 최소값을 찾고 있다
        }
        else
            lo = mid + 1;
    }
    cout << ret << endl;
    return 0;
}