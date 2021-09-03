#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    A = A % C;
    vector<int> bits;
    vector<int> remainders;

    int res = 1;
    while (B > 0)
    {
        remainders.push_back(A);
        bits.push_back(B % 2);
        A = (A * A) % C;
        B /= 2;
    }
    for (int i = 0; i < bits.size(); i++)
    {
        cout << "i: " << i << "," << bits[i] << ": " << remainders[i] << endl;
        if (bits[i] == 1)
        {
            res *= remainders[i];
            res %= C;
        }
    }
    cout << res;
}
