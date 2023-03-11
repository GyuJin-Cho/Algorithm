#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n)
{
    int answer = 1;
    int sum = slice;
    while(1)
    {
	    if(sum >=n)
	    {
            break;
	    }
        answer++;
        sum += slice;
    }

    return answer;
}

int main()
{
    cout << solution(7,10);

    return 0;
}