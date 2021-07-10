#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n";
typedef unsigned long long ll;
const int INF = 987654321;
int n;
double temp;
priority_queue<double> pq;
vector<double> v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pq.push(temp);
        if (pq.size() == 8)
            pq.pop();
    }
    while (pq.size())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());
    for (double i : v)
        printf("%.3lf\n", i);

    return 0;
}