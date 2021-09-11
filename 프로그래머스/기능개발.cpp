#include <string>
#include <vector>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int board[1000];
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> p;
    vector<int> pr = progresses;
    vector<int> sp = speeds;
    int size = pr.size();
    int count = 0;
    int c = 1;
    while(true)
    {
        int size = pr.size();
        count++;
        for(int i=0;i<pr.size();i++)
        {
            pr[i] += sp[i];
            p.push(pr[i]);
        }
        
        for(int i=0;i< size;i++)
        {
            int a = p.front();
	        if(a>=100)
	        {
                p.pop();
                board[count]++;
                pr.erase(pr.begin(), pr.begin()+c);
                sp.erase(sp.begin(), sp.begin() + c);
	        }
        }
        if (p.empty())
            break;
        for(int i=0;i<pr.size();i++)
        {
            if (p.size() == 0)
                break;
            p.pop();
        }
    }

    for(int i=0;i<1001;i++)
    {
	    if(board[i]==0)
            continue;
        answer.push_back(board[i]);
    }
    return answer;
}

int main()
{
    vector<int> p = { 95, 90, 99, 99, 80, 99 };
    vector<int> s = { 1, 1, 1, 1, 1, 1 };
    vector<int> v= solution(p, s);
    for(auto i:v)
    {
        cout << i<<" ";
    }
    return 0;
}