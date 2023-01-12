#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int num1, int num2)
{
    int answer = num1/num2;
    return answer;
}

int main()
{
    cout << solution(10, 5);
    return 0;
}