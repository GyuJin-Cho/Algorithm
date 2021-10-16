#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	long long N;
	cin >> N;
	stack<long long>s;
	for (long long i = 0; i < N; i++)
	{
		long long a;
		cin >> a;
		if (a == 0&&s.size()>=1)
		{
			s.pop();
		}
		else
		{
			s.push(a);
		}
	}

	long long sum = 0;

	if (s.size() == 0)
		cout << sum;
	else
	{
		while (!s.empty())
		{
			sum += s.top();
			s.pop();
		}
		cout << sum;
	}

	return 0;
}