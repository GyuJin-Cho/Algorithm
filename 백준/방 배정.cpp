#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	unordered_map<int, int> f;
	unordered_map<int, int> m;
	int sex, grade;
	while(n--)
	{
		cin >> sex >> grade;
		if (sex == 0)
			f[grade]++;
		else
			m[grade]++;
	}
	int sum = 0;
	for(auto i : f)
	{
		
		float div = float(i.second) / float(k);
		sum += ceil(div);
	}
	for (auto i : m)
	{
		float div = float(i.second) / float(k);
		sum += ceil(div);
	}
	cout << sum;
	return 0;
}