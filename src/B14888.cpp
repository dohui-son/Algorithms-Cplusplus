#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, mini = 987654321, maxi, cnt;
vector<int> num;
vector<int> cal(4, 0);

//int tmp_res = calculate(i, res, here + 1);
int calculate(int cal_idx, int f, int num_idx)
{
    int ret = 0;
    switch (cal_idx)
    {
    case 0: //+
        ret = f + num[num_idx];
        break;
    case 1: //-
        ret = f - num[num_idx];
        break;
    case 2: //*
        ret = f * num[num_idx];
        break;
    case 3: // /

        ret = f / num[num_idx];
        break;
    }
    return ret;
}

void go(int here, int res)
{
    cnt++; //이부분 매우 중요

    if (here == n)
    {
        if (cnt == n)
            maxi = mini = res;
        mini = min(mini, res);
        maxi = max(maxi, res);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (cal[i])
        {

            int tmp_res = calculate(i, res, here);
            cal[i]--;
            go(here + 1, tmp_res);
            cal[i]++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tmp = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        num.push_back(tmp);
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> cal[i];
    }
    go(1, num[0]);
    cout << maxi << endl;
    cout << mini << endl;

    return 0;
}

///////////////////////
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// #define endl "\n";
// int N, MAX, MIN, k = 0,input;

// vector<int> cal, num;

// void calculate(int res, int num_idx)
// {
//     k++;

//     if (num_idx == N)
//     {
//         if (k == N)
//         {
//             MAX = MIN = res;
//         }
//         MAX = max(MAX, res);
//         MIN = min(MIN, res);
//         return;
//     }
//     else
//     {

//         for (int i = 0; i < 4; i++)
//         {
//             if (cal[i] > 0)
//             {
//                 switch (i)
//                 {
//                 case 0:
//                     input = res+num[num_idx];
//                     break;
//                 case 1:
//                     input = res- num[num_idx];
//                     break;
//                 case 2:
//                     input = res * num[num_idx];
//                     break;
//                 case 3:
//                     input = res/num[num_idx];
//                     break;
//                 }

//                 cal[i]--;
//                 calculate(input, num_idx+1);
//                 cal[i]++;
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     cin >> N;
//     num = vector<int>(N);
//     cal = vector<int>(4);
//     for (int i = 0; i < N; i++)
//     {
//         cin >> num[i];
//     }

//     cin >> cal[0] >> cal[1] >> cal[2] >> cal[3]; // + - * /

//     calculate(num[0], 1);

//     cout << MAX << endl;
//     cout << MIN << endl;

//     return 0;
// }