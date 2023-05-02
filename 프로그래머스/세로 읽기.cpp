#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c)
{
    string answer = "";
    string tmp[1001];
    int size = -1;
    int cnt = 0;
    for(int i=0;i<my_string.size();i=i+m)
    {
        size++;
	    for(int j=cnt;j<m+i;j++)
	    {
            tmp[size] += my_string[j];
            cnt++;
	    }
    }
    for(int i=0;i<=size;i++)
    {
        answer += tmp[i][c - 1];
    }

    return answer;
}

int main()
{
    cout << solution("programmers", 1, 1);

    return 0;
}