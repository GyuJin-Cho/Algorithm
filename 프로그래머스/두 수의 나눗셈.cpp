#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2)
{
    int answer = 0;
    float div = 0;
    div = (float)num1 / (float)num2;
    answer = div*1000;
    return answer;
}

int main()
{
    cout << solution(3, 2);

	return 0;
}