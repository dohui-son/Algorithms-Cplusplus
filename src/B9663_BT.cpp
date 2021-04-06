#include <iostream>
#include <vector>

using namespace std;
#define endl "\n";

vector<int> col;
int N, cases = 0;

bool check(int level)
{
    for (int i = 0; i < level; i++)
    {
        if (col[i] == col[level] || abs(col[i] - col[level]) == level - i)
            return false;
    }
    return true;
}

void N_QUEEN(int x)
{
    if (x == N)
        cases++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[x] = i;
            if (check(x))
                N_QUEEN(x + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;
    col = vector<int>(N);
    N_QUEEN(0);

    cout << cases;
    return 0;
}