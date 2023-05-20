#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int sum = 0;
	int num;
	int cnt = 0;
	for(int i=0;i<N;i++)
	{
		cin >> num;
		cnt += num;
		if(num==0)
		{
			cnt = 0;
		}
		sum += cnt;
	}
	cout << sum;
	return 0;
}