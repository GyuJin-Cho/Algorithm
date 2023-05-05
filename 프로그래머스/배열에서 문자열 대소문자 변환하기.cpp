#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr)
{
    vector<string> answer;

    for(int i=0;i<strArr.size();i++)
    {
        string tmp = "";
	    for(int j=0;j<strArr[i].size();j++)
	    {
		    if(i%2==0)
		    {
                tmp += tolower(strArr[i][j]);
		    }
            else
            {
                tmp += toupper(strArr[i][j]);
            }
	    }
        answer.push_back(tmp);
    }

    return answer;
}

int main()
{
    vector<string> v = { "AAA","BBB","CCC","DDD" };
    vector < string> ans = solution(v);
    for(auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}