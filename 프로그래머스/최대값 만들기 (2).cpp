#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> numbers)
{
    int answer = -100000001;

    for(int i=0;i<numbers.size();i++)
    {
	    for(int j=0;j<numbers.size();j++)
	    {
		    if(i==j)
                continue;

            answer = max(answer, numbers[i] * numbers[j]);
	    }
    }

    return answer;
}

int main()
{
    vector<int> num = {-10000,9999 };

    cout << solution(num);

    return 0;
}