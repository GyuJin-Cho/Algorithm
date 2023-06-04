#include<iostream>
#include<map>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;

	map<string, string> m;
	m["000000"] = "A";
	m["001111"] = "B";
	m["010011"] = "C";
	m["011100"] = "D";
	m["100110"] = "E";
	m["101001"] = "F";
	m["110101"] = "G";
	m["111010"] = "H";
	string tmp = "";
	string ans = "";
	int cnt = 1;
	for(int i=0;i<s.size();i++)
	{
		tmp += s[i];
		if((i+1)%6==0)
		{
			if(m[tmp].empty())
			{
				bool check = false;
				for(int j=0;j<tmp.size();j++)
				{
					if(tmp[j]=='0')
					{
						tmp[j] = '1';
						if(!m[tmp].empty())
						{
							ans += m[tmp];
							check = true;
							break;
						}
						else
						{
							tmp[j] = '0';
						}
					}
					else
					{
						tmp[j] = '0';
						if(!m[tmp].empty())
						{
							ans += m[tmp];
							check = true;
							break;
						}
						else
						{
							tmp[j] = '1';
						}
					}
				}
				if(!check)
				{
					cout << cnt;
					return 0;
				}
			}
			else
			{
				ans += m[tmp];
			}
			cnt++;
			tmp = "";
		}
	}
	
	cout << ans;
	

	return 0;
}