#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int s;
int64_t m;
char tmps[11];

void go(string str, int x)
{
    if (str[0] == 'a' && str[1] == 'd')
    {
        s |= (1 << x);
    }
    else if (str[0] == 'r')
    {
        s &= ~(1 << x);
    }
    else if (str[0] == 'c')
    {

        int tmp = ((s & (1 << x)) == 0 ? 0 : 1);
        cout << tmp << "\n";
    }
    else if (str[0] == 't')
    {
        s ^= (1 << x);
    }
    else if (str[0] == 'a' && str[1] == 'l')
    {
        s = (1 << 21) - 1;
    }
    else
    {
        s = 0;
    }
    return;
}

int main()
{
    scanf("%d", &m);
    int tmp = 0;

    while (m--)
    {
        scanf("%s %d", &tmps, &tmp);
        go(tmps, tmp);
    }

    return 0;
}
////////////////////숏코딩
#include <bits/stdc++.h>
using namespace std;
int n, m, x;
char s[11];
int main()
{
    scanf(" %d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf(" %s %d", &s, &x);
        if (s[0] == 'a' && s[1] == 'd')
            n |= (1 << x);
        else if (s[0] == 'r')
            n &= ~(1 << x);
        else if (s[0] == 'c')
            printf("%d\n", (n & (1 << x)) == 0 ? 0 : 1);
        else if (s[0] == 't')
            n ^= (1 << x);
        else if (s[0] == 'a' && s[1] == 'l')
            n = (1 << 21) - 1;
        else
            n = 0;
    }
}
