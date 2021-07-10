#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long ll;
using namespace std;
#define endl "\n";

int n, k;
ll m, v, c, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;

	vector<pair<ll, ll> > dia(n);
	vector<ll> bag(k);
	priority_queue<ll> pq;

	for (int i = 0; i < n; i++)
	{
		cin >> dia[i].first >> dia[i].second;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> bag[i];
	}
	sort(dia.begin(), dia.end());
	sort(bag.begin(), bag.end());
	int idx = 0;
	for (int i = 0; i < k; i++)
	{
		while (idx < n && dia[idx].first <= bag[i])
			pq.push(dia[idx++].second);
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}