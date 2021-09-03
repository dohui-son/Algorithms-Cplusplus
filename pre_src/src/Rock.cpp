//#include <bits/stdc++.h>
//
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//
//
//using namespace std;
//#define endl "\n";
//#define y1 xoxoxo
//vector<int> v;
//void b(int a);
//void b2(int& a);
//void b3(int* a);
//
//int nn = 5;
//int kk = 3;
//int aaaa[5] = { 1,2,3,4,5 };
//vector<int> bbbb;
//
//vector<int> vect;
//void printV(vector<int>& v);
//void makePermutation(int n, int r, int depth);
//
//void combi(int start, vector<int> b);
//
//
//int _map[104][104], mmm, nnn, kkk, x1, x2, y1, y2;
//const int dy[4] = { -1,0,-1,0 };
//const int dx[4] = { 0,1,0,-1 };
//vector<int> ret;
//int dfs(int y, int x );
//
//
//
//
//int main() {
//
//	//	// 1.
//	//	for (int i = 1; i < 10; i++)
//	//	{
//	//		v.push_back(i);
//	//	}
//	//	rotate(v.begin(), v.begin() + 1, v.end()); //2 3 4 5 6 7 8 9 1  앞으로가기
//	//	rotate(v.begin(), v.begin() + v.size() - 1, v.end());  //9 1 2 3 4 5 6 7 8  뒤로가기
//	//	for (std::vector <int>::iterator it = v.begin(); it != v.end(); ++it)
//	//		std::cout << ' ' << *it;
//	//	std::cout << '\n';
//	//
//	//
//	//	// 2. 
//	//	int a = 1;
//	//	b2(a);
//	//	// void b2(int& a) { a = 3;  }
//	//	cout << a << endl;
//	//	b3(&a);
//	//	// void b3(int* a) { *a = 4; }
//	//	cout << a << endl;
//	//
//	//
//	//	// 3.
//	//	string str = "abcde";
//	//	if (str.find("FBI") != string::npos) { //문자열에서 "FBI"찾아내기
//	//		cout << "found" << endl;
//	//	}
//	//	else {
//	//		cout << "unfound";
//	//	}
//	//
//	//
//	//	// 4.
//	//	//10진법을 2진법으로
//	//	int n = 100;
//	//	int bb = 2;
//	//	while (n > 1)
//	//	{
//	//		v.push_back(n % bb);
//	//		n /= bb;
//	//	}
//	//	if (n == 1)v.push_back(1);
//	//	reverse(v.begin(), v.end());
//	//	for (int a : v)
//	//	{
//	//		if (a >= 10)cout << char(a + 55);
//	//		else cout << a;
//	//	}
//	//
//	//
//	//	// 5.
//	//	//sort(a.begin(), a.end(), greater<int>()); 내림차순
//	//	int _count[3] = { 3,2,1 };
//	//	sort(_count, _count + 3, comp);
//	//
//	//	// 6. 실수형
//		//<1>
//	//	n = 0;
//	//	int m1, m2;
//	//	scanf("%d %d.%d", &n, &m1, &m2);  // 33.2를 정수형으로 받으려면?
//	//
//	//  //<2>
//	//	//cout을 사용해 정수부분+소수부분해서 6자리까지 출력한다면? (소수부분은 반올림)
//	////#include<bits/stdc++.h>
//	////usin namespace std;
//	//	typedef long long ll;
//	double a = 1.23456789;
//
//	cout << a << "\n"; //1.23457 ***************(소수부분은 반올림)
//
//	cout.precision(7); // 소수 여섯째자리까지 출력
//	cout << a << "\n"; //1.234568 **************(소수부분은 반올림)
//	//precision건 후 출력
//
//	typedef long long ll;
//	double db = 1.23456789;
//	int b = 2;
//	printf("%.6lf\n", db);	//1.234568
//	printf("%02d\n", b);	//02
//
//
//	cout << endl;
//	cout << "{ 7 }. lower_bound   upper_bound";
//	//7. lower_bound upper_bound
//	//vector가 오름차순 정렬되어있어야함
//
//
//
//	//lower_bound idx제일작은 key값, 찾으려 하는 key값이 "없으면" key값보다 큰 가장 작은 원소 주소값
//	//0번째 배열의 원소부터 찾아서 어떠한 값의 "이상이 되는 위치"를 반환
//	//upper_bound  key 값을 초과하는 가장 첫번째 원소의 주소값
////#include <cstdio>
////#include <vector>
////#include <algorithm>
//	vector<int> v;
//	int aa[5] = { 1,2,2,2,7 };
//	for (int i = 0; i < 5; i++)
//	{
//		v.push_back(aa[i]);
//
//	}
//	cout << endl;
//	int x = 2; //*****여기서 다루는 값은 "2"
//	//vector안의 "2"들의 개수
//	int count = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x));
//	cout << "vector안의 2들의 개수  :  " << count << endl;
//	//vector의 lower_bound의 key가 시작되는 index
//	int start_idx = (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
//	cout << "vector의 lower_bound의 key가 시작되는 index   " << start_idx << endl;
//	//upper_bound의 index 
//	int upper_idx = (int)(upper_bound(v.begin(), v.end(), x) - v.begin());
//	cout << "upper_bound의 index    " << upper_idx << endl;
//	cout << v[upper_idx] << endl;
//
//	//lower_bound가 시작되는 점의 값
//	int lower_s = *lower_bound(v.begin(), v.end(), x);
//	cout << "lower bound가 시작되는 점의 값	" << lower_s << endl;
//
//	//upper_bound가 시작되는 점의 값
//	int upper_s = *upper_bound(v.begin(), v.end(), x);
//	cout << "upper_bound가 시작되는 점의 값	" << upper_s << endl;
//
//
//
//	///////////////////////////////////////////////////////////배열 array
//	cout << endl;
//	count = (int)(upper_bound(aa, aa + 5, x) - lower_bound(aa, aa + 5, x));
//	cout << "array안의 2들의 개수  :  " << count << endl;
//	//vector의 lower_bound의 key가 시작되는 index
//	start_idx = (int)(lower_bound(aa, aa + 5, x) - aa);
//	cout << "array의 lower_bound의 key가 시작되는 index   " << start_idx << endl;
//	//upper_bound의 index 
//	upper_idx = (int)(upper_bound(aa, aa + 5, x) - aa);
//	cout << "array의 upper_bound의 index    " << upper_idx << endl;
//	cout << v[upper_idx] << endl;
//
//	//lower_bound가 시작되는 점의 값
//	lower_s = *lower_bound(aa, aa + 5, x);
//	cout << "lower bound가 시작되는 점의 값	" << lower_s << endl;
//
//	//upper_bound가 시작되는 점의 값
//	upper_s = *upper_bound(aa, aa + 5, x);
//	cout << "upper_bound가 시작되는 점의 값	" << upper_s << endl;
//
//	//lower_bound 란 ?
//	//	-이진탐색(Binary Search)기반의 탐색 방법입니다. (배열 또는 리스트가 정렬 되어있어야 한다.)
//	//	- lower_bound는 찾으려 하는 key값이 "없으면" key값보다 큰, 가장 작은 정수 값을 찾습니다.
//	//	- 같은 원소가 여러개 있어도 상관 없으며, 항상 유일한 해를 구할 수 있습니다.
//	//	- 구간이[start, end]인 배열이 있을때, 중간위치의 index를 mid 라고 하면,
//	//	arr[mid - 1] < key 이면서 arr[mid] >= key 인 최소의 m 값을 찾으면 됩니다. (m >= 2)
//
//	//반환형이 Iterator 이므로 
//	//vector container인 경우에는 iterator에서 v.begin()을 뺀 값으로 몇 번째 인자인지 계산을 하고,
//	//배열인 경우에는 배열의 첫번째 주소를 가리키는 배열의 이름을 빼면 몇 번째 인자인지 알 수 있습니다.
//
//
//	/*upper_bound 란 ?
//		-lower_bound와 마찬가지로 이진탐색(Binary Search)기반의 탐색법 입니다.
//		- 이진탐색(Binary Search)기반이므로 배열이나 리스트가 오름차순으로 정렬 되어있어야 합니다.
//		- upper_bound는 key값을 초과****하는 가장 첫 번째 원소의 위치를 구하는 것 입니다.
//		- 같은 원소가 여러개 존재 해도 항상 유일한 해를 구할 수 있습니다.
//		- 구간이[start, end]인 배열이 있을때, 중간위치의 index를 mid 라고 하면,
//		arr[mid - 1] <= key 이면서 arr[mid] > key 인 최소의 m 값을 찾으면 됩니다. (m >= 2)
//		- upper_bound에서 기억해야 할 것은
//		************(같은 값이 아닌) key 값을 초과하는 가장 첫번째 원소의 위치 라는 것 입니다.*/
//
//
//		/*upper_bound 는
//		마지막 원소부터 원하는 값을 찾고
//		그 값이 시작되기 전의 위치를 반환합니다.
//		예를 들어 1, 2, 2, 3, 4, 5 이라는 배열에서
//		2 를 찾는 다면 4, 3 순으로 찾고 어라 ? 2 를 발견했다 ?
//		그렇다면 그 전의 값인 3 의 위치를 반환하는것입니다.
//		근데 만약에 4 를 찾는다면..그 전의 값인 5 번째 요소라는 값을 반환합니다.
//		이 때 반환되는 값은
//		이터레이터이기 때문에
//		배열의 처음 주소값인 v.begin() 또는 a[0], 을 빼주어서
//		int 형으로 몇번째인지를 파악할 수있습니다.
//			반환되는 값이 포인터 즉 주소값이 반환되기 때문에
//			그 주소값이 몇번째임을 알려면 주소값의 첫번째 값을 빼주면된다는 것입니다.
//			* 이터레이터는 STL 안의 데이타들을 가리키는 포인터입니다.
//			begin()은 해당 리스트의 처음 요소의 주소값을 가리키고
//			end()는 해당 리스트의 마 마지막 요소보다 한칸 뒤의 주소값을 가리킵니다.
//			네 v[i] != v.end()라는 코드를 많이 보셨을텐데요.
//			리스트를 다 순회하고 리스트의 끝에 도착했다는 것을 말함.
//	*/
//
//	vector<int> vvv;
//	for (int i = 1; i < 4; i++) vvv.push_back(i);
//	for (int i = 5; i < 11; i++)vvv.push_back(i);
//	{
//		cout << lower_bound(vvv.begin(), vvv.end(), 4) - vvv.begin() << endl;  //3을 출력 
//	}
//	//idx 3이니 vvv[3] = 5  (4가 없어서) 
//
//	cout << endl;
//	vector<int> v2;
//	for (int i = 2; i <= 5; i++) {
//		v2.push_back(i);
//		cout << i << " ";
//	}
//	v2.push_back(7);
//	cout << 7 << endl;
//	//v2 = { 2,3,4,5,7 }
//	cout << "upper_bound(v2.begin(), v2.end(), 6) - v2.begin()" << endl;
//	cout << upper_bound(v2.begin(), v2.end(), 6) - v2.begin() << endl;	//4
//	cout << "lower_bound(v2.begin(), v2.end(), 6) - v2.begin()" << endl;
//	cout << lower_bound(v2.begin(), v2.end(), 6) - v2.begin() << endl;	//4
//	cout << "upper_bound(v2.begin(), v2.end(), 9) - v2.begin()" << endl;
//	cout << upper_bound(v2.begin(), v2.end(), 9) - v2.begin() << endl;	//5
//	cout << "lower_bound(v2.begin(), v2.end(), 9) - v2.begin()" << endl;
//	cout << lower_bound(v2.begin(), v2.end(), 9) - v2.begin() << endl;	//5
//	cout << "upper_bound(v2.begin(), v2.end(), 0) - v2.begin()" << endl;
//	cout << upper_bound(v2.begin(), v2.end(), 0) - v2.begin() << endl;	//0
//	cout << "lower_bound(v2.begin(), v2.end(), 0) - v2.begin()" << endl;
//	cout << lower_bound(v2.begin(), v2.end(), 0) - v2.begin() << endl;	//0
//
//	/*6 을 찾으려고 하니 4 를 반환합니다.
//	6 을 찾지 못해 7 까지 가서 그 인덱스를 반환하는 것이죠.
//	9 의 경우는 upper_bound 는 오른쪽에서부터 찾으려고 했지만 실패해
//	바로 그 index 의 윗부분을 반환하고
//	lower_bound 는 왼쪽에서 찾으려고 했지만 실패해
//	끝까지 해본 도달지점인 7 윗부분의 인덱스를 반환하는 것을 볼 수있습니다.*/
//
//	cout << endl;
//	cout << "{ 8 }. 순열";
//	cout << endl;
//	/*첫번째 방법은
//	next_permutation 과 prev_permutation 을 이용하는 방법입니다.
//	next_permutation 은 배열을 오름차순으로 순열을 만들 수 있을 때 true 를 반환하고
//	그렇지 않다면 false 를 반환하고
//	배열을 원래의 배열로복원시킵니다.
//	prev_permutation 은 그와 반대인 내림차순입니다.
//	여기서 중요한 점이 있습니다.
//	next_permutation 이나 prev 를 써서 하기전…
//	무조건 sort 를 해야 합니다.
//	아래의 코드는 1, 2, 3 오름차순이 되어있는 코드지만 그렇지 않을 경우
//		예를 들어 3, 2, 1 이렇게 입력을 받는 경우
//		sort(v.begin(), v.end()) 등을 통해 오름차순 정렬을 한 다음
//		do {}…이렇게 permutation 을들어가야 합니다.*/
//
//		//#include <cstdio>
//		//#include <vector>
//		//#include <algorithm>
//		//#include <iostream>
//		//	using namespace std;
//	int arr2[3] = { 1,2,3 };
//	//  vector<int> vect; static으로 정의되어있음
//	for (int i = 0; i < 3; i++)
//	{
//		vect.push_back(arr2[i]);
//	}
//	do {
//		for (int i = 0; i < vect.size(); i++)
//		{
//			cout << vect[i] << " ";
//		}
//		cout << endl;
//	} while (next_permutation(vect.begin(), vect.end()));
//	cout << "-----------------------------------" << endl;
//	vect.clear();
//	for (int i = 2; i >= 0; i--)
//	{
//		vect.push_back(arr2[i]);
//	}
//
//	do {
//		for (int i = 0; i < vect.size(); i++)
//		{
//			cout << vect[i] << " ";
//		}
//		cout << endl;
//	} while (prev_permutation(vect.begin(), vect.end()));
//
//	cout << endl;
//	cout << "두번째 방법은" << endl;
//	cout << "재귀를 이용한 방법입니다.depth 를 이용해서 구현하는 방법또한 있습니다." << endl;
//	vect.clear();
//	for (int i = 0; i < 3; i++)vect.push_back(arr2[i]);
//	makePermutation(3, 3, 0);
//
//
//
//
//	return 0;
//
//}
//bool comp(int a, int b) { return a < b; }
//
//
//void b2(int& a) { a = 3; }
//void b3(int* a) { *a = 4; }
//
//void printV(vector<int>& v) {
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//}
//
//void makePermutation(int n, int r, int depth) {
//	if (r == depth) {
//		printV(vect);
//		return;
//	}
//	for (int i = depth; i < n; i++)
//	{
//		swap(vect[i], vect[depth]);
//		makePermutation(n, r, depth + 1);
//		swap(vect[i], vect[depth]);
//	}
//
//	/*int nn = 5;       static
//	int kk = 3;
//	int aaaa[5] = { 1,2,3,4,5 };
//	vector<int> bbbb;*/
//	combi(-1, bbbb);
//	int arr3[] = { 1,2,3,4,5,6 };
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = i; j < 6; j++)
//		{
//			for (int k1 = j; k1 < 6; k1++)cout << arr3[i] << " " << arr3[j] << " " << arr3[k1] << endl;
//
//		}
//
//	}
//
//
//
//	/*전역변수는 지역변수보다 더 많은 크기의 요소를 담을 수 있고 
//		초기화하지 않은 전역변수는 지역변수가 쓰레기값으로초기화되는 것과는 달리 
//		예상할 수 있는 0 으로 초기화되기 때문에 전역변수를 많이 써야 합니다.
//		그리고 변수명은 항상간결하게 씁시다.count 는 cnt 로 result 는 ret 으로!*/
//
//
//	/*int _map[104][104], mmm, nnn, kkk, x1, x2, y1, y2;
//	const int dy[4] = { -1,0,-1,0 };
//	const int dx[4] = { 0,1,0,-1 };
//	vector<int> ret;
//	int dfs{ int y, int x };*/
//
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cin >> mmm >> nnn >> kkk;
//	for (int i = 0; i < kkk; i++) {
//		cin >> x1 >> y1 >> x2 >> y2; 
//		for (int x = x1; x < x2; x++) {
//			for (int y = y1; y < y2; y++) {
//				_map[y][x] = 1;
//			}
//		}
//	}
//	for (int i = 0; i < mmm; i++) {
//		for (int j = 0; j < nnn; j++) {
//			if (_map[i][j] != 1) {
//				ret.push_back(dfs(i, j));
//			}
//		}
//	}
//	sort(ret.begin(), ret.end());
//	cout << ret.size() << "\n";
//	for (int _ret : ret) cout << _ret << "\n"; 
//
//
//
//	//#define time xoxoxo2
//	//int _map[104][104], m, n, k, x1, x2, y1, y2, time;
//
//
//
//	return;
//}
////1, 3, 9 의 처음 축은 0 번째 요소인 1 이 됩니다.
////자 그럼 swap 이 몇번 발생되죠 ? (0, 0), (1, 0), (2, 0) 이렇게 발생됩니다. 
////1, 3, 9
////3, 1, 9
////9, 3, 1
//
//
//void combi(int start, vector<int> b) {
//	if (b.size() == kk) {
//		printV(b);
//		return ;
//	}
//	for (int i = start+1; i < nn; i++)
//	{
//		b.push_back(i);
//		combi(i, b);
//		b.pop_back();
//	}
//	return;
//}
//
//int dfs(int y, int x) {
//	_map[y][x] = 1;
//	int _ret = 1;
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		if (ny < 0 || ny >= mmm || nx < 0 || nx >= nnn || _map[ny][nx] == 1) continue; 
//		_ret += dfs(ny, nx);
//	}
//	return _ret;
//}