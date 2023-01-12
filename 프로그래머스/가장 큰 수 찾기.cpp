#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array)
{
    vector<int> answer(2);
    
    for(int i=0;i<array.size();i++)
    {
        if(answer[0]<array[i])
        {
            answer[0] = array[i];
            answer[1] = i;
        }

    }

    return answer;
}

int main()
{
    vector<int> arrays = { 9,10,11,8 };

    vector<int> c = solution(arrays);

    for (auto i : c)
        cout << i << " ";

    return 0;
}