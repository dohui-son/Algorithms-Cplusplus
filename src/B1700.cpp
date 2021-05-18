#include <bits/stdc++.h>

//페이징 스와핑...기술면접 기출

using namespace std;
#define endl "\n"
int visited[101], a[101];
int N,K;
deque<int>dq; 

int main(){ 
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    vector<int>v;
    for (int i = 0; i < K; i++)
    {
    	if(!visited[a[i]]){
    		if(v.size() == N){
    			//지우는 로직 
    			int last = 0; 
                for(int t : v){
                    for(int j =i+1; j<K; j++){
                        if( a[j] == t && last < j ){
                        	last = j; 
						} 
                    }
                }
                v.erase(find(v.begin(), v.end(), a[last]));
                v.push_back(a[i]);
                ans++;
			}
			//무조건 insert 
            visited[a[i]] = 1;
            v.push_back(a[i]);
		} 
    }
    cout << ans <<endl; 
    return 0;
}