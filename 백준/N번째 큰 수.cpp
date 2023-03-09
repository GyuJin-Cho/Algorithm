#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v(10);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		for(int j=0;j<10;j++)
		{
			cin >> v[j];
			
		}
		sort(v.begin(), v.end(),greater<int>());
		cout << v[2]<<endl;
	}

	return 0;
}