#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<ctime>
#include<iostream>
using namespace std;

int main()
{
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    cout << t->tm_year + 1900 << '\n';
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mon + 1 << '\n';
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mday;

	return 0;
}