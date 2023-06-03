#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int palindrome(string s, int start, int end)
{
	int flag = 0;
	int TmpStart = 0;
	int TmpEnd = 0 ;
	while(start<end)
	{
		if(s[start]==s[end])
		{
			start++;
			end--;
			continue;
		}
		else
		{
			if(flag==0&&s[start+1]==s[end])
			{
				TmpStart = start;
				TmpEnd = end;
				start++;
				flag = 3;
				continue;
			}
			else if(flag==0&&s[start]==s[end-1])
			{
				end--;
				flag = 1;
				continue;
			}
			else
			{
				if(flag==3)
				{
					start = TmpStart;
					end = TmpEnd - 1;
					flag = 1;
				}
				else
				{
					flag = 2;
					break;
				}
			}
		}
	}
	if(flag==1||flag==3)
	{
		return 1;
	}
	else if(flag==2)
	{
		return 2;
	}
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	string s;
	while (N--)
	{
		cin >> s;
		cout << palindrome(s,0,s.size()-1) << '\n';
		
	}

	return 0;
}