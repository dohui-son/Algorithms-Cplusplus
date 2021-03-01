#include <iostream>
#include <vector>
#include <queue>

#define endl "\n";

using namespace std;
int N, K;
vector<int> locate;
queue<int> q;

int BFS(int n)
{

    q.push(n);
    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        if (K == idx)
            return locate[idx];
        if (idx + 1 < 200002 && locate[idx + 1] == 0)
        {
            locate[idx + 1] = locate[idx] + 1;
            q.push(idx + 1);
        }
        if (idx - 1 >= 0 && locate[idx - 1] == 0)
        {
            locate[idx - 1] = locate[idx] + 1;
            q.push(idx - 1);
        }
        if (idx * 2 < 200002 && locate[idx * 2] == 0)
        {
            locate[idx * 2] = locate[idx] + 1;
            q.push(idx * 2);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N >> K;

    locate = vector<int>(200002, 0);
    cout << BFS(N);

    return 0;
}