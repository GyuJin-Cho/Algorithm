#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = -11;

    for(int i=0;i<numbers.size();i++)
    {
	    for(int j=0;j<numbers.size();j++)
	    {
		    if(i==j)
                continue;
            answer = max(numbers[i] * numbers[j], answer);
	    }
    }

    return answer;
}

int main()
{
    vector<int> v = { 0, 31, 24, 10, 1, 9 };
    cout << solution(v);
    return 0;
}