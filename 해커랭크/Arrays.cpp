#include<iostream>

using namespace std;
int T[1001];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> T[i];
	}
	for (int i = n-1; i >= 0; i--)
	{
		cout << T[i]<<" ";
	}
	return 0;
}