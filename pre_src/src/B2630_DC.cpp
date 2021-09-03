#include <iostream>
using namespace std;

#define endl "\n";
int n, blue, white;
int map[129][129];

void cut(int size, int row, int col)
{
    if (size == 1)
    {
        if (map[row][col])
            blue++;
        else
            white++;
        return;
    }

    bool avail = true;
    int first = map[row][col];
    for (int i = row; i < row + size; i++)
    {
        for (int j = col; j < col + size; j++)
        {
            if (map[i][j] != first)
            {
                avail = false;
                break;
            }
        }
        if (!avail)
            break;
    }
    if (avail)
    {
        if (first)
            blue++;
        else
            white++;
        return;
    }
    else
    {
        cut(size / 2, row, col);
        cut(size / 2, row + size / 2, col);
        cut(size / 2, row, col + size / 2);
        cut(size / 2, row + size / 2, col + size / 2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }

    cut(n, 1, 1);

    cout << white << endl;
    cout << blue << endl;

    return 0;
}
