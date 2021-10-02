#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    string tmp = "";
    vector<string> a;
    for(int i=0;i<s.length();i++)
    {
	    if(s[i]==' ')
	    {
            tmp += ' ';
            a.push_back(tmp);
            tmp = "";
		    continue;
	    }
        tmp += s[i];
    }
    a.push_back(tmp);
    for(int i=0;i<a.size();i++)
    {
        a[i][0] = toupper(a[i][0]);
	    for(int j=1;j<a[i].length();j++)
	    {
            if (a[i][j] == ' ')
                break;
            
            if(j%2==0)
            {
                a[i][j] = toupper(a[i][j]);
            }
            else if(j%2!=0)
            {
                a[i][j] = tolower(a[i][j]);
            }
	    }
    }
    for(int i=0;i<a.size();i++)
    {
        answer += a[i];
    }
    return answer;
}

int main()
{
    cout << solution("a");
    return 0;
}