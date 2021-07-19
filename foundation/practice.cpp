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
{ //struct with custion sorting
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

struct percent
{ //단순한 struct
    int x, y;
    double w, d, l;
} sarr[6]; //한정
//cin >> sarr[0].x;

struct Point
{
    //priority queue 에 int 외 다른 구조체가 들어갈때
    int y, x;
    Point(int y, int x) : y(y), x(x) {}
    Point()
    {
        y = -1;
        x = -1;
    }
    bool operator<(const Point &p) const { return x > p.x; } //오름차순 ( x 기준 )
};
struct Ppoint //내림차순 ( x 기준 )
{
    int y, x;
};
struct cmp
{
    bool operator()(Ppoint a, Ppoint b) { return a.x < b.x; }
}; //내림차순

int main()
{
    cout << "priority queue 에 int 외에 다른 구조체가 들어갈때" << endl;
    priority_queue<Point> pq_struct;
    pq_struct.push({1, 10});
    pq_struct.push({2, 3});
    pq_struct.push({4, 5});
    pq_struct.push({6, 7});
    cout << " pq_struct top().x  " << pq_struct.top().x << endl; //less 3 가장작은 수
    cout << "pq_struct top().y  " << pq_struct.top().y << endl;  //2
    pq_struct.pop();
    cout << " pq_struct top().x  " << pq_struct.top().x << endl; //less 5
    cout << "pq_struct top().y  " << pq_struct.top().y << endl;  //4

    priority_queue<Ppoint, vector<Ppoint>, cmp> pq; //greater -- biggest
    pq.push({1, 2});
    pq.push({10, 2});
    pq.push({11, 1});
    pq.push({4, 5});
    cout << "custom pq greater x  " << pq.top().x << endl;
    cout << "custom pq greater y  " << pq.top().y << endl;

    char s[50] = {
        0,
    };
    string str = "good morning";
    str += "  ";
    str += "space added";
    cout << str << endl;
    str = "";
    cout << "str: " << str << "init" << endl;
    int initial[10] = {
        0,
    };
    for (int i : initial)
        cout << i << " ";
    cout << endl;

    int init2[10][10] = {{
        0,
    }};
    cout << "2중 배열 초기화 " << endl;
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
    fill(s, s + 50, 0); // char vector 초기화

    char c = '4';
    int to_int = c - '0'; //정수형 4
    cout << "'4'-'0' " << to_int << endl;
    c = 'C';
    to_int = c - 'A' + 10; //정수형 12
    cout << "c - 'A' + 10;  " << to_int << endl;
    cout << " 'C'-'A'  " << 'C' - 'A' << endl;
    cout << " 'A'-'A'  " << 'A' - 'A' << endl;
    c = '\0';
    str = "123";
    str[0]++;
    cout << str << endl; //223;

    v = vector<int>(5, 0);
    for (int i = 0; i < 5; i++)
    {
        scanf("%1d", &v[i]);
        cout << "붙어있는 입력값 받기  " << v[i] << " ";
    }
    cout << endl;

    getline(cin, str); //개행문자 받기

    //입력을 주다가 안 줄때 끝난다고 명시되어있을때***
    while (scanf("%d", &to_int) != EOF)
    {
    }
    while (cin >> to_int)
    {
    }

    double a1 = 3.2, a2 = 3.7, a3 = -3.2, a4 = -3.7;
    cout << round(a1) << endl;
    cout << round(a2) << endl;
    cout << round(-3.2) << endl; // -3
    cout << round(-3.7) << endl; // -4

    cout << ceil(4.3) << endl;
    cout << ceil(-4.3) << endl; // -4

    cout << floor(4.7) << endl;
    cout << floor(-4.7) << endl; // -5

    cout << trunc(-4.7) << endl; //-4
    cout << trunc(4.7) << endl;  //4

    c = 'A';
    cout << c << endl;
    cout << (int)c * 100 << " 형변환 됨" << endl;
    cout << (int)100 * c << " x" << endl;

    //A-Z 65-90
    //a-z 97-122
    //a 에서 z 까지 입력 받는데 이를 정수로 0-26 으로 표현 ***
    c = 'c';
    cout << (int)c - 97 << endl;  //0
    cout << (int)c - 'a' << endl; //0

    str = "this is string";
    cout << str.substr(0, 3) << endl; //시작 지점으로부터 몇개 문자열 뽑아내기
    cout << str.substr(1, 3) << endl;

    reverse(str.begin(), str.end());
    cout << str << endl;
    auto au = find(str.begin(), str.end(), 'i');
    cout << *au << endl;
    cout << au - str.begin() << endl;
    au = find(str.begin(), str.end(), 'z');
    if (au == str.end())
        cout << "not found " << endl;
    str.erase(str.begin(), str.begin() + 2);
    cout << str << endl;

    str = "hello for the fine";
    if (str.find("hi") == string::npos)
        cout << "string::npos " << endl;

    pair<int, int> pi;
    pi = {1, 2};
    int num1 = 0, num2 = 0, num3 = 0;
    tie(num1, num2) = pi;
    cout << num1 << " " << num2 << endl;
    tuple<int, int, int> tl;
    tl = {0, 0, 3};
    tie(num1, num2, num3) = tl;
    cout << num1 << "  " << num2 << "  " << num3 << endl;

    v.push_back(100);
    v.pop_back();
    for (int i : v)
        cout << i << " ";
    cout << endl;
    v.erase(v.begin(), v.begin() + 2);
    for (int i : v)
        cout << i << " ";
    auto aut = find(v.begin(), v.end(), 10);
    if (aut == v.end())
        cout << "10 not found" << endl;
    cout << "unfound *aut  " << *aut << "   v.size()  " << v.size() << endl;
    fill(v.begin(), v.end(), 10);
    v.clear();
    cout << "after clear v.size()  " << v.size() << endl;
    int arr[10] = {
        0,
    };
    auto auu = find(arr, arr + 10, 20);
    if (auu == arr + 10)
        cout << "not found" << endl;

    cout << *auu << endl;
    cout << auu - arr << endl;

    // fill(시작값, 끝값, 초기화할 값);
    //memeset은 바이트로 초기화하기 때문에 0,-1로만 초기화 가능
    int arr2[10][10] = {{
        0,
    }};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    fill(&arr2[0][0], &arr2[0][0] + 10 * 10, 11); //*****
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    unordered_map<string, int> umap;
    umap["insert"] = 4; //입력
    umap["insert"] = 7;
    cout << umap["insert"] << endl;
    umap["insert"]++;
    cout << umap["insert"] << endl;
    cout << umap["2"] << endl;
    cout << umap.size() << endl;

    map<string, int> m;                    //자동정렬
    map<int, int, greater<int> > greaterm; //내림차순
    m["map"]++;
    cout << m["map"] << endl;
    m["amap"] = 2;
    for (auto i : m)
        cout << i.first << " " << i.second << endl;
    for (int i = -6; i <= 0; i++)
    {
        greaterm[i] = 1;
    }
    for (auto i : greaterm)
        cout << i.first << " " << i.second << endl;
    bool b = m.erase("amap");
    if (b)
        cout << "amap is erased" << endl;
    auto search = m.find("map");
    if (search == m.end())
        cout << "map is not found" << endl;
    else
        cout << search->first << " " << (*search).second << endl;
    cout << m["third"] << endl;
    cout << "size " << m.size() << endl;
    for (auto i : m)
        cout << i.first << " ";
    cout << endl;
    m.clear();
    if (m.end() == m.find("third"))
        cout << "m is cleared" << endl;

    // 중복요소는 없고 오로지 유닉한 값만 저장 + 오름차순 자동정렬
    set<pair<string, int> > se;
    set<int, greater<int> > setgreater; // 내림차순
    for (int i = 0; i < 6; i++)
    {
        se.insert({"set1", i});
        se.insert({"set1", i});

        setgreater.insert(i);
        setgreater.insert(i);
    }
    for (auto i : se)
        cout << i.first << "  " << i.second << "    ";
    cout << endl;
    for (auto i : setgreater)
        cout << i << " ";
    cout << endl;

    multiset<int> ms; //오름차순, 중복가능 O
    multiset<char> msc;
    multiset<int, greater<int> > msgreater;
    for (int i = 0; i < 7; i++)
    {
        ms.insert(i);
        msc.insert(90 - (char)i);
        msgreater.insert(i);

        ms.insert(i);
        msc.insert(90 - (char)i);
        msgreater.insert(i);
    }
    for (auto i : ms)
        cout << i << "  ";
    cout << endl;

    for (auto i : msc)
        cout << i << "  ";
    cout << endl;

    for (auto i : msgreater)
        cout << i << "  ";
    cout << endl;

    for (auto i = ms.begin(); i != ms.end(); i++)
    {
        cout << "*i  " << *i << "  ";
    }
    cout << endl;

    auto multis = ms.find(90);
    ms.erase(ms.begin(), multis);
    cout << ms.size() << endl;

    cout << msc.size() << endl;
    msc.erase(msc.begin());
    cout << msc.size() << endl;

    cout << "stack 괄호만들기, 짝짓기, '교차하지 않고'라는 문장" << endl;
    stack<string> st; //괄호만들기, 짝짓기, "교차하지 않고"라는 문장
    st.push("hi");
    st.push("  ");
    cout << st.size() << endl;

    while (st.size())
    {
        cout << "st.top()  : " << st.top() << endl;
        st.pop();
    }

    queue<int> q;
    for (int i = 0; i < 4; i++)
    {
        q.push(i);
        cout << q.front() << " ";
    }
    cout << "size  " << q.size() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << endl;
    cout << "size  " << q.size() << endl;

    deque<int> dq;
    for (int i = 0; i < 3; i++)
    {
        dq.push_back(-i);
        dq.push_front(i);
    }
    while (dq.size())
    {
        cout << "size" << dq.size() << endl;
        cout << "front  " << dq.front() << endl;
        cout << "back  " << dq.back() << endl;
        dq.pop_front();
        dq.pop_back();
    }

    v.clear();
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    cout << "before rotation : v[0]  " << v[0] << endl;
    rotate(v.begin(), v.begin() + v.size() - 1, v.end()); //뒤로
    cout << "after 뒤로 돌리기 : v[0]  " << v[0] << endl;
    rotate(v.begin(), v.begin() + 1, v.end()); //앞으로
    cout << "after 앞으로 돌리기 : v[0]  " << v[0] << endl;

    //n진법 ( 10 -> 2 )
    v.clear();
    cout << "10진법에서 2진법으로 " << endl;
    int nn = 100, bb = 2;
    while (nn > 1)
    {
        v.push_back(nn % bb);
        nn /= bb;
    }
    if (nn == 1)
        v.push_back(1);
    reverse(v.begin(), v.end());
    for (int aa : v)
    {
        if (aa >= 10)
            cout << char(aa + 55) << endl;
        else
            cout << aa;
    }
    cout << endl;

    //정렬
    int cnt[4] = {7, 8, 9, 1};
    //bool comp(int a,int b)return a<=b; //오름차순
    //sort (cnt, cnt+1, comp);
    sort(cnt, cnt + 4);
    for (int i = 0; i < 4; i++)
    {
        cout << cnt[i] << "  ";
    }
    cout << endl;

    sort(cnt, cnt + 4, greater<int>()); //내림차순
    for (int i = 0; i < 4; i++)
    {
        cout << cnt[i] << "  ";
    }
    cout << endl;
    sort(v.begin(), v.end(), greater<int>());
    for (int i : v)
        cout << i << "  ";
    cout << endl;

    //실수입력
    int one = 1, two = 2, three = 3;
    scanf("%d %d.%d", &one, &two, &three);
    double d = 1.23456789;
    cout << "d  " << d << endl;                        //1.23457
    cout.precision(10);                                //정수부분+소수부분 해서 10자리 출력 (소수부분은 반올림)
    cout << "after cout.precision(10)  " << d << endl; //1.23456789
    cout.precision(7);                                 //정수부분+소수부분 해서 7자리 출력 (소수부분은 반올림)
    cout << "after cout.precision(7)  " << d << endl;  //1.234568

    // 소수점 6자리까지 (반올림) 그리고 2를 02로 만들어서 출력
    cout << "use printf :" << endl;
    printf("%.6lf\n", d);  //1.23458
    printf("%03d\n", two); //002
    printf("%02d\n", two); //02

    //lower_bound(하한)은 0번째 배열의 원소부터 찾아서 어떠한 값의 "이상이 되는 위치"(이터레이터)를 반환
    //없을때는 value보다 큰 값 중 가장 작은 값의 주소값 반환
    //upper_bound 는 마지막 원소부터 원하는 값을 찾고 그 값이 시작되기전의 이터레이터를 반환
    int ar[5] = {1, 2, 2, 3, 4};
    v.clear();
    for (int i = 0; i < 5; i++)
    {
        v.push_back(ar[i]);
    }
    sort(v.begin(), v.end()); //소팅하고 lower_bound upper_bound 를 써야함
    int x = 2;
    //x의 개수
    int cc = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x));
    cout << "x의 개수 : " << cc << endl;
    //시작되는 지점idx
    int start = (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
    cout << "시작되는 지점idx : " << start << endl; // 1
    //끝난 지점idx
    int fin = (int)(upper_bound(v.begin(), v.end(), x) - v.begin());
    cout << "끝난 지점idx :  " << fin << endl;
    //lower_bound ( 이상이되는 시작 위치의 값 )
    int s2 = *lower_bound(v.begin(), v.end(), x);
    cout << "lower_bound ( 이상이되는 시작 위치의 값 ) : " << s2 << endl;
    //upper_bound ( 초과가 되는 위치의 값 )
    int f2 = *upper_bound(v.begin(), v.end(), x);
    cout << "upper_bound ( 초과가 되는 위치의 값 ) : " << f2 << endl;

    //배열로...
    //x의 개수
    cc = (int)(upper_bound(ar, ar + 5, x) - lower_bound(ar, ar + 5, x));
    cout << "x의 개수 : " << cc << endl;
    //시작되는 지점idx
    start = (int)(lower_bound(ar, ar + 5, x) - ar);
    cout << "시작되는 지점idx : " << start << endl; // 1
                                                    //끝난 지점idx
    fin = (int)(upper_bound(ar, ar + 5, x) - ar);
    cout << "끝난 지점idx :  " << fin << endl;
    //lower_bound ( 이상이되는 시작 위치의 값 )
    s2 = *lower_bound(ar, ar + 5, x);
    cout << "lower_bound ( 이상이되는 시작 위치의 값 ) : " << s2 << endl;
    //upper_bound ( 초과가 되는 위치의 값 )
    f2 = *upper_bound(ar, ar + 5, x);
    cout << "upper_bound ( 초과가 되는 위치의 값 ) : " << f2 << endl;

    v.clear();
    for (int i = 2; i < 6; i++)
    {
        v.push_back(i);
    }
    v.push_back(7);

    return 0;
}
