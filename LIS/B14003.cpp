#include <cstdio> ///nlogn
#include <algorithm>
#include <stack>
using namespace std;
int n, lis[1000004], len, num;
pair<int, int> ans[1000004];
stack<int> stk;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        if (*lowerPos == 0)
            len++;
        *lowerPos = num;
        ans[i].first = _pos;
        ans[i].second = num;
    }
    printf("%d\n", len);
    int l = len - 1;

    //for(int i = 0; i < n; i++)printf("%d %d\n", ans[i].first, ans[i].second);
    for (int i = n - 1; i >= 0; i--)
    {
        if (ans[i].first == l)
        {
            stk.push(ans[i].second);
            l--;
        }
    }
    while (stk.size())
    {
        printf("%d\n", stk.top());
        stk.pop();
    }
    return 0;
}

/*
8
1 6 2 5 7 3 5 6  
*/