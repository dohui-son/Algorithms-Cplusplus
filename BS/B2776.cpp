#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;
int t, n, m;
vector<int> a;
vector<int> b;

int go(int num)
{
    int l = 0, r = a.size() - 1, mid = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == num)
            return 1;
        else if (a[mid] < num)
            l = mid + 1;
        else if (a[mid] > num)
            r = mid - 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    int tmp = 0;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> tmp;
            b.push_back(tmp);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < b.size(); i++)
        {
            cout << go(b[i]) << endl;
        }
        a.clear();
        b.clear();
    }

    return 0;
}