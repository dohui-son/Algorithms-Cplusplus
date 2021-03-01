#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl "\n";

using namespace std;
int Y, X;
vector<string> chess;
int start_wh(int y, int x);
int start_bl(int y, int x);
int count_min();

int start_wh(int y, int x)
{
    int count = 0;
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (chess[i][j] != 'W')
                    count++;
            }
            else
            {
                if (chess[i][j] != 'B')
                    count++;
            }
        }
    }
    return count;
}

int start_bl(int y, int x)
{
    int count = 0;
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (chess[i][j] != 'B')
                    count++;
            }
            else
            {
                if (chess[i][j] != 'W')
                    count++;
            }
        }
    }
    return count;
}

int count_min()
{
    int ret = 64;
    int y = 0;
    int x = 0;
    while (y + 7 < Y)
    {
        int x = 0;
        while (x + 7 < X)
        {
            ret = min(ret, min(start_bl(y, x), start_wh(y, x)));

            x++;
        }
        y++;
    }

    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> Y >> X;
    chess = vector<string>(Y);
    string str;
    for (int i = 0; i < Y; i++)
    {
        cin >> str;
        chess[i] = str;
    }
    cout << count_min();

    return 0;
}