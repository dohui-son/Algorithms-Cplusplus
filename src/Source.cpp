#include <iostream>
#include <vector>

using namespace std;
#define endl "\n"
int v[5][5] = { -1 };

int main(){
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << v[i][j] << " ";
		}

	}
	return 0;
}