#include<iostream>
#include<algorithm>
#include<cmath>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		vector<int> v;
		if(n==-1)
		{
			break;
		}
		for(int i=1;i<n;i++)
		{
			if(n%i==0)
			{
				v.push_back(i);
			}
		}
		int sum = 0;
		for(int i=0;i<v.size();i++)
		{
			sum += v[i];
		}
		if(sum==n)
		{
			cout << n << " = ";
			for(int i=0;i<v.size()-1;i++)
			{
				cout << v[i] << " + ";
			}
			cout << v[v.size() - 1] << '\n';
		}
		else
		{
			cout << n << " is NOT perfect." << '\n';
		}
	}

	return 0;
}