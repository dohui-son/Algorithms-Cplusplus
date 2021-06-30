#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

pair<int, int> p;
tuple<int, int, int> tl;
int a, b, c;
vector<int> v;

int main()
{
    p = make_pair(1, 2);
    tl = make_tuple(1, 2, 3);
    tie(a, b) = p;
    tie(a, b, c) = tl;

    for (int i = 0; i < 10; i++)
        v.push_back(i);
    for (int a : v)
        cout << a << " ";
    v.pop_back();
    v.erase(v.begin(), v.begin() + 1);
    auto a = find(v.begin(), v.end(), 100);
    if (a == v.end())
        cout << "not found" << endl;

    int maxim = *max_element(v.begin(), v.end());
    int mini = *min_element(v.begin(), v.end());

    v.clear();                    //배열 초기화
    fill(v.begin(), v.end(), 10); //시작값, 끝값, 초기화하는 값   ==>vector에도 사용가능
    //memset은 0, -1 으로만 초기화가 가능. 왜냐하면 memset이 byte로 초기화를 해버리기 때문
    int b[10] = {
        0,
    };
    int bb[10][10] = {{
        0,
    }};
    fill(b, b + 10, 0);
    //2차원 배열 초기화 : fill;
    for (size_t i = 0; i < 10; i++)
        fill(bb[i], bb[i] + 10, 0);
    //fill(&bb[0][0], &bb[0][0] + n * m, k);

    int arr[10] = {
        0,
    };
    for (int a : arr)
        cout << a << " ";
    auto a = find(arr, arr + 10, 100);
    if (a == arr + 10)
        cout << "not found";

    fill(arr, arr + 10, 10);

    unordered_map<string, int> umap;
    umap.insert({"test1", 1});
    umap["test1"] = 4;

    return 0;
}
