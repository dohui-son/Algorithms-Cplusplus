#include <iostream>
#include <vector>
#include <algorithm>
//*****아이디어가 잘 안떠오름****

using namespace std;
#define endl "\n";
long long s, e, cnt[100001], n, a[100001], ret;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (e < n)
    {
        if (!cnt[a[e]])
        { //지금 살펴본 애는 중복 안됨 (이때까지 동일한 애 뽑은 적 없음)
            cnt[a[e]]++;
            e++;
        }
        else
        { //이번애가 중복됨 (중복 발견)
            ret += (e - s);
            cnt[a[s]]--;
            s++;
        }
    }
    ret += (long long)(e - s) * (e - s + 1) / 2;
    cout << ret;

    return 0;
}