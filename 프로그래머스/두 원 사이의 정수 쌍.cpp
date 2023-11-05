#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2)
{
    long long answer = 0;

    for(int i=1;i<=r2;i++)
    {
        int minY = ceil(sqrt((long long)pow(r1, 2) - (long long)pow(i, 2)));
        int maxY = floor(sqrt((long long)pow(r2, 2) - (long long)pow(i, 2)));

        if (r1 < i)
            minY = 0;

        answer += (maxY - minY + 1);
    }

    return answer*4;
}

int main()
{
    cout << solution(2, 3);

    return 0;
}