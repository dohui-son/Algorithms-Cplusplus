#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int n, x, y, d, gen;
int g[102][102];
struct Input
{
    int x, y, d, g;
};
vector<Input> a;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> dragon;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> d >> gen;
        if (d == 0)
            d = 1;
        else if (d == 1)
            d = 0;
        else if (d == 2)
            d = 3;
        else if (d == 3)
            d = 2;
        a.push_back({x, y, d, gen});
        cout << a[i].g << endl;
    }

    return 0;
}