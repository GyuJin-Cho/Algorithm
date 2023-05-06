#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(string my_string, string is_prefix)
{
    int answer = 0;
    unordered_set<string> um;
    string tmp = "";
    for(int i=0;i<my_string.size();i++)
    {
        tmp += my_string[i];
        um.insert(tmp);
    }
    for (auto i : um)
    {
	    if(i==is_prefix)
	    {
            answer = 1;
	    }
    }
    return answer;
}

int main()
{
    cout << solution("banana", "nan");

    return 0;
}