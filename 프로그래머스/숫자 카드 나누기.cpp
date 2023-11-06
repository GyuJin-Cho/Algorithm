#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MIN = -21740000;
int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;

    int MaxSize = *max_element(arrayA.begin(), arrayA.end());
    MaxSize = max(MaxSize, *max_element(arrayB.begin(), arrayB.end()));
    int MaxA = MIN;
    int MaxB = MIN;
    for(int i=2;i<=MaxSize;i++)
    {
        bool ch = false;
	    for(int j=0;j<arrayA.size();j++)
	    {
		    if(arrayA[j]%i!=0)
		    {
                ch = true;
                break;
		    }
	    }
        if(ch)
            continue;
        bool ch1 = false;
        for(int j=0;j<arrayB.size();j++)
        {
	        if(arrayB[j]%i==0)
	        {
                ch1 = true;
                break;
	        }
        }
        if (!ch1)
            MaxA = i;
    }

    for (int i = 2; i <= MaxSize; i++)
    {
        bool ch = false;
        for (int j = 0; j < arrayA.size(); j++)
        {
            if (arrayB[j] % i != 0)
            {
                ch = true;
                break;
            }
        }
        if (ch)
            continue;
        bool ch1 = false;
        for (int j = 0; j < arrayB.size(); j++)
        {
            if (arrayA[j] % i == 0)
            {
                ch1 = true;
                break;
            }
        }
        if (!ch1)
            MaxB = i;
    }

    answer = max(MaxA, MaxB);
    if (answer == MIN)
        answer = 0;
    return answer;
}

int main()
{
    cout << solution({ 5 }, { 8 });

    return 0;
}