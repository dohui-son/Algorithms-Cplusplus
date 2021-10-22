#include <stdio.h>
int N, M, d, s, idx[50][50], n, ans;
int dr[4] = {0, -1, 1, 0};
int dc[4] = {1, 0, 0, -1};

typedef struct Line
{
    int arr[2500];
} Line;
Line map, next, init;

void numbering(int r, int c)
{
    idx[r][c] = n++;
}

void indexing()
{
    numbering(N / 2, N / 2);
    for (int i = N / 2; i >= 0; i--)
    {
        int e = N - 1 - i;

        for (int j = i + 1; j <= e; j++)
            numbering(j, i);
        for (int j = i + 1; j <= e; j++)
            numbering(e, j);
        for (int j = e - 1; j >= i; j--)
            numbering(j, e);
        for (int j = e - 1; j >= i; j--)
            numbering(i, j);
    }
}

void blizzard()
{
    int r = N / 2;
    int c = N / 2;

    for (int i = 1; i <= s; i++)
    {
        int rr = r + i * dr[d];
        int cc = c + i * dc[d];

        map.arr[idx[rr][cc]] = 0;
    }

    next = init;
    int cur = 1;
    for (int i = 1; i < n; i++)
    { //n=N*N
        if (map.arr[i])
            next.arr[cur++] = map.arr[i];
    }
    map = next;
}

int bomb()
{
    int flag = 0, lb = 1, ub = 1, cur = 1;
    next = init;

    for (int i = 2; i < n; i++)
    {
        if (map.arr[i] != map.arr[i - 1])
        {
            ub = i - 1;

            if (ub - lb + 1 >= 4)
            {
                flag = 1;
                ans += map.arr[ub] * (ub - lb + 1);
            }
            else
            {
                for (int j = lb; j <= ub; j++)
                    next.arr[cur++] = map.arr[j];
            }

            if (!map.arr[i])
                break;
            lb = i;
        }
    }

    map = next;
    return flag;
}

void rearrange()
{
    int lb = 1, ub = 1, cur = 1;
    next = init;

    for (int i = 2; i < n; i++)
    {
        if (map.arr[i] != map.arr[i - 1])
        {
            ub = i - 1;
            next.arr[cur++] = ub - lb + 1;
            if (cur >= n)
                break;
            next.arr[cur++] = map.arr[ub];
            if (!map.arr[i] || cur >= n)
                break;
            lb = i;
        }
    }
    map = next;
}

int main()
{
    scanf(" %d %d", &N, &M);
    indexing();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf(" %d", &map.arr[idx[i][j]]);
    for (int t = 0; t < M; t++)
    {
        scanf(" %d %d", &d, &s);
        d %= 4;
        blizzard();
        while (bomb())
            ;
        rearrange();
    }
    printf("%d", ans);
    return 0;
}