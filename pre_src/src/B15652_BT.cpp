#include <iostream>
#include <vector>

using namespace std;
#define endl "\n";
int N, M;
vector<int> v;

void dfs(int cnt, int num)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        for (int i = num; i <= N; i++)
        {
            v[cnt] = i;
            dfs(cnt + 1, i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> N >> M;
    v = vector<int>(M);
    dfs(0, 1);

    return 0;
}
