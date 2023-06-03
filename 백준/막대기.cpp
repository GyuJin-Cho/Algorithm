#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v(N);
	for(int i=0;i<N;i++)
	{
		cin >> v[i];
	}
	int ans = 0;
	int Max = -21740000;

	for(int i = v.size()-1;i>=0;i-- )
	{
		if(v[i]>Max)
		{
			ans++;
			Max = v[i];
		}
	}
	cout << ans;

	return 0;
}