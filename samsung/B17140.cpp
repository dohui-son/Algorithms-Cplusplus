#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define endl "\n"
int R, C, K, ans, rs, cs;
vector<vector<int> > a(3, vector<int>(3, 0));
vector<int> rsize(3, 3);
vector<int> csize(3, 3);

void csort() {}
void rsort()
{
    for (int i = 0; i < a.size(); i++)
    {
        int zero_idx = min_element(a[i].begin(), a[i].end()) - a[i].begin();
        cout << zero_idx << endl;
        sort(a[i].begin(), a[i].begin() + zero_idx - 1); ////////////-1빼야하나????
        map<int, int> m;
        vector<pair<int, int> > cnt(101, {0, 0});
        for (int j = 0; j < zero_idx; j++)
        {
            m[a[i][j]]++;
            cout << "here" << endl;
            cnt[a[i][j]] = {m[a[i][j]], a[i][j]};

            /* code */
        }

        cout << "zero" << zero_idx << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> R >> C >> K;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    R--, C--;
    while (ans < 100)
    {
        if (a[R][C] == K)
            break;
        rs = *max_element(rsize.begin(), rsize.end());
        cs = *max_element(csize.begin(), csize.end());
        if (rs - cs >= 0)
        { //r정렬
            rsort();
        }
        else
        { //c 정렬
            csort();
        }

        ans++;
    }
    if (ans >= 100)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}