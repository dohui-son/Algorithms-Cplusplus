#include <iostream>
#include <vector>

#define endl "\n";

using namespace std;
int N, M;
vector<int> card;

int find()
{
    int max_sum = 0;

    for (int i = 0; i < N - 2; i++)
    {
        int j = 1;
        while (i + j < N - 1)
        {
            if (card[i] + card[i + j] < M)
            {
                int k = 1;
                while (i + j + k < N)
                {

                    if (card[i] + card[i + j] + card[i + j + k] == M)
                        return card[i] + card[i + j] + card[i + j + k];
                    else if (card[i] + card[i + j] + card[i + j + k] < M && card[i] + card[i + j] + card[i + j + k] > max_sum)
                        max_sum = card[i] + card[i + j] + card[i + j + k];
                    k++;
                }
            }
            j++;
        }
    }
    return max_sum;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N >> M;
    card = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
    }
    cout << find();

    return 0;
}