#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr)
{
    vector<string> answer;
    string tmp = "";
    for(int i=0;i<myStr.size();i++)
    {
	    if(myStr[i]=='a'|| myStr[i] == 'b'|| myStr[i] == 'c')
	    {
		    if(tmp.empty())
		    {
			    continue;
		    }
            else
            {
                answer.push_back(tmp);
                tmp = "";
                continue;
            }
	    }
        tmp += myStr[i];
    }
    if (!tmp.empty())
        answer.push_back(tmp);

    if (answer.empty())
        answer.push_back("EMPTY");
    return answer;
}

int main()
{
    vector<string> ans = solution("baconlettucetomato");
    for (string i : ans)
        cout << i << ' ';

    return 0;
}