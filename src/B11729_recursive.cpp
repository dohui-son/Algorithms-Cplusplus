#include <iostream>
#include <vector>
#define endl "\n";
//20.2.24


using namespace std;
int N, counter = 0;
vector<vector<int>> ans;

int hanoi(int n, int from, int to)
{
    if (n == 0)
    {
        return 0;
    }
    counter++;
    int mid = 6 - from - to;
    hanoi(n - 1, from, mid);
    ans.push_back({from, to});
    hanoi(n - 1, mid, to);
    return counter;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> N;

    cout << hanoi(N, 1, 3) << endl;

    for (vector<int> t : ans)
    {
        cout << t[0] << " " << t[1] << endl;
    }

    return 0;
}