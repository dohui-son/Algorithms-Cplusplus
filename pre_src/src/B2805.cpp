#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n";

using namespace std;
uint64_t N;
uint64_t M;
vector<uint64_t> trees;

uint64_t h_to_len(uint64_t h)
{
    uint64_t ret = 0;
    for (uint64_t i = 0; i < N; i++)
    {
        if (trees[i] > h)
            ret += trees[i] - h;
    }
    return ret;
}

uint64_t asdf(uint64_t left, uint64_t right, uint64_t val)
{

    while (left <= right)
    {
        uint64_t mid = (left + right) / 2;
        if (val > h_to_len(mid))
        {
            if (left == right)
                break;

            else
                right = mid;
        }
        else
            left = mid - 1;
    }

    return left - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N >> M;
    trees = vector<uint64_t>(N);
    for (uint64_t i = 0; i < N; i++)
    {
        cin >> trees[i];
    }

    cout << asdf(0, *max_element(trees.begin(), trees.end()), M);

    return 0;
}