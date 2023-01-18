#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    answer.push_back(1);

    for(int i=2;i<=n;i++)
    {
	    if(n%i==0)
	    {
            answer.push_back(i);
	    }
    }

    return answer;
}

int main()
{
    vector<int> a = solution(29);

    for (auto i : a)
        cout << i << " ";

    return 0;
}