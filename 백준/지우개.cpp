#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>

using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> v;
	for(int i=0;i<N;i++)
	{
		v.push_back(i+1);
	}

	while(v.size()!=1)
	{
		for(int i=0;i<v.size();i++)
		{
			if((i+1)%2==1)
			{
				v[i] = 0;
			}
		}
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==0)
			{
				v.erase(v.begin() + i);
				i--;
			}
		}
	}

	cout << v[0];
	return 0;
}