////한번에 성공
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//#define endl "\n"
//
//vector<int> t,p,planner;
//int n, ans=0;
//int last_day = 0;
//queue<int>q;
//
//
//bool plan(queue<int>& qq, vector<int>& pl, int start) {
//	//cout << "start+t[start]  " << start + t[start] << endl;
//	if (pl[start] != 0) {
//		return false;
//	}
//	for (int i = start; i < start+t[start]; i++)
//	{
//		
//		
//			//cout << "start " << start << endl;
//			//cout << "i " << i << " pl[i] " << pl[i] << endl;
//			if (pl[i] != 0)return false;
//			
//			pl[i] = 1;			
//			//cout << "i " << i << " pl[i] " << pl[i] << endl;
//		
//	}
//	//cout << endl;
//	queue<int> tmp_q = qq;
//	tmp_q.push(start);
//	int payment=0;
//	while (!tmp_q.empty())
//	{
//		int date = tmp_q.front();
//		//cout << "date " << date << endl;
//		tmp_q.pop();
//		payment += p[date];
//		ans = max(payment, ans);
//		//cout << "ans   " << ans << endl;
//	}
//	//cout << endl;
//	return true;
//}
//
//
//void BT(int start,vector<int>& planner, queue<int>& q) {
//	if (start >= n)return;
//	else {
//		for (int i = start; i <= last_day; i++)
//		{
//
//			if (t[i] + i > n) continue;
//			vector<int> temp = planner;
//			
//			
//			if (plan(q, temp, i)) {
//				
//				//cout << "i " << i << endl;
//				queue<int>temp_q = q;
//				temp_q.push(i);
//				//cout <<"temp_q.size  "<< temp_q.size() << endl;
//				
//				BT(i + 1, temp, temp_q);
//			}
//			else{}
//		}
//	}
//}
//
//
//int main() {
//	cin >> n;
//	t = vector <int>(n);
//	p = vector <int>(n);
//	planner = vector<int>(n,0);
//	
//	for (int i = 0; i < n; i++)
//	{
//		cin >> t[i] >> p[i];
//		if (i + t[i] <= n) { last_day = i; }
//
//	}
//
//	BT(0,planner,q);
//	cout << ans;
//
//
//
//
//	return 0;
//}