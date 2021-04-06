#include <iostream>
#include <vector>

#define endl "\n";

using namespace std;
int n, m;
bool check[9] = {
    0,
};
vector<int> v;


void solve(int cnt)
{

    if (m == cnt)
    {
        for (int i = 0; i < m; i++)
        {
            cout << v[i] << " ";
            
        }
        cout << endl;
    }

    else
    {
        for (int j = 1; j <= n; j++)
        {
            if (check[j] == 1)
                continue;
            check[j] = 1;
            v.push_back(j);
            solve(cnt + 1);
            v.pop_back();
            check[j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m;

    solve(0);
    return 0;
}