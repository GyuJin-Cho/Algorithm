#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int k)
{
    int answer = 0;

    int mul = n / 10;
    answer = (n * 12000) + (k*2000) - (mul*2000);

    return answer;
}

int main()
{
    cout << solution(64, 6);

	return 0;
}