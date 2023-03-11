#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    int mul = 1;
    int cnt = 1;

    if (n == 1)
        return 1;

    while(1)
    {
        if (mul == n)
        {
            answer = cnt;
            break;
        }
        else if (mul >= n)
        {
            answer = cnt - 1;
            break;
        }
        mul *= cnt;
        cnt++;
    }

    return answer-1;
}

int main()
{
    cout << solution(1);

	return 0;
}