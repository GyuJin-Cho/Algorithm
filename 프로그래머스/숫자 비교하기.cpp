#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num1, int num2)
{
    
    return num1 == num2 ? 1 : -1;
}

int main()
{
    cout << solution(11, 11);

    return 0;
}