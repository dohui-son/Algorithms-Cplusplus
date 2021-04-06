#include <iostream>

#define endl "\n";

using namespace std;
int n;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n;
    if (n <= 0)
    {
        cout << 0;
        return 0;
    }
    if (0 < n && n < 3)
        cout << n;
    else
        cout << n * (n - 1) * (n - 2);

    return 0;
}