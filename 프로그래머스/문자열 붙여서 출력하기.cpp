#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str1, str2;
    cin >> str1 >> str2;
    string answer = "";
    answer += str1;
    answer+=str2;
    cout << answer;
    return 0;
}