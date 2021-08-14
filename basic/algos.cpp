//1주차 - 문자열/누적합/구현
//2주차 - 그래프이론/dfs/bfs
//3주차 - 완전탐색/백트랙킹
//4주차 - 비트마스킹
//5주차 - 그리디/라인스위핑/투포인터
//6주차 - 이분탐색/LIS(최대증가부분수열)
//7주차 - DP (동적계획법, 다이나믹프로그래밍)
//8주차 - 펜윅트리와 최단거리 알고리즘(다익스트라,플로이드워셜,벨만포드)

//5주차 - 그리디/라인스위핑/투포인터
//[5그리디] 회의실배정
int from, to, n, idx = 0, ret = 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> from >> to;
        v.push_back({to, from});
    }
    sort(v.begin(), v.end());
    from = v[0].second;
    to = v[0].first;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second < to)
            continue;
        from = v[i].second;
        to = v[i].first;
        ret++;
    }
    cout << ret << '\n';
    return 0;
}
//[그리디] 보석도둑
typedef long long ll;
ll n, k, ret, temp1, temp;
int main()
{
    cin >> n >> k;
    vector<pair<ll, ll>> v(n);
    vector<ll> vv(k);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < k; i++)
        cin >> vv[i];
    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());
    priority_queue<ll> pq;

    int j = 0;
    for (int i = 0; i < k; i++)
    {
        while (j < n && v[j].first <= vv[i])
            pq.push(v[j++].second);
        if (pq.size())
        {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << "\n";
    return 0;
}
//[PriorityQ]칠무해
//n이 너무나 크기때문에 PQ를 사용한다
#define f first
#define s second
typedef unsigned long long ll;
const int INF = 987654321;
int n;
double temp;
priority_queue<double> pq;
vector<double> v;
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (pq.size() == 7)
        {
            pq.push(temp);
            pq.pop();
        }
        else
            pq.push(temp);
    }
    while (pq.size())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());
    for (double i : v)
        printf("%.3lf\n", i);
    return 0;
}
//[라인스]

//6주차 - 이분탐색/LIS(최대증가부분수열)
//[이분탐색BS]용돈관리
//최적화문제를 결정문제로
typedef long long ll;
int n, m, a[100005], _max;
bool check(int mid)
{
    int cnt = 1;
    int real_mid = mid;
    for (int i = 0; i < n; i++)
    {
        if (mid - a[i] >= 0)
        {
            mid -= a[i];
        }
        else
        {
            //남은 금액을 넣고 통장에서 인출했다!
            mid = real_mid;
            cnt++;
            if (a[i] > mid)
                return false;
            else
                mid -= a[i];
        }
    }
    return cnt <= m;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i], _max = max(a[i], _max);
    int lo = 1, hi = 100004, ret;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            hi = mid - 1;
            ret = mid;
        }
        else
            lo = mid + 1;
    }
    cout << ret << "\n";
    return 0;
}
//[LIS 가장 긴 증가하는 부분 수열]
// O(n^2)
int n, a[1001], cnt[1001], ret;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++)
    {
        int maxValue = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && maxValue < cnt[j])
                maxValue = cnt[j];
        }
        cnt[i] = maxValue + 1;
        ret = max(ret, cnt[i]);
    }
    printf("%d\n", ret);
}

//[LIS 가장 긴 증가하는 부분 수열4]
// O(n^2)--with trace
int n, a[1001], ret = 1, cnt[1001], idx;
int prev_list[1001];
vector<int> real;
void go(int idx)
{
    if (idx == -1)
        return;
    real.push_back(a[idx]);
    go(prev_list[idx]);
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    fill(prev_list, prev_list + 1001, -1);
    fill(cnt, cnt + 1001, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && cnt[i] < cnt[j] + 1)
            {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if (ret < cnt[i])
                {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }
    printf("%d\n", ret);
    go(idx);
    for (int i = real.size() - 1; i >= 0; i--)
    {
        printf("%d ", real[i]);
    }
    return 0;
}

//[LIS 가장 긴 증가하는 부분 수열4]
// O(n^2)--with trace + for문 버전
int n, a[1001], ret = 1, cnt[1001], idx, prev_list[1001];
vector<int> real;
void go(int idx)
{
    if (idx == -1)
        return;
    real.push_back(a[idx]);
    go(prev_list[idx]);
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    fill(prev_list, prev_list + 1001, -1);
    fill(cnt, cnt + 1001, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && cnt[i] < cnt[j] + 1)
            {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if (ret < cnt[i])
                {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }
    printf("%d\n", ret);
    int i = idx;
    for (; prev_list[i] != -1; i = prev_list[i])
    {
        real.push_back(a[i]);
    }
    real.push_back(a[i]);
    for (int i = real.size() - 1; i >= 0; i--)
    {
        printf("%d ", real[i]);
    }
    return 0;
}

//[LIS 가장 긴 증가하는 부분 수열]
// O(n log n) --lower_bound는 정렬된 배열에서만
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
    }
    printf("%d", len);
    return 0;
}

//[LIS 가장 긴 증가하는 부분 수열]
// O(n log n) -- with trace
int n, len, num;
pair<int, int> a[100001];
int lis[100001];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis, lis + len, a[i].second);
        if (!(*it))
            len++;
        *it = a[i].second;
    }
    printf("%d\n", n - len);

    return 0;
}

//7주차 - DP (동적계획법, 다이나믹프로그래밍)
//[DP]자두나무
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1004][2][34], n, m, b[1004];
int go(int idx, int tree, int mm)
{
    if (mm < 0)
        return -1e9;
    if (idx == n)
        return mm == 0 ? 0 : -1e9;
    int &ret = dp[idx][tree][mm];
    if (~ret)
        return ret;
    return ret = max(go(idx + 1, tree, mm), go(idx + 1, tree ^ 1, mm - 1)) + (tree == b[idx] - 1);
}
int main()
{
    fill(&dp[0][0][0], &dp[0][0][0] + 1004 * 2 * 34, -1);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cout << max(go(0, 0, m), go(0, 1, m - 1)) << "\n";
    return 0;
}
//[DP]1,2,3 더하기 4
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, dp[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    dp[0] = 1;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 10000; j++)
        {
            if (j - i >= 0)
                dp[j] += dp[j - i];
        }
    }
    while (t--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, dp[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    dp[0] = 1;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 10000; j++)
            if (j - i >= 0)
                dp[j] += dp[j - 1];
    }
    while (t--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
