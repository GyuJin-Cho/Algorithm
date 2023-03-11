#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height)
{
    int answer = 0;

    for(int i=0;i<array.size();i++)
    {
        if (array[i] > height)
            answer++;
    }

    return answer;
}

int main()
{
    vector<int> arrays = { 149, 180, 192, 170 };

    cout << solution(arrays,167);

	return 0;
}