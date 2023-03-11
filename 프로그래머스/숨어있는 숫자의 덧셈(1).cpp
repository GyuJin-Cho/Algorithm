#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string my_string)
{
    int answer = 0;

    for(auto i : my_string)
    {
	    if(i>='0'&&i<='9')
	    {
            answer += (i - 48);
	    }
    }

    return answer;
}

int main()
{
    cout << solution("1a2b3c4d123");

	return 0;
}