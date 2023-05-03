#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int answer = 0;
    string JJack = "";
    string Hol = "";
    for(int i=0;i<num_list.size();i++)
    {
	    if(num_list[i]%2==0)
	    {
            JJack += to_string(num_list[i]);
	    }
        else
        {
            Hol += to_string(num_list[i]);
        }
    }
    answer = stoi(JJack) + stoi(Hol);
    return answer;
}

int main()
{
    vector<int> v = { 3,4,5,2,1 };
    cout << solution(v);

    return 0;
}