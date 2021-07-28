#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
int n, sum, a, ret = -1001;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> n;
        sum += a;
        ret = max(ret, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << ret << endl;

    return 0;
}
//////////////////////////////////////

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     int N;
//     vector<int> input;
//     vector<long long> memo;
//     cin >> N;
//     input = vector<int>(N);
//     memo = vector<long long>(N);

//     for (int i = 0; i < N; i++)
//         cin >> input[i];

//     memo[0] = input[0];
//     for (int i = 1; i < N; i++)
//     {
//         memo[i] = input[i];
//         memo[i] = max(memo[i - 1] + input[i], memo[i]);
//     }
//     cout << *max_element(memo.begin(), memo.end());
//     return 0;
// }