#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices)
{
    string answer = "";
    for(int i=0;i<indices.size();i++)
    {
        my_string[indices[i]]=' ';
    }

    for(int i=0;i<my_string.size();i++)
    {
	    if(my_string[i]!=' ')
	    {
            answer += my_string[i];
	    }
    }
    return answer;
}

int main()
{
    vector<int> ind = { 1, 16, 6, 15, 0, 10, 11, 3 };
    cout << solution("apporoograpemmemprs", ind);

    return 0;
}