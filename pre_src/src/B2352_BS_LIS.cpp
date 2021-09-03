#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n";

vector<int> port, B;
int n;

int BS(int left, int right, int val)
{
    //최고 index를 리턴해주지만, 0번째 인덱스는 -1이므로 최종 출력시 (리턴값-1)을 해주어야함

    int ret = right;
    if (ret == 0)
    {
        B[1] = val;
        return ret + 1;
    }
    else
    {
        while (left <= right)
        {
            int mid = (left + right) / 2;
            //right-left ==1이면, mid에 left가 되기 때문에 else left=mid;라고 하면 무한루프를 돌아서 꼭 left=mid+1;을해줘야한다.
            if (B[mid] == val)
                return ret;
            if (left == right)
            {
                if (B[right - 1] < val)
                    B[right] = val;
                return ret;
            }
            else if (B[mid] > val)
            {
                right = mid;
            }
            else
                left = mid + 1;
        }
        return ret; // val과 동일한거 있으면 ret을 그대로 리턴 /
    }
}

int BS_LIS()
{
    int ret = 0;
    for (int i = 0; i < port.size(); i++)
    {
        //cout << "ret  " << ret << endl;
        if (port[i] == B[ret])
            continue;
        else if (port[i] > B[ret])
        {
            B[++ret] = port[i];
        }
        else
        {
            ret = BS(0, ret, port[i]);
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> n;
    port = vector<int>(n, 0);
    B = vector<int>(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> port[i];
    }
    cout << BS_LIS();

    return 0;
}