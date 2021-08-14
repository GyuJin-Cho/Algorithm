#include <iostream>
using namespace std;

int main()
{
	int a, b, c, product;
	int quotient, remainder;
	int count[10] = { 0 }; // 인덱스가 해당 숫자이고 그에 해당하는 값이 쓰인 횟수

	cin >> a >> b >> c;
	product = a * b * c;

	do {
		quotient = product / 10;  // 몫을 계산
		remainder = product % 10; // 나머지 계산
		product = quotient;       // 몫을 다시 값으로 받음

		count[remainder]++;       // 나머지가 해당하는 수이므로 해당 인덱스 1 증가

	} while (quotient != 0);     // 몫이 0이 되기 전까지 반복

	for (int i = 0; i < 10; i++)
	{
		cout << count[i] << endl;
	}

	return 0;
}