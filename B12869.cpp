#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"
int N;
int ans = 987654321;
vector<int>scv;


void BT(int cnt) {
	cout << "cnt   " << cnt << endl;
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		if (scv[i] > 0)sum += scv[i];
	}
	if (sum <= 0) {
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		rotate(scv.begin(), scv.begin() + scv.size() - 1, scv.end());
		scv[2] -= 9;
		scv[1] -= 3;
		scv[0] -= 1;
		BT(cnt + 1);
		scv[2] += 9;
		scv[1] += 3;
		scv[0] += 1;
		rotate(scv.begin(), scv.begin() + 1, scv.end());
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int tmp = 0,sum=0;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		scv.push_back(tmp);
	}
	sort(scv.begin(), scv.end());
	BT(0);

	//while (sum > 0) {
	//	sort(scv.begin(), scv.end());
	//	for (auto v : scv)cout << v << " ";
	//	cout << endl;
	//	int attack = 9;
	//	sum = 0;
	//	for (int i = N-1; i >=0; i--)
	//	{
	//		scv[i] -= attack;
	//		attack /= 3;
	//		if (scv[i] < 0)continue;
	//		sum += scv[i];
	//		
	//	}
	//	ans++;
	//}
	cout << ans;

	return 0;



}