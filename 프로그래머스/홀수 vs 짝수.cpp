#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int answer = 0;
    int hol = 0;
    int jjack = 0;
    for(int i=0;i<num_list.size();i++)
    {
	    if((i+1)%2==1)
	    {
            hol += num_list[i];
	    }
        else
        {
            jjack += num_list[i];
        }
    }

    answer = max(hol, jjack);
    return answer;
}

int main()
{
    vector<int> v = { 4,2,6,1,7,6 };
    cout << solution(v);

    return 0;
}