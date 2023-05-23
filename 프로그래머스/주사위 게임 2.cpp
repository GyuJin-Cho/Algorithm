#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c)
{
    int answer = 0;

    if(a!=b&&a!=c&&b!=c)
    {
        return a + b + c;
    }
    else if(a==b||b==c||a==c)
    {
        if(a==b&&b==c&&a==c)
        {
            return (a + b + c) * ((a * a) + (b * b) + (c * c)) * ((a * a * a) + (b * b * b) + (c * c * c));
        }
        return (a + b + c) * ((a * a) + (b * b) + (c * c));
    }

    return answer;
}

int main()
{
    cout << solution(3, 5, 3);

    return 0;
}