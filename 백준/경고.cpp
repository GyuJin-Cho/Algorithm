#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string start, end;
	cin >> start>>end;

	if(start==end)
	{
		cout << "24:00:00";
		return 0;
	}

	int sHour = stoi(start.substr(0, 2));
	int sMin = stoi(start.substr(3, 6));
	int sSec = stoi(start.substr(6, 9));

	int eHour = stoi(end.substr(0, 2));
	int eMin = stoi(end.substr(3, 6));
	int eSec = stoi(end.substr(6, 9));

	int fSec = eSec - sSec;
	if(fSec<0)
	{
		fSec += 60;
		eMin--;
	}
	int fMin = eMin - sMin;
	if(fMin<0)
	{
		fMin += 60;
		eHour--;
	}
	int fHour = eHour - sHour;
	if(fHour<0)
	{
		fHour += 24;
	}

	string answer;
	if(fHour<10)
	{
		answer = answer + "0" + to_string(fHour) + ":";
	}
	else
	{
		answer = answer + to_string(fHour) + ":";
	}
	if (fMin < 10)
	{
		answer = answer + "0" + to_string(fMin) + ":";
	}
	else
	{
		answer = answer + to_string(fMin) + ":";
	}
	if (fSec < 10)
	{
		answer = answer + "0" + to_string(fSec) ;
	}
	else
	{
		answer = answer + to_string(fSec);
	}

	cout << answer;
	return 0;
}