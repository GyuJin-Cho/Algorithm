#include<iostream>

using namespace std;

int solution(int n, int a, int b)
{
	for (int i = 1; i < n; i++)
	{
		if (a % 2 == 1)
			a++;
		if (b % 2 == 1)
			b++;

		a = a / 2;
		b = b / 2;

		if (a == b)
		{
			return i;
		}
	}
}

int main()
{
	cout << solution(8, 4, 7);

	return 0;
}