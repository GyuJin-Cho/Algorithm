#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int sum1=0, mul1=1;
    for(int i=0;i<num_list.size();i++)
    {
        sum1 += num_list[i];
        mul1 *= num_list[i];
    }

    return mul1 < (sum1* sum1) ? 1 : 0;

}

int main()
{
    vector<int> v = { 5, 7, 8, 3 };
    cout << solution(v);

    return 0;
}