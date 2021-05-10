#include <bits/stdc++.h>

//비트마스킹

using namespace std;

#define endl '\n'
int n;
vector<vector<bool>> g(100, vector<bool>(100,false));
vector<int> popul(100);
int ans = 987654321;


//방문한 정점을 
int BFS(bool now,vector<bool>& v, vector<bool>&visited) {
	
	queue<int>q;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] == false && v[i] == now)
		{
			q.push(i);
			visited[i] = true;
			ret += popul[i];
			break;
		}
	}
	

	while (!q.empty())
	{
		
		int turn = q.front(); 
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && v[i] == now && g[turn][i] ) {
				visited[i] = true;
				ret += popul[i];
		
				q.push(i);
			}
		}
	}
	return ret;
}



int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
    int total =0 ;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> popul[i];
		total += popul[i];
	}
	
	int tmp = 0, tmp2=0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = 0; j < tmp; j++)
		{
			cin >> tmp2;
			g[i][tmp2 - 1] = true;
			g[tmp2 - 1][i] = true;
		}
	}
	for (int i = 1; i < (1<<n); i++)
	{
		vector<bool>div(n, false);
		int blue = 0, red = 0, tmp = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) {
				div[j] = true;
				tmp += 1;
			}
		}
		for (auto i : div)cout << i << " ";
		cout << endl;

		if (tmp == n)continue;
		
		vector<bool>visit(100, false);
		red = BFS(div[0],div, visit);
		blue = BFS(!div[0], div, visit);
		if (red + blue == total)ans = min(ans, abs(red - blue));
	}
	if (ans == 987654321) { cout << -1; return 0; }
	cout << ans;

	return 0;
}