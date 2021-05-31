#include<bits/stdc++.h>
using namespace std; 


typedef long long ll;
ll n, k, ret, temp1, temp;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k; 
	vector<pair<ll,ll>> dia(n);
	vector<ll> bag(k); 
	for(int i = 0; i < n; i++){
		cin >> dia[i].first >> dia[i].second; 
	}
	for(int i = 0; i < k; i++) cin >> bag[i]; 
	sort(dia.begin(), dia.end());
	sort(bag.begin(), bag.end());
	priority_queue<ll> pq; 
	
	int j = 0; 
	for(int i = 0; i < k; i++){
		while(j < n && dia[j].first <= bag[i]) pq.push(dia[j++].second);
		if(pq.size()){ //여기******
			ret += pq.top(); pq.pop();
		}
	} 
	cout << ret << "\n"; 
    
    
    
	return 0;
} 


