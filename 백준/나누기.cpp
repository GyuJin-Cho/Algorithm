#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
	long long N,F;
	cin >> N >> F;
	long long MinLength = N / 100;
	long long MaxLength = MinLength + 1;
	int Min = 1323123123123;

	for (long long i = MinLength * 100; i < MaxLength * 100; i++)
	{
		if (i % F == 0)
		{
			string temp = to_string(i);
			char a = temp.back();
			temp.pop_back();
			char b = temp.back();
			temp.pop_back();
			string c;
			c += b;
			c += a;
			Min = min(Min, stoi(c));
		}
	}
	if (Min < 10)
		cout << "0" << Min;
	else
		cout << Min;
	return 0;
}