#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat)
{
    string answer = "";
    int MaxIndex = -217400000;
    for(int i=0;i<myString.size()-pat.size()+1;i++)
    {
        string tmp = "";
	    for(int j=i;j<pat.size()+i;j++)
	    {
            tmp += myString[j];
	    }
        if(tmp==pat)
        {
            MaxIndex = max(i, MaxIndex);
        }
    }

    for(int i=0;i<MaxIndex+pat.size();i++)
    {
        answer += myString[i];
    }

    return answer;
}

int main()
{
    cout << solution("AdEE", "dEE");

    return 0;
}