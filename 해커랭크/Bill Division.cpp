#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	int cost;
	cin >> cost;
	int sum = 0;
	for(int i=0;i<v.size();i++)
	{
		if (i == k)
			continue;
		sum += v[i];
	}
	int returncost = sum / 2;
	if (cost - returncost <= 0)
		cout << "Bon Appetit";
	else if (cost - returncost > 0)
		cout << cost - returncost;
	return 0;
}