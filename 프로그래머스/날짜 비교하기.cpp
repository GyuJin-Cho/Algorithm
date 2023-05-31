#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2)
{
    int answer = 0;
    
    if(date1[0] != date2[0])
    {
        return date1[0] < date2[0] ? 1 : 0;
    }
    if(date1[1] != date2[1])
    {
        return date1[1] < date2[1] ? 1 : 0;
    }
    if(date1[2] != date2[2])
    {
        return date1[2] < date2[2] ? 1 : 0;
    }
    
    return answer;
}

int main()
{
    vector<int> date1 = {0,12,31} , date2 = {1,1,1};
    cout<<solution(date1 , date2 );
    
    return 0;
}
