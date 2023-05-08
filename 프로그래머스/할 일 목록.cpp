#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> todo_list, vector<bool> finished)
{
    vector<string> answer;

    for(int i=0;i<finished.size();i++)
    {
	    if(!finished[i])
	    {
            answer.push_back(todo_list[i]);
	    }
    }

    return answer;
}

int main()
{
    vector<string> v = { "problemsolving", "practiceguitar", "swim", "studygraph" };
    vector<bool> f = { true, false, true, false };
    vector<string> ans = solution(v, f);
    for(auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}