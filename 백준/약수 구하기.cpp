#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> v;
	for(int i=1;i<N;i++)
	{
		if(N%i==0)
		{
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	if (v.size() >= K)
		cout << v[K-1];
	else
		cout << 0;

	return 0;
}