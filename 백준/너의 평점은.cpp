#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
	unordered_map<string, float> um;
	float mul = 0.0f;
	um["A+"] = 4.5f;
	um["A0"] = 4.0f;
	um["B+"] = 3.5f;
	um["B0"] = 3.0f;
	um["C+"] = 2.5f;
	um["C0"] = 2.0f;
	um["D+"] = 1.5f;
	um["D0"] = 1.0f;
	um["F"] = 0.0f;
	um["P"] = 0.0f;
	string s;
	float grade = 0.0f;
	for(int i=0;i<20;i++)
	{
		getline(cin, s);
		string tmp1 = "";
		for(int i=0;i<s.size();i++)
		{
			if (s[i] == ' ')
			{
				for(int j=i+1;j<s.size();j++)
				{
					tmp1 += s[j];
				}
				break;
			}
		}
		string tmp2="";
		string tmp3 = "";
		for(int i=0;i<tmp1.size();i++)
		{
			if(tmp1[i]==' ')
			{
				for(int j=i+1;j<tmp1.size();j++)
				{
					tmp3 += tmp1[j];
				}
				break;
			}
			tmp2 += tmp1[i];
		}
		if(tmp3!="P")
		{
			grade += stof(tmp2);
			mul = mul + (stof(tmp2) * um[tmp3]);
		}
	}
	float answer = float(mul) / float(grade);
	printf("%.6f", answer);
	return 0;
}