#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n)
{
    vector<string> answer;
    string temp="";
    for(int i=0;i<my_str.size();i++)
    {
        temp += my_str[i];
        if((i+1)%n==0)
        {
            answer.push_back(temp);
            temp = "";
        }
    }

    if(temp!="")
    {
        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    vector<string> a = solution("abcdef123", 3);

    for (auto i : a)
        cout << i << endl;

	return 0;
}