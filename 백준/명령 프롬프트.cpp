#include<iostream>
#include<map>
#include<string>
using namespace std;
char ch[51][51];
int main()
{
	map<char, int> m;
	int n;
	cin >> n;

	string str;
	int size = 0;
	for(int i=0;i<n;i++)
	{
		cin >> str;
		size = str.size();
		for (int j = 0; j < str.size(); j++)
		{
			ch[i][j] = str[j];
		}
	}

	string output;

	
	for(int i=0;i<size;i++)
	{
		bool flag = true;
		for(int j=0;j<n;j++)
		{
			for(int z=0;z<n;z++)
			{
				if (j == z)
					continue;
				if (ch[j][i] != ch[z][i])
				{
					flag = false;
					output += "?";
					break;
				}
			}
			if(!flag)
				break;
		}
		if (flag)
			output += ch[0][i];
	}

	cout << output;
	return 0;
}