#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;
int n, mp, mf, ms, mv, p, f, s, v, c, ans = 987654321, kk;
struct food
{
    int p, f, s, v, c;
};
vector<pair<int, int> > picked;
vector<food> input;

bool combi(int start, vector<pair<int, int> > &b, int pp, int ff, int ss, int vv, int &cost)
{
    if (b.size() == kk)
    {
        if (pp >= mp && ff >= mf && ss >= ms && vv >= mv)
            return true;
        else
            return false;
    }
    for (int i = 1 + start; i < n; i++)
    {
        b.push_back({input[i].c, i});
        int money = cost + input[i].c;
        combi(i, b, pp + input[i].p, ff + input[i].f, ss + input[i].s, vv + input[i].v, money);
        b.pop_back();
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> f >> s >> v >> c;
        input.push_back({p, f, s, v, c});
    }
    //가격 //idx
    int cost = 0, idx = 0;
    for (int i = 0; i < n; i++)
    {
        kk = i;
        vector<pair<int, int> > pick_idx;
        cost = 0;
        if (combi(-1, pick_idx, 0, 0, 0, 0, cost))
        {
            if (ans > cost)
            {
                ans = cost;
                picked = pick_idx;
            }
        }
    }
    cout << cost;

    return 0;
}
