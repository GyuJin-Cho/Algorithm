#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> seoul)
{
    string answer = "";
    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
        {
            answer += "김서방은 ";
            answer += to_string(i);
            answer += "에 있다";
        }
    }
    return answer;
}

int main()
{
    vector<string> answer = { "Jane","Kim" };
    cout << solution(answer) << endl;
}