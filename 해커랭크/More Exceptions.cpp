#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
class Calculator
{
private:
    int n, p;
public:
    int power(int n, int p)
    {
        this->n = n;
        this->p = p;
        if (n < 0 || p < 0)
            throw invalid_argument("n and p should be non-negative");
        else
        {
            if (this->p == 0)
                return 1;
            
            for (int i = 1; i < this->p; i++)
            {
                this->n = this->n *n;
            }
        }
        return this->n;
    }
};
int main()
{
    Calculator myCalculator = Calculator();
    int T, n, p;
    cin >> T;
    while (T-- > 0) {
        if (scanf_s("%d %d", &n, &p) == 2) {
            try {
                int ans = myCalculator.power(n, p);
                cout << ans << endl;
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
        }
    }

}