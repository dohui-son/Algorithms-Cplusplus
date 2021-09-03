#include <iostream>
#include <vector>

using namespace std;
#define endl "\n";
int N;
vector<vector<int>> S;

vector<int> s;
int MIN = 1234567890;

void find_best_match(int cnt, int cur)
{

    //cout << k << endl;
    if (cnt == N / 2)
    {
        int A = 0, B = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == 1 && s[j] == 1)
                {
                    A += S[i][j];
                    A += S[j][i];
                }
                else if (s[i] == 0 && s[j] == 0)
                {
                    B += S[i][j];
                    B += S[j][i];
                }
            }
            //cout << "A, B " << A << " " << B << endl;
        }

        MIN = min(abs(A - B), MIN);
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (s[i] == 0 && cur < i)
            {
                s[i] = 1;
                find_best_match(cnt + 1, i);
                s[i] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    S = vector<vector<int>>(N, vector<int>(N));
    s = vector<int>(N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> S[i][j];
    }
    find_best_match(0, -1);
    cout << MIN;

    return 0;
}