#include <iostream>
#include <vector>

#define endl "\n";

using namespace std;
vector<vector<int>> conference;
vector<int> greedy, time;

int N;

int find_max()
{
    int max = 0;

    return max;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;
    if (N == 1)
    {
        cout << 1;
        return 0;
    }
    conference = vector<vector<int>>(N, vector<int>(2, 0));
    greedy = vector<int>(N);
    time = vector<int>(N);

    for (int i = 0; i < N; i++)
    {
        cin >> conference[i][0] >> conference[i][1];
        greedy[i] = conference[i][1] - conference[i][0];
    }

    cout << find_max();

    return 0;
}