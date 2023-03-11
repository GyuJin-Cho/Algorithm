#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list)
{
    vector<int> answer;
    int jjak=0, hol=0;

    for(int i=0;i<num_list.size();i++)
    {
        if (num_list[i] % 2 == 0)
            jjak++;
        else
            hol++;
    }
    answer.push_back(jjak);
    answer.push_back(hol);
    return answer;
}

int main()
{
    vector<int> numlist = { 1,2,3,4,5 };
    vector<int> a = solution(numlist);

    for(auto i : a)
    {
        cout << i << " ";
    }

    return 0;
}