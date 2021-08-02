#include <iostream> // 내코드 -- 빠름
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int n, m, tmp, psum, ans;
vector<int> a;

bool check(int mid)
{
    // if (mid < *max_element(a.begin(), a.end()))
    //     return false;
    int cnt = 1;
    int real_mid = mid;
    for (int i = 0; i < n; i++)
    {
        if (mid - a[i] >= 0)
            mid -= a[i];

        else
        {
            cnt++;
            mid = real_mid;
            mid -= a[i];
            if (mid < 0)
                return false;
        }
    }
    return cnt <= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
        psum += tmp;
    }
    int lo = 0, hi = psum, mid = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    cout << ans << endl;

    return 0;
}
////////////////////////////////////다른 사람 코드 -- 내 코드가 더 빠름
