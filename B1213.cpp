////#include <iostream>
////#include <vector>
////#include <string>
////#include <map>
////#include<algorithm>
////
////using namespace std;
////#define endl "\n"
////
////int main() {
//	//ios::sync_with_stdio(false);
//	//cin.tie(nullptr);
//	//cout.tie(nullptr);
//	
//	/*for (int i = 0; i < str.size(); i++)
//	{
//		if (m.find(str[i]) == m.end()) { m.insert({ str[i], 1 }); }
//		else { m[str[i]]++; }
//	}
//	int odd = 0;
//	for (auto iter : m)
//	{
//		if (iter.second % 2 != 0)odd++;
//	}
//	if (odd > 1) {
//		cout << "I'm Sorry Hansoo";
//	}
//	else {
//
//	}*/
//
//	//두번째 시도
//	//string str;
//	//vector<int> vect;
//	//map<char, int>m;
//	//int tmp = 0;
//	//getline(cin, str);
//	//for (int i = 0; i < str.size(); i++)
//	//{
//	//	vect.push_back(str[i]);
//	//	if (m.find(str[i]) != m.end())m[str[i]]++;
//	//	else { m.insert({ str[i], 1 }); }
//	//}
//	//int idx = 0;
//	//vector<char> ans(50,0);
//	//tmp = 0;
//	//int i = 0;
//	//int j = 0;
//	//
//	//while(j < str.size()/2)
//	//{
//	//	
//	//	if (m[vect[i]] % 2 != 0) {
//	//		tmp++;
//	//		//짝수 다 들어가고 들어가야하는데....
//	//		
//	//		if (tmp > 1){
//	//			cout << "I'm Sorry Hansoo";
//	//			return 0;
//	//		}
//	//		int idx = str.size() / 2;
//	//		int tmp2 = m[vect[i]] / 2 ;
//	//		while (tmp2>0) {
//	//			ans[idx] = (char)vect[i];
//	//			idx--;
//	//			tmp2--;
//	//		}
//	//	}
//	//	else {
//	//		
//	//		int total = 1;
//	//		while (total < m[vect[i]] /2)
//	//		{
//	//			
//	//			ans[j] = (char)vect[i];
//	//			total++;
//	//			j++;
//	//		}
//	//	}
//	//	i++;
//	//}
//	//for (int i = 0; i < str.size()/2; i++)
//	//{
//	//	cout << ans[i];
//	//}
////	return 0;
////}
//
//#include<bits/stdc++.h> 
//using namespace std;
//string s, ret;
//int cnt[200], flag;
//char mid;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> s;
//	for (char a : s)cnt[a]++;
//	for (int i = 'Z'; i >= 'A'; i--) {
//		if (cnt[i]) {
//			if (cnt[i] & 1) {
//				mid = char(i); flag++;
//				cnt[i]--;
//			}
//			if (flag == 2)break;
//			for (int j = 0; j < cnt[i]; j += 2) {
//				ret = char(i) + ret;
//				ret += char(i);
//			}
//		}
//	}
//	if (mid)ret.insert(ret.begin() + ret.size() / 2, mid);
//	if (flag == 2)cout << "I'm Sorry Hansoo\n";
//	else cout << ret << "\n";
//}