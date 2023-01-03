#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<string, int> AddM;
	unordered_map<string, long long> MulM;
	long long ans = 0;;
	AddM["black"] = 0;
	AddM["brown"] = 1;
	AddM["red"] = 2;
	AddM["orange"] = 3;
	AddM["yellow"] = 4;
	AddM["green"] = 5;
	AddM["blue"] = 6;
	AddM["violet"] = 7;
	AddM["grey"] = 8;
	AddM["white"] = 9;

	MulM["black"] = 1;
	MulM["brown"] = 10;
	MulM["red"] = 100;
	MulM["orange"] = 1000;
	MulM["yellow"] = 10000;
	MulM["green"] = 100000;
	MulM["blue"] = 1000000;
	MulM["violet"] = 10000000;
	MulM["grey"] = 100000000;
	MulM["white"] = 1000000000;

	string str;
	string temp;
	for(int i=0;i<3;i++)
	{
		cin >> str;
		if (i == 2)
			ans = stoi(temp) * MulM[str];
		else
			temp += to_string(AddM[str]);
	}
	cout << ans;
	return 0;
}