#include <iostream>
#include <string>

#define endl "\n";

using namespace std;
int N;
string N_str; //자리수 sizeof(NN)

int smallest_s()
{
    int start = (N / 2);
    while (start < N)
    {
        int ans = start;
        string str = to_string(start);
        for (int i = 0; i < str.size(); i++)
        {

            ans += str[i] - '0';
        }

        if (ans == N)
            return start;
        start++;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N_str;

    N = stoi(N_str);

    if (N <= 1)
    {
        cout << 0;
        return 0;
    }

    cout << smallest_s();

    return 0;
}