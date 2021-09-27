#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main()
{
    //1
    string str = "java c c++ python";
    istringstream ss(str);
    string stringBuffer;
    vector<string> x;
    x.clear();
    cout << "어떻게 잘리는지 확인해봅시다 ->";
    //구분자가 , 이라면 getline(ss, stringBuffer, ',')쓰면됨
    while (getline(ss, stringBuffer, ' '))
    {
        x.push_back(stringBuffer);
        cout << stringBuffer << " ";
    }

    cout << endl
         << "vector 값을 출력해보자." << endl;
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << endl;
    }
    cout << endl;

    //2
    string s = "next_is_enter \n make split function by myself";
    string d = " ";
    vector<string> a = split(s, d);
    for (string b : a)
        cout << b << "\n";

    return 0;
}