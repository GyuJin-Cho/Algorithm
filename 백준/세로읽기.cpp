#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

char S[16][16];

int main()
{
	string s;
	int Col = 0;
	while(1)
	{
		getline(cin,s);
		if (s == "")
			break;
		for(int i=0;i<s.size();i++)
		{
			S[Col][i] = s[i];
		}
		Col++;
	}

	for(int i=0;i<16;i++)
	{
		for(int j=0;j<Col;j++)
		{
			if (S[j][i] == '\0')
				continue;
			cout << S[j][i];
		}
	}

	return 0;
}