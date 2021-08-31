#include<iostream>

using namespace std;

int main()
{
	long long A, B, V;
	cin >> A >> B >> V;
	long long N;
	if ((V - A) % (A - B) == 0)
	{
		N = (V - A) / (A - B);
	}
	else
	{
		N = (V - A) / (A - B) + 1;
	}

	cout << N + 1;
	return 0;
}