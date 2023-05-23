#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    string answer="";
    for(int i=0;i<str.size();i++)
    {
	    if(str[i]>='A'&&str[i]<='Z')
	    {
            char s = str[i] + 32;
            answer += s;
	    }
        else
        {
            char s = str[i] - 32;
            answer += s;
        }
    }
    cout << answer;
    return 0;
}