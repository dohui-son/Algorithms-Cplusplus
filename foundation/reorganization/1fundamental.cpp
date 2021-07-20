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
void b2(int &a) { a = 2; }
void b3(int *a) { *a = 3; }
void arrs(int a[][10])
{
    a[0][4] = 44;
}
void make_permutation(int n, int r, int depth);
void combi(int start, vector<int> &b);

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
        return x < a.x; //내림차순 ( x 기준 )
    }
};

struct percent
{ //단순한 struct
    int x, y;
    double w, d, l;
} a[6]; //한정
//percent a;
//  cin>> a[0].x; 이런식

struct Point
{ //priority queue에 int 외에 다른 구조체가 들어갈때
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
    cout << "priority queue에 int 외에 다른 구조체가 들어갈때" << endl;
    priority_queue<Point> pq_struct;
    pq_struct.push({1, 10});
    pq_struct.push({2, 3});
    pq_struct.push({4, 5});
    pq_struct.push({6, 7});
    cout << "pq_struct top().x  " << pq_struct.top().x << endl; // 3 //오름차순 ( x 기준 )
    cout << "pq_struct top().y  " << pq_struct.top().y << endl; // 2

    cout << "내림차순 ( x 기준 )" << endl;
    priority_queue<Ppoint, vector<Ppoint>, cmp> pq; //greater
    pq.push({1, 2});
    pq.push({10, 1});
    pq.push({11, 1});
    pq.push({4, 5});
    cout << "custom pq greater  " << pq.top().x << endl; //5
    cout << "custom pq greater  " << pq.top().y << endl; //4

    //priority_queue 다익스트라 그리디
    priority_queue<int, vector<int>, greater<int>> pqdown; //내림차순
    priority_queue<int> pq_up;
    for (int i = 7; i > 0; i--)
    {
        pqdown.push(i);
        cout << "pqdown  <greater<int>>내림차순 - 가장 작은 top " << pqdown.top() << endl;

        pq_up.push(i);
        cout << "pq_up default오름차순 - 가장 큰 top " << pq_up.top() << endl;
    }

    char s[50] = {
        0,
    };
    string str = "good morning";
    str += " ";
    str += "space added";
    cout << str << endl;
    str = ""; //string 초기화
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

    c = '\0'; // char 형 초기화 ---- null 인 \0
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
    cout << "round(-3.2) : " << round(a3) << endl; //round(-3.2)  -3
    cout << "round(-3.7) : " << round(a4) << endl; //round(-3.7)  -4

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
    //a에서 z까지 입력 받는데 이를 정수로 0-26으로 표현 ***
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
    cout << num1 << "  " << num2 << "  " << num3 << endl;

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

    //fill(시작값, 끝값, 초기화할값);
    //memset은 바이트로 초기화하기 때문에 0, -1로만 초기화 가능
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

    map<string, int> m;               // 기본 오름차순
    map<int, int, greater<int>> down; // 내림차순
    m["map"]++;                       // 처음에 입력하고 값 넣기
    cout << " map :  " << m["map"] << endl;
    m["amap"] = 2; // 처음에 입력
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
    cout << m["third"] << endl;
    cout << "size " << m.size() << endl;
    for (auto i : m)
        cout << "inserted without adding value  " << i.first << endl;
    m.clear();
    if (m.end() == m.find("map"))
        cout << "clear is done" << endl;
    cout << "m.size() after clear  " << m.size() << endl;
    for (auto i : m)
        cout << "map is not empty after clear()  " << i.first << endl;

    //중복요소는 없고 오로지 유닉한 값만 저장 + 오름차순 자동정렬
    set<pair<string, int>> se;
    set<int, greater<int>> set_greater; // 내림차순
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
    multiset<int, greater<int>> msdown; //내림차순
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

    //실수입력
    int one = 1, two = 2, three = 3;
    scanf("%d %d.%d", &one, &two, &three); // 3 3.21입력받을때
    double d = 1.23456789;
    cout << "d " << d << endl; //1.234567
    cout.precision(10);        //정수부분+소수부분 해서 10자리 출력 ( 소수부분은 반올림 )
    cout << "after cout.precision(10)  " << d << endl;

    cout.precision(7);                               //정수+소수부분해서 7자리 출력(소수부분 반올림)
    cout << "after cout.precision(7) " << d << endl; //1.234568

    //소수점 6자리까지 (반올림) 그리고 2 를 02로 만들어서 출력
    d = 1.233456789;
    printf("%.6lf\n", d);  //1.23458
    printf("%03d\n", two); //002
    printf("%02d\n", two); //02

    //lower_bound(하한)는 0번째 배열의 원소부터 찾아서 어떠한 값의 "이상이 되는 위치"(이터레이터)를 반환
    //없을때는 value보다 큰 값중 가장 작은 값의 주소값 반환
    //upper_bound는 마지막 원소부터 원하는 값을 찾고 그 값이 시작되기 전의 이터레이터를 반환
    int ar[5] = {1, 2, 2, 3, 4};
    v.clear();
    for (int i = 0; i < 5; i++)
    {
        v.push_back(ar[i]);
    }
    sort(v.begin(), v.end()); //소팅하고 해야함
    int x = 2;
    //x의 개수
    int cc = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x));
    cout << "x의 개수 " << cc << endl;
    //시작되는 점
    int f = (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
    cout << "시작되는 점 " << f << endl;
    //끝나는 점
    int t = (int)(upper_bound(v.begin(), v.end(), x) - v.begin());
    cout << "끝나는 점 " << t << endl;

    int f2 = *lower_bound(v.begin(), v.end(), x);
    cout << "lower_bound (이상이 되는 위치의 값)  " << f2 << endl;
    int t2 = *upper_bound(v.begin(), v.end(), x);
    cout << "upper_bound (초과가 되는 위치의 값) " << t2 << endl;

    //배열
    //x의 개수
    cout << endl;
    cout << "배열 " << endl;
    cc = (int)(upper_bound(ar, ar + 5, x) - lower_bound(ar, ar + 5, x));
    cout << "x의 개수 " << cc << endl;
    //시작되는 점
    f = (int)(lower_bound(ar, ar + 5, x) - ar);
    cout << "시작되는 점 " << f << endl;
    //끝나는 점
    t = (int)(upper_bound(ar, ar + 5, x) - ar);
    cout << "끝나는 점 " << t << endl;

    f2 = *lower_bound(ar, ar + 5, x);
    cout << "lower_bound (이상이 되는 위치의 값)  " << f2 << endl;
    t2 = *upper_bound(ar, ar + 5, x);
    cout << "upper_bound (초과가 되는 위치의 값) " << t2 << endl;

    v.clear();
    for (int i = 2; i < 6; i++)
        v.push_back(i);
    v.push_back(7);
    // 2 3 4 5 7
    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl; //4
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl; //4
    cout << upper_bound(v.begin(), v.end(), 9) - v.begin() << endl; //5
    cout << lower_bound(v.begin(), v.end(), 9) - v.begin() << endl; //5
    if (upper_bound(v.begin(), v.end(), 9) == v.end())
        cout << "nope" << endl;
    cout << upper_bound(v.begin(), v.end(), 0) - v.begin() << endl; //0
    cout << lower_bound(v.begin(), v.end(), 0) - v.begin() << endl; //0
    if (upper_bound(v.begin(), v.end(), 0) == v.begin())
        cout << "nope" << endl;

    str = "abcda";
    string *point = &str;
    string &ref = str; // 별명
    cout << "pointer  " << point << endl;
    cout << "*pointer  " << *point << endl;
    cout << "ref별명  " << ref << endl;

    int numbers = 10;
    //void b2(int &a){a=2;}
    //void b3(int *a){*a = 3;}
    b2(numbers);
    cout << "b2(numbers) " << numbers << endl;
    b3(&numbers);
    cout << "b3(numbers) " << numbers << endl;
    // void arrs(int a[][10]){
    //     a[0][4] =44;
    // }
    fill(&arr2[0][0], &arr2[0][0] + 10 * 10, 10); //2차원 배열 초기화
    arrs(arr2);
    cout << "void arrs(int a[][10])  " << arr2[0][4] << endl;

    cout << "next permutation / prev permutaion 중복X 순서O " << endl;
    //next permutation 은 배열을 오름차순으로 순열을 만들 수 있을 때 true 반환
    // 그렇지 않다면 false를 반환하고 배열을 원래의 배열로 복원
    //prev permuation은 내림차순
    v.clear();
    int arrr[] = {1, 2, 3};
    cout << "next permutaion 오름차순 순열 less 뽑기" << endl;
    for (int i = 0; i < 3; i++)
        v.push_back(i);
    do
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << "  ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    cout << "prev_permuation 내림차순 순열 greater 뽑기" << endl;
    v.clear();

    for (int i = 2; i >= 0; i--)
        v.push_back(arrr[i]);
    do
    {
        for (int i = 0; i < 3; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    } while (prev_permutation(v.begin(), v.end())); //내림차순 순열 뽑기

    //depth 순열 뽑기
    cout << "depth 재귀로 순열 뽑기 - 오름차순 (처음 depth == 0)" << endl;
    v.clear();
    for (int i = 0; i < 3; i++)
    {
        v.push_back(arrr[i]);
    }
    make_permutation(3, 3, 0); // n개중에 r개뽑기 depth0부터 항상 시작

    cout << "조합 : 뽑아야하는 대상이 적은 경우만 !!!for문" << endl;
    v.clear();
    int aa[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < j; k++)
            {
                cout << aa[i] << " " << aa[j] << " " << aa[k] << endl;
            }
        }
    }
    cout << "조합 : recursive combination " << endl;
    n = 3;
    k = 2;
    v.clear();
    combi(-1, v);

    return 0;
}

void make_permutation(int n, int r, int depth)
{
    if (r == depth)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = depth; i < n; i++)
    {
        swap(v[i], v[depth]);
        make_permutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
    return;
}

void combi(int start, vector<int> &b)
{
    if (b.size() == k)
    {
        for (int i = 0; i < b.size(); i++)
            cout << b[i] << " ";
        cout << endl;
    }
    for (int i = 1 + start; i < n; i++)
    {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}