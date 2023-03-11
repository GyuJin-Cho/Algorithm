#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v(1001);
	int k = 1;
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if (k > 1000)
				break;
			v[k] = i;
			k++;

		}
	}
	int sum = 0;
	for(int i=N;i<=M;i++)
	{
		sum += v[i];
	}
	cout << sum;
	return 0;
}