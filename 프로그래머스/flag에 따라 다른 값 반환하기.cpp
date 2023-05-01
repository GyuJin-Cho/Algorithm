#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag)
{
    if (flag)
        return a + b;
    return a - b;
}

int main()
{
    cout << solution(-4, 7, true);

    return 0;
}