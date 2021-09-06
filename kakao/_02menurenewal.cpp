#include <bits/stdc++.h>
using namespace std;
int cnt[30];
unordered_map<string, int> um;
vector<string> menu[30][30];

void combi(int idx, string order, string now)
{
    if (now.size() > 1)
    {
        um[now]++;
        cnt[now.size()] = max(cnt[now.size()], um[now]);
        menu[now.size()][um[now]].push_back(now);
    }
    for (int i = idx + 1; i < order.size(); i++)
    {
        now.push_back(order[i]);
        combi(i, order, now);
        now.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    for (string s : orders)
    {
        sort(s.begin(), s.end());
        combi(-1, s, "");
    }
    for (int i : course)
    {
        if (cnt[i] >= 2)
        {
            for (string s : menu[i][cnt[i]])
                answer.push_back(s);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

///////////다른 풀이
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> combi;

void combination(string src, string crs, int depth)
{
    if (crs.size() == depth)
        combi[crs]++;

    else
        for (int i = 0; i < src.size(); i++)
            combination(src.substr(i + 1), crs + src[i], depth);
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (string &order : orders)
        sort(order.begin(), order.end());

    for (int crs : course)
    {
        for (string order : orders)
            combination(order, "", crs);

        int sup = 0;
        for (auto it : combi)
            sup = max(sup, it.second);
        for (auto it : combi)
            if (sup >= 2 && it.second == sup)
                answer.push_back(it.first);
        combi.clear();
    }

    sort(answer.begin(), answer.end());
    return answer;
}
