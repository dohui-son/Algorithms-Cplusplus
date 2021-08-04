#include <iostream> //O(n^2)
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

vector<int> a;
int cnt[1005];
int tmp, n, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        int maxim = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && maxim < cnt[j])
                maxim = cnt[j];
        }
        cnt[i] = maxim + 1;
        ans = max(cnt[i], ans);
    }
    cout << ans << endl;

    return 0;
}

//////////////////////////////////////////////////////////////
#include <cstdio> //O(nlogn)
#include <algorithm>
using namespace std;

int n, lis[1001], len, num;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        auto lowerPos = lower_bound(lis, lis + len, num);
        if (*lowerPos == 0)
            len++;
        *lowerPos = num;
        for (int j = 0; j < n; j++)
        {
            printf("%d ", lis[j]);
        }
        printf("\n");
    }
    printf("%d", len);

    return 0;
}
/*
6
10 20 10 30 25 50
*/
