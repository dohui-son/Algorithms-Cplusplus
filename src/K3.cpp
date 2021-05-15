#include <bits/stdc++.h>
#include <string>

using namespace std;

#define endl "\n";


string solution(int n, int k, vector<string> cmd) {
	// n처음 표의 행개수    k처음선택된 행 위치       cmd수행한 명령어 담긴 문자열배열
    
	vector<char>ans(n, 'O');
	string answer(ans.begin(), ans.end());


	int pre_idx = -1, now = k,pre_d = -1, dis = 0;
	for (int i = 0; i < cmd.size(); i++)
	{
		if (cmd[i][0] == 'U') { 
			dis = stoi(cmd[i].substr(2,cmd[i].size()-1)); 
			int tmp = 1;
			int next = 0;
			while(tmp != dis){ 
				if (ans[now - tmp] == 'O') {
					tmp++;
					next = now - tmp;
				}
			}
			now = next;

		}
		else if (cmd[i][0] == 'D') {
			dis = stoi(cmd[i].substr(2, cmd[i].size() - 1));
			int tmp = 1;
			int next = 0;
			while (tmp != dis) {
				if (ans[now + tmp] == 'O') {
					tmp++;
					next = now + tmp;
				}
			}
			now = next;
		}
		else if (cmd[i][0] == 'C') {
			string fisrt = "", second="";

			if(now)

		}
		else if (cmd[i][0] == 'Z') {}
		
	}

	
	//삭제되지 않은 행은 O, 삭제된 행은 X로 표시하여 문자열 형태로 return
    return answer;
}


int main() {
	return 0;
}