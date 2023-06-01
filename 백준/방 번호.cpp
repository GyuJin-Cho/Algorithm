#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int solution(int n)
{
	int number[10] = {};
	while(n>0)
	{
		number[n % 10]++;
		n /= 10;
	}

	int ans = 1;
	for(int i=0;i<10;i++)
	{
		if(i==6||i==9)
		{
			continue;
		}
		ans = max(ans, number[i]);
	}

	ans = max(ans, (number[6] + number[9] + 1) / 2);
	return ans;
}

int main()
{
	int number;
	cin >> number;
	cout << solution(number);

	return 0;
}