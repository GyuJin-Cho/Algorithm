#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string)
{
    string answer = "";

    for(int i=0;i<my_string.size();i++)
    {
	    if(my_string[i]>='a'&&my_string[i]<='z')
	    {
            answer += toupper(my_string[i]);
	    }
        else
        {
            answer += tolower(my_string[i]);
        }
    }

    return answer;
}

int main()
{
    cout << solution("cccCCC");

    return 0;
}