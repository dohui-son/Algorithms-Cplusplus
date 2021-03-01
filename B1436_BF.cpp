//영화감독 숌
#include <iostream>
#include <vector>
#include <string>

#define endl "\n";

using namespace std;
int N;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;
    if (N == 1)
    {
        cout << 666;
        return 0;
    }
    int num = 1665;
    int count = 1;
    while (1)
    {
        num++;
        string str = to_string(num);
        if (-1 != str.find("666"))
        {
            count++;
            if (count == N)
            {
                cout << num;
                return 0;
            }
        }
    }

    return 0;
}