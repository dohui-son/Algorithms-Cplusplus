#include <bits/stdc++.h>
#include <string>

using namespace std;

#define endl "\n";


string solution(int n, int k, vector<string> cmd) {
	// nó�� ǥ�� �ళ��    kó�����õ� �� ��ġ       cmd������ ��ɾ� ��� ���ڿ��迭
    
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

	
	//�������� ���� ���� O, ������ ���� X�� ǥ���Ͽ� ���ڿ� ���·� return
    return answer;
}


int main() {
	return 0;
}