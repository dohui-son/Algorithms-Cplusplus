#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define endl "\n";

using namespace std;
vector<vector<int> > v;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    v = vector<vector<int> >(2, vector<int>(3, 0));
    cout << v.size();

    return 0;
}