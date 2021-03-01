#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n";
using namespace std;
int N, C;
vector<uint64_t> x;

bool is_dis_poosible(uint64_t distance)
{
    int count = 1;
    uint64_t prev = x[0];
    for (int i = 1; i < N; i++)
    {
        if (x[i] - prev >= distance)
        {
            count++;
            prev = x[i];
        }
    }
    if (count >= C)
        return true;
    return false;
}

uint64_t asdf(uint64_t left, uint64_t right)
{
    uint64_t ans = 0;
    while (left <= right)
    {
        uint64_t mid = (left + right) / 2;
        if (is_dis_poosible(mid))
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> N >> C;
    x = vector<uint64_t>(N);

    for (int i = 0; i < N; i++)
        cin >> x[i];

    sort(x.begin(), x.end());
    uint64_t max_dis = x[N - 1] - x[0];

    cout << asdf(1, max_dis);
    return 0;
}