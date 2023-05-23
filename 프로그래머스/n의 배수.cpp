#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num, int n)
{
    return num % n == 0 ? 1 : 0;
}

int main()
{
    cout << solution(98,1);

    return 0;
}