#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_map<string, string> m;
	string a = "";
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		bool check = false;
		string adress = "";
		string password = "";
		cin >> adress >> password;
		m.insert({ adress,password });
	}

	for (int i = 0; i < K; i++)
	{
		string a;
		cin >> a;
		cout << m[a] << "\n";
	}

	return 0;
}