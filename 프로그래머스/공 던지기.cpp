#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k)
{
    int answer = 0;
    int cnt = 1;
    int i = 0;
    bool Revers = false;
	while(1)
	{
        if(cnt==k)
        {
            answer = numbers[i];
            break;
        }
        if(i+2>numbers.size()-1)
        {
            i = (i+2)-numbers.size();
            cnt++;
        }
        else
        {
            i += 2;
            cnt++;
        }
	}

    return answer;
}

int main()
{
    vector<int> numbers = { 1,2,3};
    cout << solution(numbers, 3);

    return 0;
}