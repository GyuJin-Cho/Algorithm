#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct node
{
    vector<int> q1;
    vector<int> q2;
    int cnt;
};

int Size;
int JumpIndex(int idx)
{
    return idx + 1 >= 2 * Size ? 0 : idx + 1;
}

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = 0;

    long long sum1 = 0, sum2 = 0;
    for(int i=0;i<queue1.size();i++)
    {
        sum1 += queue1[i];
    }
    for (int i = 0; i < queue2.size(); i++)
    {
        sum2 += queue2[i];
    }
    Size = queue1.size();
    vector<int> tmp = queue1;
    for(int i=0;i<queue2.size();i++)
    {
        tmp.push_back(queue2[i]);
    }
    int q1s = 0, q1e = Size - 1;
    int q2s = Size, q2e = Size * 2 - 1;

    while(answer<=4*Size) 
    {
        if (sum1 > sum2)
        {
            sum1 -= tmp[q1s];
            sum2 += tmp[q1s];

            q1s = JumpIndex(q1s);
            q2e = JumpIndex(q2e);
        }
        else if (sum1 < sum2)
        {
            sum2 -= tmp[q2s];
            sum1 += tmp[q2s];

            q2s = JumpIndex(q2s);
            q1e = JumpIndex(q1e);
        }
        else
            return answer;
        answer++;
    }


    return -1;
}

int main()
{
    cout << solution({ 1,1 }, { 1,5 });

    return 0;
}