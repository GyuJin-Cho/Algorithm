#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string n_str)
{
    
    return to_string(stoi(n_str));
}
int main()
{
    cout << solution("0010");

    return 0;
}