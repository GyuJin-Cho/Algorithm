#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts)
{
    string answer = "";

    for(int i=0;i<my_strings.size();i++)
    {
	    for(int j=parts[i][0];j<=parts[i][1];j++)
	    {
            answer += my_strings[i][j];
	    }
    }

    return answer;
}

int main()
{
    vector<string> s = { "progressive", "hamburger", "hammer", "ahocorasick" };
    vector<vector<int>> p = { {0,4},{1,2},{3,5},{7,7} };
    cout << solution(s, p);

    return 0;
}