#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n";
int n, start, link;
int s[21][21];
vector<int>v;

void BT(){
    if(total == n/2){
       
        

        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }
    BT();


    return 0;
}