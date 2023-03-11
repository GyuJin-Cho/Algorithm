#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string my_string)
{
    int answer = 0;

    string temp = "";

    for(int i=0;i<my_string.size();i++)
    {
	    if(my_string[i]>='0'&&my_string[i]<='9')
	    {
            temp += my_string[i];
	    }
        else
        {
            if(!temp.empty())
				answer += stoi(temp);
            temp = "";
        }
    }

    if (!temp.empty())
        answer += stoi(temp);

    return answer;
}

int main()
{
    cout << solution("1000");

	return 0;
}