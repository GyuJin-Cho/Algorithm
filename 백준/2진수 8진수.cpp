#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<cstring>

using namespace std;

int main()
{
    string str;
    cin >> str;
    if (str.size() % 3 == 1) 
    {
        cout << str[0];
    }
    if (str.size() % 3 == 2) 
    {
        cout << (str[0] - '0') * 2 + (str[1] - '0');
    }
    for (int i = str.size() % 3; i < str.size(); i += 3) 
    {
        cout << (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0');
    }
    return 0;
}
