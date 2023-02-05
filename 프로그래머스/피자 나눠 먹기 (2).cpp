#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define PAN 6
int solution(int n)
{
    int answer = 0;
    int count = PAN;
    while(1)
    {
        answer++;
        if (count%n == 0)
            break;
        count += PAN;
    }

    return answer;
}

int main()
{
    cout << solution(10);

    return 0;
}