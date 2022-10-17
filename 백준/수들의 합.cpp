#include<iostream>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	long long sum = 0;
	int num = 1;
	int count = 0;
	while (true)
	{
		sum += num;
		count++;
		if (sum > n)
		{
			count--;
			break;
		}
		num++;
	}
	cout << count;
	return 0;
}