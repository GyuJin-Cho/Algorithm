#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class A
{
private:
	string tmp1;
	string tmp2;

public:
	A(string s) : tmp1(s),tmp2(s)
	{
		
	}
	~A()
	{
		
	}

	void print()
	{
		reverse(tmp2.begin(), tmp2.end());
		if (tmp1 == tmp2)
			cout << 1;
		else
			cout << 0;
	}

};
int main()
{
	string s;
	cin >> s;
	A* a = new A(s);
	a->print();
	delete a;
	return 0;
}