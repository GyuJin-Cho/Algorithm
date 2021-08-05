#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string a;
    long b = 0;
    map<string, long> answer;
    int T = 0;
    cin >> T;
    for (long i = 0; i < T; i++)
    {
        cin >> a >> b;
        answer.insert(make_pair(a, b));
    }
    while (cin >> a)
    {
        if (answer.find(a) != answer.end())
        {
            cout << a << "=" << answer.find(a)->second << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
        
        
    }
    return 0;
}