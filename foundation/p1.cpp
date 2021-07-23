#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <tuple>
#include <set>
#include <stack>
#include <queue>

using namespace std;
#define endl "\n"

void make_permutation(int n, int r, int depth);
void combi(int start, vector<int> &b);

vector<int> v;
int n = 3, k = 2;
void b2(int &a) { a = 2; }
void b3(int *a) { *a = 3; }
void arrs(int a[][10]) { a[0][4] = 44; }

struct P
{
    //struct with custion sorting
    int y, x;
    P(int y, int x) : y(y), x(x) {}
    P()
    {
        y = -1;
        x = -1;
    }
    bool operator<(const P &a) const
    {
        if (x == a.x)
            return y < a.y;
        return x < a.x; //내림차순 -- x기준
    }
};

struct percent
{
    int x, y;
    double w, d, l;
} sarr[6]; //한정 cin>> sarr[0].x;

struct Point
{
    //priority queue 에 int 외 다른 구조체가 들어갈때
    int y, x;
    Point(int y, int x)
}
