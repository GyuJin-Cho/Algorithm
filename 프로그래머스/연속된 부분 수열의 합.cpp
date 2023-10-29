#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;

    int s = 0;
    int e = 0;
    int sum = sequence[0];
    int Len = sequence.size() + 1;
    pair<int, int> res;

    while(s<=e&&e<(int)(sequence.size()))
    {
	    if(sum<k)
	    {
            e++;
            sum += sequence[e];
	    }
        else if(sum==k)
        {
			if(e-s+1<Len)
			{
                Len = e - s + 1;
                res = { s,e };
			}
            else if(e-s+1==Len)
            {
	            if(s<res.first)
	            {
                    res = { s,e };
	            }
            }
            sum -= sequence[s];
            s++;
        }
        else
        {
            sum -= sequence[s];
            s++;
        }
        
    }
    
    answer.push_back(res.first);
    answer.push_back(res.second);
    return answer;
}

int main()
{
    vector<int> seq = { 1, 1, 1, 2, 3, 4, 5};
    vector<int> v = solution(seq, 5);
    for(auto i : v)
    {
        cout << i << ' ';
    }

    return 0;
}