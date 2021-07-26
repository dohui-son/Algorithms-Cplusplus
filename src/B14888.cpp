#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl "\n";
int N, MAX, MIN, k = 0, input;

vector<int> cal, num;

void calculate(int res, int num_idx)
{
    k++;

    if (num_idx == N)
    {
        if (k == N)
        {
            MAX = MIN = res;
        }
        MAX = max(MAX, res);
        MIN = min(MIN, res);
        return;
    }
    else
    {

        for (int i = 0; i < 4; i++)
        {
            if (cal[i] > 0)
            {
                switch (i)
                {
                case 0:
                    input = res + num[num_idx];
                    break;
                case 1:
                    input = res - num[num_idx];
                    break;
                case 2:
                    input = res * num[num_idx];
                    break;
                case 3:
                    input = res / num[num_idx];
                    break;
                }

                cal[i]--;
                calculate(input, num_idx + 1);
                cal[i]++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> N;
    num = vector<int>(N);
    cal = vector<int>(4);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    cin >> cal[0] >> cal[1] >> cal[2] >> cal[3]; // + - * /

    calculate(num[0], 1);

    cout << MAX << endl;
    cout << MIN << endl;

    return 0;
}