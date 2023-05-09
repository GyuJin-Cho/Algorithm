#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v(3);
	for(int i=0;i<3;i++)
	{
		cin >> v[i];
	}

	for(int i=0;i<3;i++)
	{
		int tmp = 0;
		for(int j=i+1;j<3;j++)
		{
			if(v[i]>v[j])
			{
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}

	for (int i : v)
	{
		cout << i << ' ';
	}

	return 0;
}