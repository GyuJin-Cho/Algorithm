#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;

    string tmp = "";
    bool check = false;
    for(int i=0;i<my_string.size();i++)
    {
	    if(my_string[i]==' '&&check)
	    {
            check = false;
            answer.push_back(tmp);
            tmp = "";
	    }
        else if(my_string[i]>='a'&&my_string[i]<='z')
        {
            check = true;
            tmp += my_string[i];
        }
    }

    if(!tmp.empty())
    {
        answer.push_back(tmp);
    }

    return answer;
}

int main()
{
    vector<string> ans = solution("    programmers ");
    for(auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}