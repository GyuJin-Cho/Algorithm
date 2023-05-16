#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string code)
{
    string answer = "";
    bool mode = false;
    for(int i=0;i<code.size();i++)
    {
        if (code[i] == '1')
        {
            mode = !mode;
            continue;
        }
	    if(!mode&&i%2==0)
	    {
            answer += code[i];
	    }
        else if(mode&&i%2==1)
        {
            answer += code[i];
        }
    }

    if (!answer.empty())
        return answer;
    else
        return "EMPTY";

    
}

int main()
{
    cout << solution("abc1abc1abc");
    return 0;
}