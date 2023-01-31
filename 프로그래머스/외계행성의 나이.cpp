#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int age)
{
    string answer = "";

    string Age = to_string(age);

    for(int i=0;i<Age.size();i++)
    {
        answer+=Age[i]+49;
    }

    return answer;
}

int main(int argc, char* argv[])
{
    cout << solution(100);

	return 0;
}