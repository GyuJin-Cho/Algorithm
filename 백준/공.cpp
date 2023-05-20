#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int a, b;
	int ball = 1;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		if(a==ball)
		{
			ball = b;
		}
		else if(b==ball)
		{
			ball = a;
		}
	}

	cout << ball;
	return 0;
}