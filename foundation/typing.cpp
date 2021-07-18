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

vector<int> v;
int n = 3, k = 2;

struct P
{ //struct with custom sorting

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
        return x < a.x;
    }
};

struct Point
{
    int y, x;
    Point(int y, int x) : y(y), x(x) {}
    Point()
    {
        y = -1;
        x = -1;
    }
    bool operator<(const Point &p) const { return x > p.x; } //오름차순
};
struct Ppoint
{
    int y, x;
};
struct cmp
{
    bool operator()(Ppoint a, Ppoint b) { return a.x < b.x; }
}; //내림차순

int main()
{
    priority_queue<Point> pq_struct;
    pq_struct.push({1, 10});
    pq_struct.push({2, 3});
    pq_struct.push({4, 5});
    pq_struct.push({6, 7});
    cout << "pq_struct " << pq_struct.top().x << endl;
    cout << "pq_struct " << pq_struct.top().y << endl;

    priority_queue<Ppoint, vector<Ppoint>, cmp> pq; //less
    pq.push({1, 2});
    pq.push({10, 1});
    pq.push({11, 1});
    pq.push({4, 5});
    cout << "custom pq less  " << pq.top().x << endl;
    cout << "custom pq less  " << pq.top().y << endl;

    //priority_queue 다익스트라 그리디
    priority_queue<int, vector<int>, greater<int> > pq_up; //오름차순
    priority_queue<int> pq_down;
    for (int i = 7; i > 0; i--)
    {
        pq_up.push(i);
        cout << "pq_up  <greater<int>> " << pq_up.top() << endl;

        pq_down.push(i);
        cout << "pq_down default " << pq_down.top() << endl;
    }

    char s[50] = {
        0,
    };
    string str = "good morning";
    str += " ";
    str += "space added";
    cout << str << endl;
    str = ""; //string init
    cout << "str: " << str << "init" << endl;
    int initial[10] = {
        0,
    };
    for (int i : initial)
        cout << i << " ";
    cout << endl;
    for (char i : s)
        cout << i << " ";
    cout << "char s[50] = {0,} initialized " << endl;
    fill(s, s + 50, 0); //char vector초기화
    for (char i : s)
    {
        cout << i << endl;
        cout << "char vector 초기화 완료 ";
    }
    cout << endl;

    char c = '4';
    int to_int = c - '0'; ///정수형 4
    cout << "'4'-'0' " << to_int << endl;
    c = 'C';
    to_int = c - 'A' + 10; // 정수형 12
    cout << "'C'-'A'+10 " << to_int << endl;

    c = '\0'; // char 형 초기화 - null 인 \0
    cout << "c : "
         << c << "char init done " << endl;
    str = "123";
    str[0]++;
    cout << str << endl; //223;

    //입력시 붙어있을때
    v = vector<int>(5, 0);
    for (int i = 0; i < 5; i++)
    {
        scanf("%1d", &v[i]);
        cout << "after scanf(\"%1d\", &v[i]): " << v[i] << endl;
    }
    getline(cin, str); //개행문자 있는 입력

    //입력을 주다가 안 줄때 끝난다고 명시되어있을때***
    while (scanf("%d", &to_int) != EOF)
    {
    }
    while (cin >> to_int)
    {
    }

    double a1 = 3.2;
    double a2 = 3.7;
    double a3 = -3.2;
    double a4 = -3.7;
    cout << "[C++] round 반올림 example" << endl;
    cout << "round(3.2) : " << round(a1) << endl;
    cout << "round(3.7) : " << round(a2) << endl;
    cout << "round(-3.2) : " << round(a3) << endl; //-3
    cout << "round(-3.7) : " << round(a4) << endl; //-4

    //올림 함수
    cout << " ceil(4.3) " << ceil(4.3) << endl;
    cout << " ceil(-4.3) " << ceil(-4.3) << endl; // -4 ***
    //내림 함수
    cout << " floor(4.7) " << floor(4.7) << endl;
    cout << " floor(-4.7) " << floor(-4.7) << endl; // -5
    //소수점 아래는 다 없애는 함수 c++11
    cout << "trunc(-4.7) " << trunc(-4.7) << endl; // -4
    cout << "trunc(4.7) " << trunc(4.7) << endl;   //  4

    to_int = (int)c * 100;
    to_int = (int)100 * c; //형변환 안됨

    //asci code A-Z 65-90
    //asci code a-z 97-122
    //a에서 z까지 입력 받는데 이를 정수로 0-26으로 표현
    c = 'a';
    cout << (int)c - 97 << endl;  // 0
    cout << (int)c - 'a' << endl; // 0

    str = "this is string";
    cout << str.substr(0, 3) << endl; //시작 지점으로부터 몇개 문자열 뽑아내기
    cout << str.substr(1, 3) << endl; // idx 1로부터 3개 문자열 뽑아내기
    reverse(str.begin(), str.end());
    cout << str << endl;
    reverse(str.begin(), str.begin() + 6);
    cout << str << endl;
    auto au = find(str.begin(), str.end(), 'i');
    cout << "*au printed  " << *au << endl;
    if (au == str.end())
        cout << "not found" << endl;
    str.erase(str.begin(), str.begin() + 2);
    cout << str << endl;

    string strr = "hello for the fine";
    if (strr.find("hi") == string::npos)
        cout << "string::npos " << endl;
    pair<int, int> pi;
    pi = {1, 2};
    int num1 = 0, num2 = 0, num3 = 0;
    tie(num1, num2) = pi;
    cout << num1 << " " << num2 << endl;
    tuple<int, int, int> tl;
    tl = {1, 2, 3};
    tie(num1, num2, num3) = tl;
    cout << num1 << num2 << num3 << endl;

    v.push_back(100);
    v.pop_back();
    for (int i : v)
        cout << "v  " << i << " "; //2 7 2 3 2
    cout << endl;
    v.erase(v.begin() + 2, v.begin() + 3); //부터 -"전"까지
    for (int i : v)
        cout << "v " << i << " "; // 2 7 3 2
    cout << endl;

    auto aut = find(v.begin() + 2, v.end(), 7);
    if (aut == v.end())
        cout << "no 7" << endl;
    else
        cout << *aut << endl;
    fill(v.begin(), v.end(), 10);
    v.clear(); //사이즈를 0으로 만들어줌
    for (int i : v)
        cout << "v " << i << endl;
    int arr[10] = {
        0,
    };
    auto auu = find(arr, arr + 10, 10);
    if (auu == arr + 10)
        cout << "not found" << endl;
    fill(arr, arr + 10, 10);
    auu = find(arr, arr + 10, 10);
    if (auu == arr + 10)
        cout << "not found";
    else
        cout << *auu << endl;

    int arr2[10][10];
    fill(&arr2[0][0], &arr2[0][0] + 10 * 10, 10);
    cout << arr2[1][1] << endl;
    unordered_map<string, int> umap;
    umap["insert"] = 4; //입력
    umap["insert"] = 7; //값 바꾸기
    umap["insert"]++;
    cout << umap["insert"] << endl;
    cout << umap.size() << endl;
    umap.erase("insert");
    cout << umap.size() << endl;

    map<string, int> m;                // 기본 오름차순
    map<int, int, greater<int> > down; //내림차순
    m["map"]++;
    cout << " map :  " << m["map"] << endl;
    m["amap"] = 2;
    for (auto i : m)
        cout << "i.first  " << i.first << "     i.second  " << i.second << endl;
    for (int i = 6; i > 0; i--)
    {
        down[i] = 8;
    }
    for (auto i : down)
        cout << i.first << "   " << i.second << endl;
    bool b = m.erase("amap");
    if (b)
        cout << " amap erased" << endl;
    auto search = m.find("map");
    if (search == m.end())
        cout << "not found" << endl;
    else
        cout << "serach-> first -  " << search->first << "   (*search).second - " << (*search).second << endl;
    m.clear();
    cout << "m[\"amap\"]  " << m["amap"] << endl;
    if (m.end() == m.find("map"))
        cout << "erased all" << endl;
    cout << "m.size()  " << m.size() << endl;

    //중복요소는 없고 오로지 유닉한 값만 저장 + 오름차순 자동정렬
    set<pair<string, int> > se;
    set<int, greater<int> > set_less;
    se.insert({"set1", 1});
    se.insert({"set1", 2});
    se.insert({"set1", 3});
    se.insert({"set1", 4});
    se.insert({"set1", 5});
    cout << "se.size()  " << se.size() << endl;
    for (auto i : se)
        cout << "se  " << i.first << "  " << i.second << endl;
    auto set_a = se.find({"set1", 1});
    if (set_a != se.end())
        cout << "found " << endl;

    multiset<int> ms; // 오름차순 , 중복가능ㅇ
    multiset<char> msc;
    multiset<int, greater<int> > msdown; //내림차순
    for (int i = 7; i > 0; i--)
    {
        ms.insert(i);
        msc.insert((char)i + 65);
        msdown.insert(i);
    }
    for (auto i : ms)
        cout << "ms  " << i << endl;
    for (auto i : msc)
        cout << "msc  " << i << endl;
    for (auto i : msdown)
        cout << "msdown  " << i << endl;

    for (auto i = ms.begin(); i != ms.end(); i++)
        cout << "*i  " << *i << "  ";
    cout << endl;
    auto multis = ms.find(90);
    ms.erase(ms.begin(), multis);
    cout << "size after erease  - " << ms.size() << endl;
    msc.erase(msc.begin());
    cout << "Size after msc.erase(msc.begin());  " << msc.size() << endl;

    stack<string> st; // 괄호만들기, 짝찾기, "교차하지 않고"라는 문장
    st.push("hi");
    st.push("  ");
    cout << "stack 괄호만들기, 짝짖기, '교차하지 않고'라는 문장" << endl;
    while (st.size())
    {
        cout << st.top() << endl;
        st.pop();
    }

    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;

    deque<int> dq;
    dq.push_back(1);
    dq.push_back(3);
    dq.push_front(9);
    dq.push_front(100);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    cout << dq.size() << endl;
    dq.pop_front();
    cout << dq.front() << endl;
    dq.pop_back();
    cout << dq.back() << endl;

    vector<int> vv;
    for (int i = 0; i < 10; i++)
    {
        vv.push_back(i);
    }
    cout << "before roatation  " << vv[0] << endl;
    rotate(vv.begin(), vv.begin() + vv.size() - 1, vv.end()); //뒤로 돌리기
    cout << "after rotation  " << vv[0] << endl;
    rotate(vv.begin(), vv.begin() + 1, vv.end()); //앞으로
    cout << " roatation  " << vv[0] << endl;

    //n진법 ( 10 -> 2 )
    vv.clear();
    cout << vv.size() << endl;
    int nn = 100, bb = 2;
    while (nn > 1)
    {
        vv.push_back(nn % bb);
        nn /= bb;
    }
    if (nn == 1)
        vv.push_back(1);
    reverse(vv.begin(), vv.end());
    cout << "10진법에서 2진법으로  " << endl;
    for (int aa : vv)
    {
        if (aa >= 10)
            cout << char(aa + 55) << endl;
        else
            cout << aa;
    }
    cout << endl;

    //정렬
    int cnt[4] = {7, 8, 9, 1};
    //bool comp(int a, int b){return a<=b;} // 오름차순
    //sort(cnt,cnt+4, comp);
    for (int i : cnt)
        cout << "sort  " << i << endl;
    sort(vv.begin(), vv.end(), greater<int>()); //내림차순
    for (int i : cnt)
        cout << " sort(vv.begin(), vv.end(), greater<int>()); //내림차순  " << i << endl;

    return 0;
}