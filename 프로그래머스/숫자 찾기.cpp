#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num, int k)
{
    int answer = -1;
    string temp = to_string(num);

    for(int i=0;i<temp.size();i++)
    {
		if(temp[i]==k+48)
		{
            answer = i + 1;
            break;
		}
    }

    return answer;
}

int main()
{
    cout << solution(123456,7);

    return 0;
}