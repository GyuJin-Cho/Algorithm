#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr)
{
    vector<string> answer;

    for(int i=0;i<strArr.size();i++)
    {
	    if(strArr[i].find("ad")==string::npos)
	    {
            answer.push_back(strArr[i]);
	    }
    }

    return answer;
}

int main()
{
    vector<string> v = { "and","notad","abcd" };
    vector<string> ans = solution(v);
    for(auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}