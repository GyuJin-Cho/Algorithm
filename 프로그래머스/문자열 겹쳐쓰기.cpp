#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s)
{
    string answer = "";

    int cnt = 0;
    for(int i=0;i<s;i++)
    {
        answer += my_string[i];
        cnt++;
    }

    for(int i=0;i<overwrite_string.size();i++)
    {
        answer += overwrite_string[i];
        cnt++;
    }
    if(cnt<my_string.size())
    {
	    for(int i=cnt;i<my_string.size();i++)
	    {
            answer += my_string[i];
	    }
    }
    return answer;
}

int main()
{
    cout << solution("He11oWor1d", "lloWorl", 2);
    return 0;
}