//#include <bits/stdc++.h>
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
#include <sstream>

//부동소수점(실수)이기 때문에 == 연산자체가 안먹혀서,>이거로 해야함
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
    bool operator<(const Point &p) const { return x > p.x; } //가장 작은수가 top ( x 기준 )--greater
};
struct Ppoint //오름차순---가장 큰 수가 top (default와 같다)
{
    int y, x;
};
struct
{
    bool operator()(Ppoint a, Ppoint b) { return a.x < b.x; }
}; //오름차순---가장 큰 수가 top (default와 같다)

bool compare(const int &a, const int &b)
{
    return b <= a; //custom sort 내림차순
}
bool compare2(const pair<int, int> &a, const pair<int, int> &b)
{
    if (b.first == a.first)
        return b.second <= a.second;
    return b.first < a.first;
} // vector<pair<int,int>> 기준 sort 내림차순

int main()
{
    cout << " queue 에 int 외에 다른 구조체가 들어갈때" << endl;
    priority_queue<Point> pq_struct;
    pq_struct.push({1, 10});
    pq_struct.push({2, 3});
    pq_struct.push({4, 5});
    pq_struct.push({6, 7});
    cout << " pq_struct top().x  " << pq_struct.top().x << endl; //3 가장작은 수 (greater랑 같음)
    cout << "pq_struct top().y  " << pq_struct.top().y << endl;  //2
    pq_struct.pop();
    cout << " pq_struct top().x  " << pq_struct.top().x << endl; //5
    cout << "pq_struct top().y  " << pq_struct.top().y << endl;  //4

    //custom pq  :  x기준 가장 큰 수biggest - default와 같음
    priority_queue<Ppoint, vector<Ppoint>, > pq;
    pq.push({1, 2});
    pq.push({10, 2});
    pq.push({11, 1});
    pq.push({4, 5});
    cout << "custom pq (default와 같음) x  " << pq.top().x << endl; //5
    cout << "custom pq (default와 같음) y  " << pq.top().y << endl; //4

    //priority_queue 다익스트라, 그리디
    priority_queue<int, vector<int>, greater<int> > pq_greater; //greater내림차순 - 가장 작은 top
    pq_greater.push(2);
    pq_greater.push(0);
    cout << "greater 내림차순 -- pq.top은 가장 작은수  " << pq_greater.top() << endl;
    priority_queue<int> default_pq;
    default_pq.push(2);
    default_pq.push(0);
    cout << "default pq -- pq.top은 가장 큰 수  " << default_pq.top() << endl;

    //sort 내림차순
    //     bool compare(const int &a,const int & b){
    //     return b <= a; //custom sort 내림차순
    // }
    vector<int> for_sort = {90, 4, 39, 7, 5, 9, 3, 4, 7, 58, 9, 34};
    sort(for_sort.begin(), for_sort.end(), compare);
    //디폴트 vector<pair<int,int>> v 벡터의 sort ==> 첫번째 인자 기준 정렬 + 동일할시 두번째 것 기준 정렬
    //     bool compare2(pair<int, int> &a,pair<int, int> &b)// vector<pair<int,int>> 기준 sort 내림차순
    // {
    //     if (b.first == a.first)
    //         return b.second <= a.second;
    //     return b.first < a.first;
    // }
    vector<pair<int, int> > vect_p;
    sort(vect_p.begin(), vect_p.end(), compare2);

    string splitt = "java c c++ python";
    istringstream ss(splitt); //#include<sstream>
    string stringBuffer;
    vector<string> strvect;
    strvect.clear();
    cout << "어떻게 잘리는지 확인해봅시다 ->";
    //구분자가 , 이라면 getline(ss, stringBuffer, ',')쓰면됨
    while (getline(ss, stringBuffer, ' '))
    {
        strvect.push_back(stringBuffer);
        cout << stringBuffer << " ";
    }

    cout << endl
         << "vector 값을 출력해보자." << endl;
    for (int i = 0; i < strvect.size(); i++)
    {
        cout << strvect[i] << endl;
    }

    char s[50] = {
        0,
    };
    string str = "good morning";
    str += "  ";
    str += "space added";
    cout << str << endl;
    str = ""; //string 초기화
    str = '\0';
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

    // char vector 초기화 1
    char charact[10][10] = {{
        '\0',
    }};
    //char charact[10][10] = {{
    //     0,
    // }};
    fill(s, s + 50, 0); // char array 초기화 2
    cout << "char charact[10][10] = {{0,}};" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << charact[i][j]; //초기화 완료
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
    int to_int = c - '0';                 //정수형 4
    cout << "'4'-'0' " << to_int << endl; // 4
    c = 'C';
    to_int = c - 'A' + 10;                       //정수형 12
    cout << "c - 'A' + 10;  " << to_int << endl; // 12
    cout << " 'C'-'A'  " << 'C' - 'A' << endl;   // 2
    cout << " 'A'-'A'  " << 'A' - 'A' << endl;   // 0
    c = '\0';                                    //char 형 초기화 ---null인 \0
    str = "123";
    str[0]++;
    cout << str << endl; //223;

    v = vector<int>(5, 0);
    for (int i = 0; i < 5; i++)
    {
        scanf("%1d", &v[i]);
        cout << "붙어있는 입력값 받기 " << v[i] << "   ";
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
    cout << "round(숫자) 반올림" << endl;
    cout << round(a1) << endl;
    cout << round(a2) << endl;
    cout << round(-3.2) << endl; // -3 ***
    cout << round(-3.7) << endl; // -4 ***

    cout << "ceil  올림" << endl;
    cout << ceil(4.3) << endl;
    cout << ceil(-4.3) << endl; // -4

    cout << "floor(숫자)  내림" << endl;
    cout << floor(4.7) << endl;
    cout << floor(-4.7) << endl; // -5

    cout << "trunc(숫자) 소수점 아래는 다 버림 c++11" << endl;
    cout << trunc(-4.7) << endl; //-4
    cout << trunc(4.7) << endl;  //4

    c = 'A';
    cout << c << endl;
    cout << (int)c * 100 << " 형변환 됨" << endl; //6500
    cout << (int)100 * c << " x" << endl;         //6500

    //A-Z 65-90
    //a-z 97-122
    //a 에서 z 까지 입력 받는데 이를 정수로 0-26 으로 표현 ***
    c = 'c';
    cout << (int)c - 97 << endl;  //2
    cout << (int)c - 'a' << endl; //2
    c = 'a';
    cout << (int)c - 'a' << endl; //0

    str = "this is string";
    cout << str.substr(0, 3) << endl; //시작 지점으로부터 몇개 문자열 뽑아내기
    cout << str.substr(1, 3) << endl; //idx 1로부터 3개 문자열 뽑아내기

    reverse(str.begin() + 1, str.end());
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
        cout << i << " "; //2 7 2 3 2
    cout << endl;
    v.erase(v.begin(), v.begin() + 2); //부터 -"전"까지
    for (int i : v)
        cout << i << " "; //2 3 2
    cout << endl;
    auto aut = find(v.begin(), v.end(), 10);
    if (aut == v.end())
        cout << "10 not found" << endl;
    cout << "unfound *aut  " << *aut << "   v.size()  " << v.size() << endl;
    (v.begin(), v.end(), 10);
    v.push_back(100);
    for (int i : v)
        cout << i << "  ";
    cout << endl;
    cout << v.size() << endl;
    cout << v[v.size() - 1] << endl;
    swap(v[0], v[v.size() - 1]);
    cout << "swap(v[0], v[v.size()-1]);  " << v[0] << "   " << v[v.size() - 1] << endl;
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

    fill(&arr2[0][0], &arr2[0][0] + 10 * 10, 11); //초기화 *****
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    //***************복사
    //gg를 gear[gdx][0]에서 gear[gdx][7]까지 복사해주기 --#include <algorithm>
    //copy(&gg[0], &gg[0] + 8, &gear[gdx][0]); // 복사할 대상 시작주소,복사할대상 시작주소+데이터수, 복사되어야할 공간의 첫 주소
    //gg에서 gear로
    //memcpy(b, a, sizeof(b)); //배열 b에다가 a를 b크기만큼 복사해주기 #include <cstring>
    unordered_map<string, int> umap;
    umap["insert"] = 4; //입력
    umap["insert"] = 7; //값 바꾸기
    cout << umap["insert"] << endl;
    umap["insert"]++;
    cout << umap["insert"] << endl;
    cout << umap["2"] << endl;
    cout << umap.size() << endl;

    //map을 key가 아닌 value기준으로 정렬해보기
    // bool (const pp& a, const pp& b) {
    // 	if (a.second == b.second) return a.first < b.first;
    // 	return a.second < b.second;
    // }
    map<int, int> map_;
    vector<pair<int, int> > vec(map_.begin(), map_.end());
    sort(vec.begin(), vec.end(), );

    map<string, int> m;                    //자동정렬 , 기본 오름차순
    map<int, int, greater<int> > greaterm; //내림차순
    m["map"]++;                            //처음에 입력하고 바로 값 넣기
    cout << m["map"] << endl;
    m["amap"] = 2; //처음 입력
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
    multiset<int, greater<int> > msgreater; //내림차순
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
    rotate(v.begin(), v.begin() + v.size() - 1, v.end()); //뒤로 한칸씩 돌리기
    cout << "after 뒤로 돌리기 : v[0]  " << v[0] << endl;
    rotate(v.begin(), v.begin() + 1, v.end()); //앞으로 한칸씩 돌리기
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
    scanf("%d %d.%d", &one, &two, &three); //3  3.21입력받을 때
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
    cout << "x의 개수 : " << cc << endl; //2
    //시작되는 지점idx
    int start = (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
    cout << "시작되는 지점idx : " << start << endl; // 1
    //끝난 지점idx
    int fin = (int)(upper_bound(v.begin(), v.end(), x) - v.begin());
    cout << "끝난 지점idx :  " << fin << endl; //3
    //lower_bound ( 이상이되는 시작 위치의 값 )
    int s2 = *lower_bound(v.begin(), v.end(), x);
    cout << "lower_bound ( 이상이되는 시작 위치의 값 ) : " << s2 << endl; //2
    //upper_bound ( 초과가 되는 위치의 값 )
    int f2 = *upper_bound(v.begin(), v.end(), x);
    cout << "upper_bound ( 초과가 되는 위치의 값 ) : " << f2 << endl; //3

    //배열로...
    //x의 개수
    cc = (int)(upper_bound(ar, ar + 5, x) - lower_bound(ar, ar + 5, x));
    cout << "x의 개수 : " << cc << endl; //2
    //시작되는 지점idx
    start = (int)(lower_bound(ar, ar + 5, x) - ar);
    cout << "시작되는 지점idx : " << start << endl; // 1
                                                    //끝난 지점idx
    fin = (int)(upper_bound(ar, ar + 5, x) - ar);
    cout << "끝난 지점idx :  " << fin << endl; //3
    //lower_bound ( 이상이되는 시작 위치의 값 )
    s2 = *lower_bound(ar, ar + 5, x);
    cout << "lower_bound ( 이상이되는 시작 위치의 값 ) : " << s2 << endl; //3
    //upper_bound ( 초과가 되는 위치의 값 )
    f2 = *upper_bound(ar, ar + 5, x);
    cout << "upper_bound ( 초과가 되는 위치의 값 ) : " << f2 << endl; //3

    v.clear();
    for (int i = 2; i < 6; i++)
    {
        v.push_back(i);
    }
    v.push_back(7);
    // 2 3 4 5 7
    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl; //4
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl; //4
    cout << upper_bound(v.begin(), v.end(), 9) - v.begin() << endl; //5
    cout << lower_bound(v.begin(), v.end(), 9) - v.begin() << endl; //5
    if (upper_bound(v.begin(), v.end(), 9) == v.end())
        cout << "bigger than the biggest" << endl;
    if (lower_bound(v.begin(), v.end(), 9) == v.end())
        cout << "bigger than the biggest" << endl;
    cout << upper_bound(v.begin(), v.end(), 0) - v.begin() << endl; //0
    cout << lower_bound(v.begin(), v.end(), 0) - v.begin() << endl; //0
    if (upper_bound(v.begin(), v.end(), 0) == v.begin())
        cout << "smaller than smallest" << endl;
    if (lower_bound(v.begin(), v.end(), 0) == v.begin())
        cout << "smaller than smallest" << endl;

    str.clear();
    cout << str.size() << endl; // 0
    str = "abcda";
    string *point = &str;
    string &ref = str; //별명
    ref = "ref";
    cout << str << endl; //ref
    str = "abcda";
    cout << ref << "  " << str << endl;
    cout << "pointer " << point << endl;
    cout << "*pointer " << *point << endl;
    cout << "ref 별명" << ref << endl;

    int no = 10;
    //void b2(int &a){a= 2;}
    //void b3(int *a){*a = 3;}
    b2(no);
    cout << "void b2(int &a)  " << no << endl;
    b3(&no);
    cout << "void b3(int *a)  " << no << endl;
    // void arrs(int a[][10]){
    //     a[0][4] = 44;
    // }
    fill(&arr2[0][0], &arr2[0][0] + 10 * 10, 20); //2차원 배열 초기화****
    cout << arr2[0][4] << endl;
    arrs(arr2); //2중배열을 함수 인자로 받기
    cout << "void arrs(int a[][10])   " << arr2[0][4] << endl;

    cout << "next_permuation 오름차순 순열  /  prev_permutation 내림차순 순열 " << endl;
    // next permutation은 배열을 오름차순으로 순열을 만들 수 있을 때 true 반환
    // 그렇지 않다면 false 반환
    // prev permutation은 배열을 내림차순
    v.clear();
    int a[] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
        v.push_back(i);
    cout << "next permutation 오름차순 순열 less 뽑기 " << endl;
    do
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
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

    v.clear();
    cout << "depth 재귀로 순열 뽑기  -  오름차순 ( 처음 depth == 0 ) " << endl;
    for (int i = 0; i < 3; i++)
        v.push_back(a[i]);
    make_permutation(3, 3, 0); //n개 중에 r개 뽑기 depth 0 부터 항상 시작

    v.clear();
    cout << "조합 : 뽑아야하는 대상이 적은 경우만 for문 이용" << endl;
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

    v.clear();
    cout << "조합 : recursive combination" << endl;
    n = 3;
    k = 2;
    combi(-1, v);

    return 0;
}

void make_permutation(int n, int r, int depth)
{
    if (r == depth)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
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