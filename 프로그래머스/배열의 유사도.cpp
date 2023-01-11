#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> s1, vector<string> s2)
{
    int answer = 0;

    for(int i=0;i<s2.size();i++)
    {
	    for(int j=0;j<s1.size();j++)
	    {
            if (s1[j] == s2[i])
                answer++;
	    }
    }

    return answer;
}

int main()
{
    vector<string> s1 = { "a","b","c" };
    vector<string> s2 = { "com","b","d","c"};
    cout << solution(s1, s2);

    return 0;
}