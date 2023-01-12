#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> array)
{
    int answer = 0;
    for(int i=0;i<array.size();i++)
    {
        string tmp = to_string(array[i]);
        for(int j=0;j<tmp.size();j++)
        {
            if (tmp[j] == '7')
                answer++;
        }
    }
    return answer;
}

int main()
{
    vector<int> v = {10,29 };
    cout << solution(v);
    return 0;
}
