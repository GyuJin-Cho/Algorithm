#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool isPrime(int num)
{
	if (num < 2)
		return false;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

bool Palindrome(string str)
{
	string front, back;

	front = str;
	reverse(str.begin(), str.end());
	back = str;
	if (front == back)
		return true;
	else
		return false;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int i = n;
	while (true)
	{
		if (isPrime(i) && Palindrome(to_string(i)))
		{
			cout << i;
			break;
		}
		i++;
	}

	return 0;
}