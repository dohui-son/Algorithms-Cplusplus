#include <iostream>
#include <vector>

#define endl "\n";

using namespace std;
int N;
int64_t sum;
vector<int64_t> road;
vector<int64_t> price;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    
    cin >> N; //도시개수
    road = vector<int64_t>(N); //마이너스도 들어감 유인트는 마이너스 안됨
    price = vector<int64_t>(N);
 //대입전 int64_t k = int형+int형 ; 
 //(int형+int형)결과가 int형에 담겼다가 그것이 int64_t로 캐스팅되어서 "="연산이 이루어진다
    
    for(int j = 0; j<N-1; j++)cin >> road[j];
    for(int j = 0; j<N; j++)cin >> price[j];

    int oil = price[0];
    sum = oil*road[0];
    for(int j = 1; j<N-1; j++){
        if(oil>price[j])oil=price[j];
        sum += oil*road[j];
    }
    cout << sum;
    

    

    return 0;
}