#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
int n, m; //1000,000,000
int64_t ans = 100000000000, tmp;
vector<int64_t> v;

bool check(int64_t mid)
{
    if (mid == 0)
        return false; //이거 꼭 해줘야함 division by zero 에러뜸
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += v[i] / mid;
        if (v[i] % mid)
            cnt++;
    }
    return cnt <= n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;

    int64_t lo = 1, hi = 0, mid = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        if (hi < tmp)
            hi = tmp;
    }
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}

// #include <iostream> //최적화문제를 결정문제로 바꿈 --> 아이디어 / 암기 / 기본폼
// #include <vector>
// #include <algorithm>

// using namespace std;
// #define endl "\n"
// #define first f
// #define second s
// typedef long long ll;
// ll n, m, a[300004], ret = 1e18; //long long 최대값 : 1e18
// bool check(ll mid)
// {
//     ll num = 0;
//     for (int i = 0; i < m; i++)
//     {
//         num += a[i] / mid;
//         if (a[i] % mid)
//             num++;
//     }
//     return n >= num;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n >> m;
//     ll lo = 1, hi = 0, mid = 0;
//     for (int i = 0; i < m; i++)
//         cin >> a[i], hi = max(hi, a[i]);
//     while (lo <= hi)
//     {
//         mid = (lo + hi) / 2;
//         if (check(mid))
//         {
//             ret = min(ret, mid); //문제에서 최소를 찾고있나 최대를 찾고 있냐에 따라 달라지는 부분***
//             hi = mid - 1;        // --> 이 문제는 최소값을 찾고 있다
//         }
//         else
//             lo = mid + 1;
//     }
//     cout << ret << endl;
//     return 0;
// }