#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n)
{
    int answer = 0;

    for(int i=0;i<array.size();i++)
    {
        if (array[i] == n)
            answer++;
    }

    return answer;
}

int main()
{
    vector<int> v = { 1,1,2,3,4,5 };

    cout << solution(v,1);

	return 0;
}