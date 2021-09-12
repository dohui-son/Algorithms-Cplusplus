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

// struct Point
// {
//     //priority queue 에 int 외 다른 구조체가 들어갈때
//     int y, x;
//     Point(int y, int x)
// }

bool compare(const int &a, const int &b)
{
    return b <= a;
}
bool compare2(const pair<int, int> &a, const pair<int, int> &b)
{
    if (b.first == a.first)
        return b.second <= a.second;
    return b.first < a.first;
}

int main()
{

    //sort(vect.begin(), vect.end(), compare); //내림차순
    //vector<pair<int,int>> vectP;
    //sort(vectP.begin(), vectP.end(), compare2); //내림차순

    //priority_queue<intmvector<int>greater<int>>pq_greater;

    char s[50] = {
        0,
    };
    string str = "good morning";
    str += "  ";
    str += "space added";
    str = ""; // 초기화
    str = "\0";
    int initial[10] = {
        0,
    };
    int init2[10][10] = {{
        0,
    }};
    fill(s, s + 50, 0);
    memset(s, -1, sizeof(s));
    char c = '4';
    int to_int = c - '0';
    char C = 'C';
    to_int = C - 'A'; // 각 알파벳을 숫자로 나타낼때 유용하다.
    c = '\0';
    str = "";
    str = "111";
    str[2]++; // "112";

    v = vector<int>(5, 0);
    for (int i = 0; i < 5; i++)
    {
        scanf("%1d", &v[i]); //붙어있는 입력값 받기 <예시> 12345를 1 / 2...한글자씩
    }

    //개행문자 받기
    getline(cin, str);

    return 0;
}