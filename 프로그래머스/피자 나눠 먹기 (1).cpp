#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define PAN 7
int solution(int n)
{
    int answer = 0;

    while (n > 0)
    {
        answer++;
        n -= PAN;
    }
    
    return answer;
}

int main()
{
    cout << solution(7);

	return 0;
}