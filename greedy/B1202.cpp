#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define endl "\n";

int n, k;
vector<pair<int64_t, int64_t> > dia;
vector<int64_t> bag;
int64_t m, v, ans, c;
priority_queue<int64_t> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		dia.push_back({m, v});
	}
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		bag.push_back(c);
	}
	sort(dia.begin(), dia.end());
	sort(bag.begin(), bag.end());
	int idx = 0;
	for (int i = 0; i < k; i++)
	{
		while (idx < n && dia[idx].first <= bag[i])
			pq.push(dia[idx++].second);
		if (pq.size())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;

	return 0;
}