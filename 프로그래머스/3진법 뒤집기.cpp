#include <string>
#include <vector>
#include<iostream>
#include<cmath>
using namespace std;

int solution(int n)
{
    int answer = 0;
    string num3;
    while (n > 0)
    {
        num3 += to_string(n % 3);
        n /= 3;
    }
    int count = 0;
    for (int i = num3.length() - 1; i >= 0; i--)
    {
        int powcheck = pow(3, count);
        answer =answer+(powcheck*(num3[i]-'0'));
        count++;
    }
    return answer;
}

int main()
{
    cout << solution(125);
    return 0;

}