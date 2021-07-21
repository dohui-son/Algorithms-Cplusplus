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
    bool nat[4000002] = {
        0,
    };
    for (int i = 2; i <= n; i++)
    {
        if (nat[i])
            continue;
        for (int j = i * 2; j <= n; j += i)
        {
            nat[j] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (nat[i])
            continue;
        prime.push_back(i);
    }
    while (1)
    {
        if (sum >= n)
            sum -= prime[low++];
        else if (high >= prime.size())
            break;
        else
            sum += prime[high++];

        if (sum == n)
            ans++;
    }
    cout << ans << endl;

    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;
// #define endl "\n";
// int n, ans, p, high, low, sum;
// vector<int> prime;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     cin >> n;
//     vector<bool> nat(n);
//     for (int i = 2; i <= n; i++)
//     {
//         if (nat[i]) // 소수가 아님
//             continue;
//         for (int j = i * 2; j <= n; j += i)
//             nat[i] = 1; //소수가 아닌거에 표시해주기
//     }
//     for (int i = 2; i <= n; i++)
//     {
//         if (!nat[i])
//             prime.push_back(i);
//     }

//     while (1)
//     {
//         if (sum >= n)
//             sum -= prime[low++];
//         else if (high == prime.size())
//             break;
//         else
//             sum += prime[high++];

//         if (sum == n)
//             ans++;
//     }
//     cout << ans << endl;

//     return 0;
// }