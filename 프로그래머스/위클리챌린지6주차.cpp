#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    int idx;
    int weight;
    double winRatio;
    int winAgeinstHeavier;
} Boxer;

bool cmp(Boxer a, Boxer b)
{
	if(a.winRatio>b.winRatio)
	{
        return true;
	}

    if(a.winRatio==b.winRatio)
    {
	    if(a.winAgeinstHeavier>b.winAgeinstHeavier)
	    {
            return true;
	    }
        if(a.winAgeinstHeavier==b.winAgeinstHeavier)
        {
	        if(a.weight>b.weight)
	        {
                return true;
	        }
            if(a.weight==b.weight&&a.idx<b.idx)
            {
                return true;
            }
        }
    }
    return false;
}

vector<int> solution(vector<int> weights, vector<string> head2head)
{
    vector<Boxer> boxers;
    for (int i = 0; i < head2head.size(); i++)
    {
        double wins = 0;
        double total = 0;
        int winAgainstHeavior = 0;
        for (int j = 0; j < head2head[i].length(); j++)
        {
            if (head2head[i][j] == 'N')
            {
                continue;
            }
            total++;
            if (head2head[i][j] == 'W')
            {
                wins++;
                if (weights[i] < weights[j])
                {
                    winAgainstHeavior++;
                }
            }
        }
        boxers.push_back({ i + 1, weights[i], total ? wins / total : 0, winAgainstHeavior });
    }
    sort(boxers.begin(), boxers.end(), cmp);
    vector<int> answer;
    for(auto boxer : boxers)
    {
        answer.push_back(boxer.idx);
    }
    return answer;
}

int main()
{
    vector<int> we = { 50,82,75,120 };
    vector<string> head = { "NLWL","WNLL","LWNW","WWLN" };
    vector<int> answer = solution(we, head);
    for (auto a : answer)
        cout << a << " ";
    return 0;
}