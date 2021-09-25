#include <iostream>
#include <string>
#include <vector>

using namespace std;
int arr[100000];
int solution(int n)
{
	int answer = 0;
	int sum = 0;
	arr[0] = 0; arr[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		arr[i] = (arr[i - 1] % 1234567 + arr[i - 2] % 1234567 ) % 1234567;
	}

	answer = arr[n] % 1234567;
    return answer;
}

int main()
{
    cout << solution(44);
    return 0;
}