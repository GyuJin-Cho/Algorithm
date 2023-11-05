#include <iostream>
#include <string>
#include <vector>

using namespace std;
int answer = 0;
string alpha = "AEIOU";
string target;
int cnt;
void DFS(string sum)
{
    cnt++;
	if(target == sum)
	{
        answer = cnt;
        return;
	}
    if (sum.length() == 5)
        return;
    for(int i=0;i<5;i++)
    {
        DFS(sum + alpha[i]);
    }
}

int solution(string word)
{
    
    target = word;
    DFS("");

    return answer - 1;
}

int main()
{
    cout << solution("EIO");

    return 0;
}