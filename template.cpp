#include <iostream>
#include <vector>

#define endl "\n";

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cout << "Hello, World!" << endl;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        cout << tmp << endl;
    }

    return 0;
}