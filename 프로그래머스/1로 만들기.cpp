#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> num_list)
{
    int answer = 0;
    int cnt;
    for(int i=0;i<num_list.size();i++)
    {
        cnt = 0;
	    while(num_list[i]!=1)
	    {
            cnt++;
		   if(num_list[i]%2==0)
		   {
               num_list[i] /= 2;
		   }
           else
           {
               num_list[i] = (num_list[i] - 1) / 2;
           }
	    }
        answer += cnt;
    }

    return answer;
}

int main()
{
    vector<int> num = { 12,4,15,1,14 };
    cout << solution(num);

    return 0;
}