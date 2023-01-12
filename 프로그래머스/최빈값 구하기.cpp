#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int c[1001] = { 0, };
int solution(vector<int> array)
{
    int answer = 0;
	for(int i=0;i<array.size();i++)
	{
        c[array[i]]++;
	}

    int Max = 0;

    for(int i=0;i<1001;i++)
    {
	    if(c[i]>Max)
	    {
            Max = c[i];
            answer = i;
	    }
    }

    int cnt = 0;

    for(int i=0;i<1001;i++)
    {
        if (c[i] == Max)
            cnt++;
    }

    if (cnt > 1)
        return -1;
    return answer;
}

int main()
{
    vector<int> a = { 1,1,1,2,2,3,3,3,4,4,4,5,5,5,5 };
    cout << solution(a);
    return 0;
}