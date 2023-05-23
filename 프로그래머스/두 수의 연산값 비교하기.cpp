#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b)
{
    int answer = 0;

    string s = to_string(a);
    string z = to_string(b);
    s += z;


    return (stoi(s)>(2*a*b)? stoi(s) : (2*a*b));
}

int main()
{
    cout << solution(91, 2);
    return 0;
}