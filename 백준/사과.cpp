#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int sum = 0;
	int apple,student;
	while(N--)
	{
		cin >> student >> apple;
		sum = sum + (apple % student);
	}
	cout << sum;
	return 0;
}