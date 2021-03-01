#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M;
    vector<int> A;
    cin >> N;
    A = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        cout << binary_search(A.begin(), A.end(), M) << endl;
    }

    return 0;
}