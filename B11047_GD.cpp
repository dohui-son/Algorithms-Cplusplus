#include <iostream>
#include <vector>

#define endl "\n";
using namespace std;
int N, K;
vector<int> A;

int find_min()
{
    for (int i = N - 1; i >= 0; i--)
    {
        if (A[i] > K)
            continue;
        int sum = A[i];
        int idx = i;
        int count = 1;
        while (idx > -1)
        {
            if ((sum + A[idx]) <= K)
            {
                sum += A[idx];
                count++;
                if (sum == K)
                {
                    return count;
                }
            }
            if (sum + A[idx] > K)
                idx--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N >> K;
    A = vector<int>(N, 0);

    for (int i = 0; i < N; i++)
    {

        cin >> A[i];
        if (A[i] == K)
        {
            cout << 1;
            return 0;
        }
    }

    cout << find_min();

    return 0;
}