#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
	int answer = 0;
	for (int i = 0; i < absolutes.size(); i++)
	{
		if (signs[i])
			answer += absolutes[i];
		else
			answer -= absolutes[i];
	}
	return answer;

}

int main()
{
	vector<int> absolutes = { 1,2,3 };
	vector<bool> signs = { false,false,true };
	cout << solution(absolutes, signs);
	system("Pause");
	return 0;
}