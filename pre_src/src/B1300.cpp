#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n";

using namespace std;

int N, k;

uint64_t seq(uint64_t bk)
{
    uint64_t count = 0;
    uint64_t nn = N;
    for (int i = 1; i <= N; i++)
    {
        count += min(nn, bk / i); //이부분 암기해야함
    }
    //cout << "count " << count;

    return count;
}

uint64_t BS(uint64_t left, uint64_t right, uint64_t val)
{
    while (left <= right)
    {
        uint64_t mid = (left + right) / 2;
        if (val <= seq(mid))
        {
            if (left == right)
            {
                break;
            }
            else
            {
                right = mid;
            }
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N >> k;

    cout << BS(1, N * N, k);

    return 0;
}