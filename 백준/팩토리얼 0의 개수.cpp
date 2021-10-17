#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	if (N == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	int count = 0;
	for (long long i = 2; i <= N; i++)
	{
		if (i % 5 == 0)
			count++;
		if (i % 25 == 0)
			count++;
		if (i % 125 == 0)
			count++;
	}
	cout << count;

	return 0;
}