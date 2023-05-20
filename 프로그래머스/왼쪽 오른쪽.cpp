#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list)
{
    vector<string> answer;

    for(int i=0;i<str_list.size();i++)
    {
	    if(str_list[i][0]=='l')
	    {
		    for(int j=0;i< str_list.size();j++)
		    {
			    if(str_list[j][0]=='l')
			    {
					return answer;
			    }
				string tmp = "";
				tmp += str_list[j][0];
				answer.push_back(tmp);
		    }
	    }
		else if(str_list[i][0]=='r')
		{
			for(int j=i+1;j<str_list.size();j++)
			{
				string tmp = "";
				tmp += str_list[j][0];
				answer.push_back(tmp);
			}
			return answer;
		}
    }

    return answer;
}

int main()
{
    vector<string> v = { "u", "u", "u", "r","u"};
    vector<string> ans = solution(v);
    for (string i : ans)
        cout << i << ' ';

    return 0;
}