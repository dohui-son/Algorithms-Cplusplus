#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <tuple>
#include <string>
#include <set>
#include <stack>
#include <queue>

using namespace std;
#define endl "\n";
struct P //struct with custom sorting
{
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
struct percent //단순한 struct
{
    int x, y;
    double w, d, l;
} a[6]; //한정
// cin >> a[0].x ; 이런식

struct Point
{ // priority queue에 int 외에 다른 구조체가 들어갈때
    int y, x;
    Point(int y, int x) : y(y), x(x) {}
    Point()
    {
        y = -1;
        x = -1;
    }
    bool operator<(const Point &p) const { return x > p.x; } //오름차순(x기준)
};

struct Ppoint //내림차순 (x기준)
{
    int y, x;
};
struct cmp
{
    bool operator()(Ppoint a, Ppoint b)
    {
        return a.x < b.x;
    }
};

void b2(int &a);
void b3(int *a);
void make_permutation(int n, int r, int depth);
void combi(int start, vector<int> &b);
void arrs(int a[][10]);

vector<int> v;
int n = 3;
int k = 2;

int main()
{
    priority_queue<Point> pq_struct;
    pq_struct.push({1, 10});
    pq_struct.push({2, 3});
    pq_struct.push({4, 5});
    pq_struct.push({6, 7});
    cout << "pq_struct  " << pq_struct.top().x << endl; // 3 x기준 오름차순
    cout << "pq_struct  " << pq_struct.top().y << endl; //2

    priority_queue<Ppoint, vector<Ppoint>, cmp> pq; //내림차순
    pq.push({1, 2});
    pq.push({10, 1});
    pq.push({11, 1});
    pq.push({4, 5});
    cout << "custom pq less " << pq.top().x << endl; //x기준
    cout << "custom pq less " << pq.top().y << endl;

    //prioirty queue ( 다익스트라, 그리디 )
    priority_queue<int, vector<int>, greater<int> > pq_up;
    //오름차순
    priority_queue<int> pq_down; //내림차순
    for (int i = 7; i > 0; i--)
    {
        pq_down.push(i);
        cout << "pq_down  <greater<int>> " << pq_down.top() << endl;
        pq_up.push(i);
        cout << "pq_up default  " << pq_up.top() << endl;
    }

    char s[10];
    string str = "wow fantastic";
    str += " ";
    str += "space added";
    cout << str << endl;
    str = ""; // string 초기화
    cout << "str : " << str << endl;

    // s[0] = {
    //     0,
    // }; --> 이거 안됨
    fill(s, s + 10, 0);              //char vector 초기화
    memset(s, 0, sizeof(char) * 10); //char vector 초기화
    for (char a : s)
    {
        cout << a << endl;
        cout << "char vector 초기화 완료";
    }
    cout << endl;

    char c = '4';
    int to_int = c - '0'; // 정수형 4
    c = 'C';
    to_int = c - 'A' + 10; // 정수형 12

    c = '\0'; // char 형 초기화 --- null 인 \0 넣기
    cout << "c : " << c << endl;
    cout << "초기화" << endl;

    str = "123";
    str[0]++;
    cout << str << endl; //223

    // 입력 : 1293746 일때 입력받는 방법
    v = vector<int>(5, 0);
    for (int i = 0; i < 5; i++)
    {
        scanf("%1d", &v[i]);
        cout << "after scanf(\" % 1d \", &v[i]) : " << v[i] << endl;
    }
    getline(cin, str); // "안녕하세요 날씨가 좋네요" 입력받기

    //***입력을 주다가 안줄 때 끝난다고 명시되어있을때***
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
    cout << "round(-3.2) : " << round(a3) << endl; //round(-3.2) : -3
    cout << "round(-3.7) : " << round(a4) << endl; //round(-3.7) : -4

    //올림 함수
    cout << "ceil(4.3) " << ceil(4.3) << endl;
    cout << "ceil(-4.3) " << ceil(-4.3) << endl;
    //내림 함수
    cout << "floor(4.7) " << floor(4.7) << endl;
    cout << "floor(-4.7) " << floor(-4.7) << endl;
    //소수점 아래는 다 없애는 함수 c++11
    cout << "trunc(-4.7) " << trunc(-4.7) << endl;
    cout << "trunc(4.7) " << trunc(4.7) << endl;
    //양수일때 ceil 값과 trunc 값이 다릅니다.
    //음수일때 floor 값과 trunc 값이 다릅니다.

    to_int = (int)c * 100;
    to_int = (int)100 * c; //이렇게 하면 형변환 안됨

    //asci code A-Z 65-90
    //asci code a-z 97-122
    //****a에서 z까지 입력받는데 이를 정수로 0-26으로 표현 *****
    c = 'a';
    cout << (int)c - 97 << endl;  //0
    cout << (int)c - 'a' << endl; //0

    str = "this is string";
    cout << str.substr(0, 3) << endl; // 시작지점으로부터 몇개 문자열 뽑아내기
    cout << str.substr(1, 3) << endl;
    reverse(str.begin(), str.end());
    cout << str << endl;
    reverse(str.begin(), str.begin() + 6);
    cout << str << endl;
    auto au = find(str.begin(), str.end(), 'i');
    cout << "*au to print     " << *au << endl;
    if (au == str.end())
        cout << "not found" << endl;
    str.erase(str.begin(), str.begin() + 2);
    cout << str << endl;

    string strr = "hello for the fine";
    if (strr.find("hi") == string::npos)
        cout << "string::npos" << endl;

    pair<int, int> pi;
    pi = {1, 2};
    int num1 = 0, num2 = 0, num3 = 0;
    tie(num1, num2) = pi;
    cout << num1 << "  " << num2 << endl;
    tuple<int, int, int> tl;
    tl = {1, 2, 3};
    tie(num1, num2, num3) = tl;
    cout << num1 << "  " << num2 << " " << num3 << endl;

    v.push_back(100);
    v.pop_back();
    for (int i : v)
        cout << "v " << i << " ";
    cout << endl;
    v.erase(v.begin() + 2, v.begin() + 3);
    for (int i : v)
        cout << "v " << i << " ";

    cout << endl;
    auto aut = find(v.begin() + 2, v.end(), 7);
    if (aut == v.end())
    {
        cout << "no 7" << endl;
    }
    else
    {
        cout << *aut << endl;
    }
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
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << *auu << endl;
    }

    //fill(시작값, 끝값, 초기화할값);
    //meset은 바이트로 초기화하기 때문에 0,-1로만 초기화가능함.....
    int arr2[10][10];
    fill(&arr2[0][0], &arr2[0][0] + 10 * 10, 10);
    cout << arr2[1][1] << endl;
    unordered_map<string, int> umap;
    umap["insert"] = 4; //입력하기
    umap["insert"] = 7; //값 바꾸기
    umap["insert"]++;
    cout << umap["insert"] << endl;
    cout << umap.size() << endl;
    umap.erase("insert");
    cout << umap.size() << endl;

    map<string, int> m;                // 기본 오름차순
    map<int, int, greater<int> > down; // 내림차순
    m["map"]++;                        //처음에 입력하고 값 넣기
    cout << "map : " << m["map"] << endl;
    m["amap"] = 2;
    for (auto i : m)
        cout << "i.first   " << i.first << " i.second  " << i.second << endl;
    bool b = m.erase("amap");
    if (b)
        cout << "erased" << endl;
    auto search = m.find("map");
    if (search == m.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "search -> find " << search->first << "  " << (*search).second << endl;
    }
    m.clear();
    cout << m["amap"] << endl;
    if (m.end() == m.find("map"))
        cout << "erased all" << endl;
    cout << "m.size()  " << m.size() << endl;

    set<pair<string, int> > se;
    //중복요소는 없고 오로지 유닉한 값만 저장 + 오름차순 자동정렬
    set<int, greater<int> > set_less; //내림차순
    se.insert({"set1", 1});
    se.insert({"set2", 2});
    se.insert({"set3", 3});
    se.insert({"set3", 3});
    se.insert({"set3", 4});
    cout << "se.size()  " << se.size() << endl;
    for (auto i : se)
        cout << "se " << i.first << " " << i.second << endl;
    auto set_a = se.find({"set1", 1});
    if (set_a != se.end())
        cout << "found" << endl;

    multiset<int> ms; //오름차순 중복 가능
    multiset<char> msc;
    multiset<int, greater<int> > msdown; //내림차순
    for (int i = 7; i > 0; i--)
    {
        ms.insert(i);
        msc.insert((char)i + 65);
        msdown.insert(i);
    }
    for (auto i : ms)
        cout << "ms " << i << endl;
    for (auto i : msc)
        cout << "msc " << i << endl;
    for (auto i : msdown)
        cout << "msdown " << i << endl;

    for (auto i = ms.begin(); i != ms.end(); i++)
    {
        cout << "*i  " << *i << "  ";
    }
    cout << endl;
    auto multis = ms.find(90);
    ms.erase(ms.begin(), multis);
    cout << "size after erase : " << ms.size() << endl;
    msc.erase(msc.begin());
    cout << "size after - msc.erase(msc.begin());  " << msc.size() << endl;

    stack<string> st; //괄호만들기, 짝찾기, "교차하지 않고"라는 문장
    st.push("hi");
    st.push("  ");
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
    dq.push_front(3);
    dq.push_front(4);
    dq.push_back(0);
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

    cout << "before rotation  " << vv[0] << endl;
    rotate(vv.begin(), vv.begin() + vv.size() - 1, vv.end()); //뒤로
    cout << "rotation  " << vv[0] << endl;
    rotate(vv.begin(), vv.begin() + 1, vv.end()); //앞으로
    cout << "rotation  " << vv[0] << endl;

    //n진법 (10 -> 2)
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
    cout << "10진법 에서 2진법 " << endl;
    for (int aa : vv)
    {
        if (aa >= 10)
        {
            cout << char(aa + 55) << endl;
        }
        else
        {
            cout << aa;
        }
    }
    cout << endl;

    //정렬
    int cnt[4] = {7, 8, 9, 1};
    //bool comp(int a,int b){return a <= b;} 오름차순
    //sort(cnt, cnt + 4, comp);
    for (int i : cnt)
        cout << "sort  " << i << endl;
    sort(vv.begin(), vv.end(), greater<int>()); //내림차순

    //실수 입력
    int one = 1, two = 2, three = 3;
    scanf("%d %d.%d", &one, &two, &three); //3 3.21받을때
    double d = 1.23456789;
    cout << d << endl;                          //1.23457
    cout.precision(7);                          //정수부분+소수부분 해서 6자리까지 출력 ( 소수부분은 반올림 )
    cout << "cout.precision(7)  " << d << endl; //1.234568

    //소수점 6자리까지(반올림), 그리고 2를 02로 만들어서 출력
    d = 1.23456789;
    printf("%.6lf\n", d);  // 1.23458
    printf("%02d\n", two); // 02

    int ar[5] = {1, 2, 2, 3, 4};
    v.clear();
    for (int i = 0; i < 5; i++)
        v.push_back(ar[i]);
    int x = 2;
    int cc = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x));
    int f = (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
    int t = (int)(upper_bound(v.begin(), v.end(), x) - v.begin());
    int f2 = *lower_bound(v.begin(), v.end(), x);
    int t2 = *upper_bound(v.begin(), v.end(), x);

    printf("%d 의 갯수 : %d, 시작되는 점: %d  끝나는 점: %d \n", x, cc, f, t);
    printf("lower bound가 시작되는 점의 값 : %d, upper bound가 시작되는 점의 값 : %d\n", f2, t2);
    cc = (int)(upper_bound(ar, ar + 5, x) - lower_bound(ar, ar + 5, x));
    f = (int)(lower_bound(ar, ar + 5, x) - ar);
    t = (int)(upper_bound(ar, ar + 5, x) - ar);
    f2 = *lower_bound(ar, ar + 5, x);
    t2 = *upper_bound(ar, ar + 5, x);
    printf("%d의 갯수 : %d, 시작되는 점 : %d, 끝나는 점 : %d \n", x, c, f, t);
    printf("lower bound가 시작되는 점의 값 : %d, upper bound가 시작되는 점의 값 : %d\n", f2, t2);

    v.clear();
    for (int i = 0; i < 4; i++)
    {
        v.push_back(i);
    }
    for (int i = 5; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << lower_bound(v.begin(), v.end(), 4) - v.begin() << endl; //3;
    //4를 찾으려하니 3을 반환 1,2,3,5의 5를 가리키는 인덱스를 반환
    //즉 4의 이산인 첫번째 지점을 반환한것

    v.clear();
    for (int i = 2; i < 6; i++)
    {
        v.push_back(i);
    }
    v.push_back(7);
    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl; //4
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl; //4
    cout << upper_bound(v.begin(), v.end(), 9) - v.begin() << endl; //5
    cout << lower_bound(v.begin(), v.end(), 9) - v.begin() << endl; //5
    cout << upper_bound(v.begin(), v.end(), 0) - v.begin() << endl; //0
    cout << lower_bound(v.begin(), v.end(), 0) - v.begin() << endl; //0

    //next permutation은 배열을 오름차순으로 순열을 만들 수 있을 때 true 반환
    // 그렇지 않다면 false를 반환하고 배열을 원래의 배열로 복원
    //prev permutation 은 내림차순
    cout << "next permutaion 오름차순  / prev permutaion 내림차순 " << endl;
    v.clear();
    int arrr[3] = {1, 2, 3};
    cout << "next_permutation 오름차순 순열" << endl;
    for (int i = 0; i < 3; i++)
    {
        v.push_back(i);
    }

    do
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << "  ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
    cout << endl;
    cout << "prev_permutation 내림차순 순열" << endl;
    v.clear();
    for (int i = 3; i > 0; i--)
        v.push_back(arrr[i]);
    do
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << "  ";
        }
        cout << endl;
    } while (prev_permutation(v.begin(), v.end())); //ㄴㅐ림차순 순열 뽑기

    str = "abcda";
    string *point = &str;
    string &ref = str; //별명
    cout << "pointer " << point << endl;
    cout << "*pointer  " << *point << endl;
    cout << "&ref " << ref << endl; //별명

    int numbers = 10;

    // void b2(int &a) { a = 2; }
    // void b3(int *a) { *a = 3; }
    b2(numbers);
    cout << "b2(numbers)  " << numbers << endl;
    b3(&numbers);
    cout << numbers << endl;

    // void arrs(int a[][10]){
    //     a[0][4] = 44;
    // }
    fill(&arr2[0][0], &arr2[0][0] + 10 * 10, 10);
    arrs(arr2);
    cout << "void arrs(int a[][10])   " << arr2[0][4] << endl;

    //depth이용 순열
    cout << "depth이용 재귀로 순열만들기 - 오름차순  (처음depth는 0)" << endl;
    v.clear();
    for (int i = 0; i < 3; i++)
        v.push_back(arrr[i]);
    make_permutation(3, 3, 0);

    cout << "조합  : 뽑아야하는 대상이 적은 경우만!!!for 문 " << endl;
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
    cout << "조합  : recursive combination " << endl;
    n = 3;
    k = 2;
    vv.clear();
    combi(-1, vv);

    return 0;
}
void combi(int start, vector<int> &b)
{
    if (b.size() == k)
    {
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    for (int i = start + 1; i < n; i++)
    {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

void make_permutation(int n, int r, int depth)
{ //하나의 축을 잡고 그 축을 바꿔나가면서 바꾸면서 만들기
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

void arrs(int a[][10])
{
    a[0][4] = 44;
}

void b2(int &a) { a = 2; }
void b3(int *a) { *a = 3; }