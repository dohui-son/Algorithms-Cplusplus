//멀티탭스케줄링
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n";
const int INF = 987654321;

int k, n, a[104], visited[104], cnt;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (!visited[a[i]])
        { //지금 멀티탭에 안 꽂혀있음
            if (v.size() == k)
            { //멀티탭 꽉 찼음
                int last_idx = 0, off_idx;
                for (int _a : v)
                {
                    int here_pick = INF;

                    for (int j = i + 1; j < n; j++)
                    {
                        if (_a == a[j])
                        {
                            here_pick = j;
                            break;
                        }
                    }
                    if (last_idx < here_pick)
                    { //here_pick을 INF로 해줌으로서 걔가 앞으로 다시 나오지 않는다면 무조건 바꿔줌
                        last_idx = here_pick;
                        off_idx = _a;
                    }
                }
                visited[off_idx] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), off_idx));
            }
            v.push_back(a[i]);
            visited[a[i]] = 1;
        }
    }
    cout << cnt << endl;
    return 0;
}