#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;

    for(int i=0;i<my_string.size();i++)
    {
        string tmp = "";
	    for(int j=i;j<my_string.size();j++)
	    {
            tmp += my_string[j];
	    }
        answer.push_back(tmp);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<string> ans = solution("banana");
    for(auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}