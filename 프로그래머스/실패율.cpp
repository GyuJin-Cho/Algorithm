#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(pair<double,double> a, pair<double,double> b)
{
	if(a.second==b.second)
	{
        return a.first < b.first;
	}
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<pair<double, double>> v;
    double count = 1;
    double checkcount = 0;
    double size = stages.size();
    sort(stages.begin(), stages.end());
    for(int i=0;i<N;i++)
    {
	    for(int j=0;j<stages.size();j++)
	    {
		    if(stages[j]==count)
		    {
                checkcount+=1.0;
		    }
	    }
        if(size==0)
        {
            v.push_back({ count,0 });
        }
        else
        {
            v.push_back({ count,checkcount / size });
        }
        size = size - checkcount;
        checkcount = 0;
        count++;
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i : v)
    {
        answer.push_back(i.first);
    }
    return answer;
}

int main()
{
    vector<int> stages = { 4,4,4,4,4 };
    int n = 500;
    vector<int>a = solution(n, stages);
    for(auto i : a)
    {
        cout << i<<" ";
    }
    return 0;
}