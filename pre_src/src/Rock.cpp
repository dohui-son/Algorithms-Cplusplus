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
//	//	rotate(v.begin(), v.begin() + 1, v.end()); //2 3 4 5 6 7 8 9 1  �����ΰ���
//	//	rotate(v.begin(), v.begin() + v.size() - 1, v.end());  //9 1 2 3 4 5 6 7 8  �ڷΰ���
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
//	//	if (str.find("FBI") != string::npos) { //���ڿ����� "FBI"ã�Ƴ���
//	//		cout << "found" << endl;
//	//	}
//	//	else {
//	//		cout << "unfound";
//	//	}
//	//
//	//
//	//	// 4.
//	//	//10������ 2��������
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
//	//	//sort(a.begin(), a.end(), greater<int>()); ��������
//	//	int _count[3] = { 3,2,1 };
//	//	sort(_count, _count + 3, comp);
//	//
//	//	// 6. �Ǽ���
//		//<1>
//	//	n = 0;
//	//	int m1, m2;
//	//	scanf("%d %d.%d", &n, &m1, &m2);  // 33.2�� ���������� ��������?
//	//
//	//  //<2>
//	//	//cout�� ����� �����κ�+�Ҽ��κ��ؼ� 6�ڸ����� ����Ѵٸ�? (�Ҽ��κ��� �ݿø�)
//	////#include<bits/stdc++.h>
//	////usin namespace std;
//	//	typedef long long ll;
//	double a = 1.23456789;
//
//	cout << a << "\n"; //1.23457 ***************(�Ҽ��κ��� �ݿø�)
//
//	cout.precision(7); // �Ҽ� ����°�ڸ����� ���
//	cout << a << "\n"; //1.234568 **************(�Ҽ��κ��� �ݿø�)
//	//precision�� �� ���
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
//	//vector�� �������� ���ĵǾ��־����
//
//
//
//	//lower_bound idx�������� key��, ã���� �ϴ� key���� "������" key������ ū ���� ���� ���� �ּҰ�
//	//0��° �迭�� ���Һ��� ã�Ƽ� ��� ���� "�̻��� �Ǵ� ��ġ"�� ��ȯ
//	//upper_bound  key ���� �ʰ��ϴ� ���� ù��° ������ �ּҰ�
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
//	int x = 2; //*****���⼭ �ٷ�� ���� "2"
//	//vector���� "2"���� ����
//	int count = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x));
//	cout << "vector���� 2���� ����  :  " << count << endl;
//	//vector�� lower_bound�� key�� ���۵Ǵ� index
//	int start_idx = (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
//	cout << "vector�� lower_bound�� key�� ���۵Ǵ� index   " << start_idx << endl;
//	//upper_bound�� index 
//	int upper_idx = (int)(upper_bound(v.begin(), v.end(), x) - v.begin());
//	cout << "upper_bound�� index    " << upper_idx << endl;
//	cout << v[upper_idx] << endl;
//
//	//lower_bound�� ���۵Ǵ� ���� ��
//	int lower_s = *lower_bound(v.begin(), v.end(), x);
//	cout << "lower bound�� ���۵Ǵ� ���� ��	" << lower_s << endl;
//
//	//upper_bound�� ���۵Ǵ� ���� ��
//	int upper_s = *upper_bound(v.begin(), v.end(), x);
//	cout << "upper_bound�� ���۵Ǵ� ���� ��	" << upper_s << endl;
//
//
//
//	///////////////////////////////////////////////////////////�迭 array
//	cout << endl;
//	count = (int)(upper_bound(aa, aa + 5, x) - lower_bound(aa, aa + 5, x));
//	cout << "array���� 2���� ����  :  " << count << endl;
//	//vector�� lower_bound�� key�� ���۵Ǵ� index
//	start_idx = (int)(lower_bound(aa, aa + 5, x) - aa);
//	cout << "array�� lower_bound�� key�� ���۵Ǵ� index   " << start_idx << endl;
//	//upper_bound�� index 
//	upper_idx = (int)(upper_bound(aa, aa + 5, x) - aa);
//	cout << "array�� upper_bound�� index    " << upper_idx << endl;
//	cout << v[upper_idx] << endl;
//
//	//lower_bound�� ���۵Ǵ� ���� ��
//	lower_s = *lower_bound(aa, aa + 5, x);
//	cout << "lower bound�� ���۵Ǵ� ���� ��	" << lower_s << endl;
//
//	//upper_bound�� ���۵Ǵ� ���� ��
//	upper_s = *upper_bound(aa, aa + 5, x);
//	cout << "upper_bound�� ���۵Ǵ� ���� ��	" << upper_s << endl;
//
//	//lower_bound �� ?
//	//	-����Ž��(Binary Search)����� Ž�� ����Դϴ�. (�迭 �Ǵ� ����Ʈ�� ���� �Ǿ��־�� �Ѵ�.)
//	//	- lower_bound�� ã���� �ϴ� key���� "������" key������ ū, ���� ���� ���� ���� ã���ϴ�.
//	//	- ���� ���Ұ� ������ �־ ��� ������, �׻� ������ �ظ� ���� �� �ֽ��ϴ�.
//	//	- ������[start, end]�� �迭�� ������, �߰���ġ�� index�� mid ��� �ϸ�,
//	//	arr[mid - 1] < key �̸鼭 arr[mid] >= key �� �ּ��� m ���� ã���� �˴ϴ�. (m >= 2)
//
//	//��ȯ���� Iterator �̹Ƿ� 
//	//vector container�� ��쿡�� iterator���� v.begin()�� �� ������ �� ��° �������� ����� �ϰ�,
//	//�迭�� ��쿡�� �迭�� ù��° �ּҸ� ����Ű�� �迭�� �̸��� ���� �� ��° �������� �� �� �ֽ��ϴ�.
//
//
//	/*upper_bound �� ?
//		-lower_bound�� ���������� ����Ž��(Binary Search)����� Ž���� �Դϴ�.
//		- ����Ž��(Binary Search)����̹Ƿ� �迭�̳� ����Ʈ�� ������������ ���� �Ǿ��־�� �մϴ�.
//		- upper_bound�� key���� �ʰ�****�ϴ� ���� ù ��° ������ ��ġ�� ���ϴ� �� �Դϴ�.
//		- ���� ���Ұ� ������ ���� �ص� �׻� ������ �ظ� ���� �� �ֽ��ϴ�.
//		- ������[start, end]�� �迭�� ������, �߰���ġ�� index�� mid ��� �ϸ�,
//		arr[mid - 1] <= key �̸鼭 arr[mid] > key �� �ּ��� m ���� ã���� �˴ϴ�. (m >= 2)
//		- upper_bound���� ����ؾ� �� ����
//		************(���� ���� �ƴ�) key ���� �ʰ��ϴ� ���� ù��° ������ ��ġ ��� �� �Դϴ�.*/
//
//
//		/*upper_bound ��
//		������ ���Һ��� ���ϴ� ���� ã��
//		�� ���� ���۵Ǳ� ���� ��ġ�� ��ȯ�մϴ�.
//		���� ��� 1, 2, 2, 3, 4, 5 �̶�� �迭����
//		2 �� ã�� �ٸ� 4, 3 ������ ã�� ��� ? 2 �� �߰��ߴ� ?
//		�׷��ٸ� �� ���� ���� 3 �� ��ġ�� ��ȯ�ϴ°��Դϴ�.
//		�ٵ� ���࿡ 4 �� ã�´ٸ�..�� ���� ���� 5 ��° ��Ҷ�� ���� ��ȯ�մϴ�.
//		�� �� ��ȯ�Ǵ� ����
//		���ͷ������̱� ������
//		�迭�� ó�� �ּҰ��� v.begin() �Ǵ� a[0], �� ���־
//		int ������ ���°������ �ľ��� ���ֽ��ϴ�.
//			��ȯ�Ǵ� ���� ������ �� �ּҰ��� ��ȯ�Ǳ� ������
//			�� �ּҰ��� ���°���� �˷��� �ּҰ��� ù��° ���� ���ָ�ȴٴ� ���Դϴ�.
//			* ���ͷ����ʹ� STL ���� ����Ÿ���� ����Ű�� �������Դϴ�.
//			begin()�� �ش� ����Ʈ�� ó�� ����� �ּҰ��� ����Ű��
//			end()�� �ش� ����Ʈ�� �� ������ ��Һ��� ��ĭ ���� �ּҰ��� ����ŵ�ϴ�.
//			�� v[i] != v.end()��� �ڵ带 ���� �������ٵ���.
//			����Ʈ�� �� ��ȸ�ϰ� ����Ʈ�� ���� �����ߴٴ� ���� ����.
//	*/
//
//	vector<int> vvv;
//	for (int i = 1; i < 4; i++) vvv.push_back(i);
//	for (int i = 5; i < 11; i++)vvv.push_back(i);
//	{
//		cout << lower_bound(vvv.begin(), vvv.end(), 4) - vvv.begin() << endl;  //3�� ��� 
//	}
//	//idx 3�̴� vvv[3] = 5  (4�� ���) 
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
//	/*6 �� ã������ �ϴ� 4 �� ��ȯ�մϴ�.
//	6 �� ã�� ���� 7 ���� ���� �� �ε����� ��ȯ�ϴ� ������.
//	9 �� ���� upper_bound �� �����ʿ������� ã������ ������ ������
//	�ٷ� �� index �� ���κ��� ��ȯ�ϰ�
//	lower_bound �� ���ʿ��� ã������ ������ ������
//	������ �غ� ���������� 7 ���κ��� �ε����� ��ȯ�ϴ� ���� �� ���ֽ��ϴ�.*/
//
//	cout << endl;
//	cout << "{ 8 }. ����";
//	cout << endl;
//	/*ù��° �����
//	next_permutation �� prev_permutation �� �̿��ϴ� ����Դϴ�.
//	next_permutation �� �迭�� ������������ ������ ���� �� ���� �� true �� ��ȯ�ϰ�
//	�׷��� �ʴٸ� false �� ��ȯ�ϰ�
//	�迭�� ������ �迭�κ�����ŵ�ϴ�.
//	prev_permutation �� �׿� �ݴ��� ���������Դϴ�.
//	���⼭ �߿��� ���� �ֽ��ϴ�.
//	next_permutation �̳� prev �� �Ἥ �ϱ�����
//	������ sort �� �ؾ� �մϴ�.
//	�Ʒ��� �ڵ�� 1, 2, 3 ���������� �Ǿ��ִ� �ڵ����� �׷��� ���� ���
//		���� ��� 3, 2, 1 �̷��� �Է��� �޴� ���
//		sort(v.begin(), v.end()) ���� ���� �������� ������ �� ����
//		do {}���̷��� permutation ������ �մϴ�.*/
//
//		//#include <cstdio>
//		//#include <vector>
//		//#include <algorithm>
//		//#include <iostream>
//		//	using namespace std;
//	int arr2[3] = { 1,2,3 };
//	//  vector<int> vect; static���� ���ǵǾ�����
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
//	cout << "�ι�° �����" << endl;
//	cout << "��͸� �̿��� ����Դϴ�.depth �� �̿��ؼ� �����ϴ� ������� �ֽ��ϴ�." << endl;
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
//	/*���������� ������������ �� ���� ũ���� ��Ҹ� ���� �� �ְ� 
//		�ʱ�ȭ���� ���� ���������� ���������� �����Ⱚ�����ʱ�ȭ�Ǵ� �Ͱ��� �޸� 
//		������ �� �ִ� 0 ���� �ʱ�ȭ�Ǳ� ������ ���������� ���� ��� �մϴ�.
//		�׸��� �������� �׻󰣰��ϰ� ���ô�.count �� cnt �� result �� ret ����!*/
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
////1, 3, 9 �� ó�� ���� 0 ��° ����� 1 �� �˴ϴ�.
////�� �׷� swap �� ��� �߻����� ? (0, 0), (1, 0), (2, 0) �̷��� �߻��˴ϴ�. 
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