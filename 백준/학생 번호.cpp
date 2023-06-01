#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool IsEqual(const vector<string>& comv)
{
	unordered_map<string,int>um;
	for(int i=0;i<comv.size();i++)
	{
		if(um[comv[i]]!=0)
		{
			return false;
		}
		um[comv[i]]++;
	}
	return true;
}


int main()
{
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	int answer = 1;


	while(1)
	{
		vector<string> comv;
		
		for (int i = 0; i < v.size(); i++)
		{
			string tmp = "";
			
			for(int j=v[i].size()-1;j>=(v[i].size()-answer);j--)
			{
				if (j < 0)
					break;
				tmp += v[i][j];
			}
			reverse(tmp.begin(), tmp.end());
			comv.push_back(tmp);
		}
		if(IsEqual(comv))
		{
			cout << answer;
			break;
		}
		answer++;
	}

	return 0;
}