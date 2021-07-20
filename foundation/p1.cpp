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
    //struct with custom sorting
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
        return x < a.x; //내림차순 x 기준
    }
};

struct percent
{
    int x, y;
    double w, d, l;
} sarr[6]; // cin >> sarr[0].x;

struct Point
{
    //priority queue with other struct (not int)
    int y, x;
    Point(int y, int x) : y(y), x(x) {}
    Point()
    {
        y = -1;
        x = -1;
    }
    bool operator<(const Point &p) const { return x > p.x; }
    //가장 작은 수가 top (x 기준)-greater
};

struct Ppoint
{
    int y, x;
};

struct cmp
{
    bool operator()(Ppoint a, Ppoint b)
    {
        if (a.x == b.x)
            return a.y <= b.y;
        return a.x < b.x;
    }
};

int main()
{
    cout << "priority q 다익스트라 그리디" << endl;
    cout << "priority queue with struct" << endl;
    priority_queue<Point> pq_struct;
    pq_struct.push({1, 10});
    pq_struct.push({2, 3});
    pq_struct.push({4, 5});
    pq_struct.push({6, 7});
    cout << pq_struct.top().x << endl; //3 가장 작은 수
    cout << pq_struct.top().y << endl; //2
    pq_struct.pop();
    cout << pq_struct.top().x << endl; //5
    cout << pq_struct.top().y << endl; //4

    priority_queue<Ppoint, vector<Ppoint>, cmp> pq;
    pq.push({1, 2});
    pq.push({10, 2});
    pq.push({11, 1});
    pq.push({4, 5});
    cout << "custom pq (==default) x " << pq.top().x << endl;  // 5
    cout << "cusotm pq (== default) y " << pq.top().y << endl; //4

    priority_queue<int, vector<int>, greater<int> > pq_greater; //greater
    pq_greater.push(2);
    pq_greater.push(0);
    cout << "greater -- pq.top은 가장 작은 수  " << pq_greater.top() << endl;
    priority_queue<int> default_q;
    default_q.push(2);
    default_q.push(0);
    cout << "default q - less(the biggest) " << default_q.top() << endl;

    char s[50] = {
        0,
    };
    string str = "good morning";
    str += " ";
    str += "space added";
    cout << str << endl;
    str = ""; //initialization
    str = '\0';
    cout << "str : " << str << "init" << endl;
    int initial[10] = {
        0,
    };
    for (int i : initial)
        cout << i << " ";
    cout << endl;

    cout << "2dm array initialization" << endl;
    int init2[10][10] = {{
        0,
    }};
    cout << "2중 배열 초기화" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << init2[i][j] << " ";
        }
        cout << endl;
    }
    char charact[10][10] = {{
        0,
    }};
    //char charact[10][10] = {{'\0',}};
    fill(s, s + 50, 0);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << charact[i][j]; // initialized
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            charact[i][j] = 'i';
            cout << charact[i][j] << " ";
        }
        cout << endl;
    }

    char c = '4';
    int to_int = c - '0'; // 정수형 4
    cout << "'4' - '0'"
         << "int " << to_int << endl;
    c = 'C';
    to_int = c - 'A' + 10; //int 12
    cout << "'C' - 'A' + 10; " << to_int << endl;
    cout << "'A' - 'A' " << 'A' - 'A' << endl;
    cout << " 'C' - 'A' " << 'C' - 'A' << endl;
    c = '\0';
    str = "123";
    str[0]++;
    cout << str << endl; //223

    v = vector<int>(5, 0); //171번째줄 *****

    return 0;
}