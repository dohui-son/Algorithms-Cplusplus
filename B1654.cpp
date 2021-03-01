#include <iostream>
#include <vector>
#include <algorithm>
// #include "../print.hpp" // 제출할때 빼고 제출

// #define endl "\n";

using namespace std;

uint64_t N, K;
vector<uint64_t> lan;

uint64_t len_to_total(uint64_t len)
{
    uint64_t ret = 0;
    for (uint64_t i = 0; i < N; i++)
    {
        ret += lan[i] / len;
    }
    return ret;
}

uint64_t asdf(uint64_t left, uint64_t right, uint64_t val)
{
    while (left <= right)
    {
        uint64_t mid = (left + right) / 2;
        if (val > len_to_total(mid))
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
    if (len_to_total(left - 1) == val)
    {
        return left - 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N >> K;
    lan = vector<uint64_t>(N);
    for (uint64_t i = 0; i < N; i++)
    {
        cin >> lan[i];
    }

    //cout << lan << endl;//벡터 이름만 출력하면 벡터가 다 출력됨
    cout << asdf(1, *max_element(lan.begin(), lan.end()), K) << "\n";

    return 0;
}