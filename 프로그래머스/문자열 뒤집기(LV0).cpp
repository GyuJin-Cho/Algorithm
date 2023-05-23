#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

string solution(string my_string, int s, int e)
{
    string answer = "";

    reverse(my_string.begin()+s , my_string.begin()+e+1 );
    
    return my_string;
}

int main()
{
    cout << solution("Progra21Sremm3", 6, 12);

    return 0;
}