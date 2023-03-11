#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index)
{
    string answer = "";

	
	vector<char> v;
    for(int i=0;i<s.size();i++)
    {
		int cnt = 1;
	    for(int j = 0 ;j<index;j++)
	    {
		    for(int z=0;z<skip.size();z++)
		    {
				if(s[i]+cnt>'z')
				{
					s[i] = 'a';
					cnt = 0;
					if (s[i] == skip[z])
					{
						j--;
						break;
					}
				}
			    else if(s[i]+cnt==skip[z])
			    {
					j--;
					break;
			    }
		    }
			cnt++;
	    }
		answer += s[i] + cnt - 1;
    }

    return answer;
}

int main()
{
    cout << solution("aukks", "wbqd", 5);

    return 0;
}