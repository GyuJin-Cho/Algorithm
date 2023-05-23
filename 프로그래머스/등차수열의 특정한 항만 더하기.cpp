#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included)
{
    int answer = 0;
    for(int i=0;i<included.size();i++)
    {
	    if(included[i])
	    {
            answer += a;
	    }
        a += d;
    }

    return answer;
}

int main()
{

    vector<bool> v = { true,false,false,true,true };
    cout << solution(3, 4, v);

    return 0;
}