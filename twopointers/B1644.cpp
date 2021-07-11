#include <iostream>
#include <vector>

using namespace std;
#define endl "\n";
int n, ans, p, high, low, sum;
vector<int> prime;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    vector<bool> nat(n);
    for (int i = 2; i <= n; i++)
    {
        if (nat[i])
            continue; // "소수가 아닌"자연수 이다
        for (int j = i * 2; j <= n; j += i)
            nat[j] = 1;
    }
    for (int i = 2; i <= n; i++)
        if (!nat[i])
            prime.push_back(i);
    int p = prime.size();
    while (1)
    {
        if (sum >= n)
            sum -= prime[low++];
        else if (high == p)
            break;
        else
            sum += prime[high++];

        if (sum == n)
            ans++;
    }
    cout << ans;
    return 0;
}