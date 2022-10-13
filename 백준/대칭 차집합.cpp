#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int A, B;
	cin >> A >> B;
	unordered_map<int,int> a;
	unordered_map<int,int> b;
	int num;
	for (int i = 0; i < A; i++)
	{
		cin >> num;
		a[num]++;
	}
	for (int j = 0; j < B; j++)
	{
		cin >> num;
		b[num]++;
	}
	
	for (auto i : b)
	{
		if (a.find(i.first)!=a.end())
			a[i.first]--;
	}
	for (auto i : a)
	{
		if(b.find(i.first)!=b.end())
			b[i.first]--;
	}
	int aCount = 0;
	for (auto i : a)
	{
		if (a[i.first] == 1)
		{
			aCount++;
		}
	}
	int bCount = 0;
	for (auto i : b)
	{
		if (b[i.first])
		{
			bCount++;
		}
	}
	cout << aCount + bCount;
	return 0;
}