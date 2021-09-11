#include <bits/stdc++.h>

using namespace std;
vector<int> g[3][1 << 3];   // [개발언어][직군(backend)/경력(junior)/소울푸드(chicken)]
vector<pair<int, int> > cp; //사람 숫자 저장해둔 벡터의 idx
vector<int> score;

void make_g(vector<string> &inf)
{
    for (string s : inf)
    {
        int idx = 0, f = 0, sec = 0;
        if (s[0] == 'c')
        {
            f = 0;
            idx += 4;
        }
        else if (s[0] == 'j')
        {
            f = 1;
            idx += 5;
        }
        else if (s[0] == 'p')
        {
            f = 2;
            idx += 7;
        }

        for (int i = 0; i < 3; i++)
        {
            if (s[idx] == 'b')
            {
                sec |= (1 << i);
                idx += 8;
            }
            else if (s[idx] == 'f')
            {
                idx += 9;
            }
            else if (s[idx] == 'j')
            {
                sec |= (1 << i);
                idx += 7;
            }
            else if (s[idx] == 's')
            {
                idx += 7;
            }
            else if (s[idx] == 'c')
            {
                sec |= (1 << i);
                idx += 8;
            }
            else if (s[idx] == 'p')
            {
                idx += 6;
            }
        }
        string str = "";
        for (int i = idx; i < s.size(); i++)
        {
            str += s[i];
        }
        g[f][sec].push_back(stoi(str));
        score.push_back(stoi(str));
    }
    sort(score.begin(), score.end());
}

void make_ans(vector<string> &q, vector<int> &ans)
{
    for (string s : q)
    {
        int f = 0, sec = 0, idx = 0, cnt = 0, secsec = 0;
        v //'-'는 -1
            if (s[0] == '-')
        {
            idx += 6;
            cnt++;
            f = -1;
        }
        else if (s[0] == 'c') { idx += 8; }
        else if (s[0] == 'j')
        {
            idx += 9;
            f = 1;
        }
        else if (s[0] == 'p')
        {
            idx += 11;
            f = 2;
        }

        for (int i = 0; i < 3; i++)
        {
            if (s[idx] == '-')
            {
                idx += 6;
                cnt++;
                if (cnt == 4)
                    break;
                secsec |= (1 << i);
            }
            else if (s[idx] == 'b')
            {
                idx += 12;
                sec |= (1 << i);
            }
            else if (s[idx] == 'f')
            {
                idx += 13;
            }
            else if (s[idx] == 'j')
            {
                idx += 11;
                sec |= (1 << i);
            }
            else if (s[idx] == 's')
            {
                idx += 11;
            }
            else if (s[idx] == 'c')
            {
                idx += 12;
                sec |= (1 << i);
            }
            else if (s[idx] == 'p')
            {
                idx += 11;
            }
        }
        string str = "";
        for (int i = idx; i < s.size(); i++)
        {
            if (s[i] == '-')
            {
                cnt++;
                break;
            }
            str += s[i];
        }

        int sc = stoi(str);
        if (cnt == 4)
        {
            int n = (int)(lower_bound(score.begin(), score.end(), sc) - score.begin());
            ans.push_back(score.size() - n);
            continue;
        }
        if (secsec == 0)
        {
            if (g[f][sec].size())
            {
                int n = (int)(lower_bound(g[f][sec].begin(), score[f][sec].end(), sc) - g[f][sec].begin());
                ans.push_back(g[f][sec].size() - n);
            }
            else
            {
                ans.push_back(0);
            }
        }
        else
        {
            for (int i = 0;)
        }
    }
}
vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> ans;
    make_g(info);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < (1 << 3); j++)
        {
            if (g[i][j].size())
            {
                sort(g[i][j].begin(), g[i][j].end());
            }
        }
    }
    //make_ans(query, ans);

    return ans;
}