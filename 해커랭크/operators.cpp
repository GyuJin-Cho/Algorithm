#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'solve' function below.
 *
 * The function accepts following parameters:
 *  1. DOUBLE meal_cost
 *  2. INTEGER tip_percent
 *  3. INTEGER tax_percent
 */

void solve(double meal_cost, double tip_percent, double tax_percent)
{
    double answer = (meal_cost + ((tip_percent / 100) * meal_cost) + ((tax_percent / 100) * meal_cost));
    int check = answer;
    if (answer - check >= 0.5)
    {
        cout << ceil(answer);
    }
    else
    {
        cout << floor(answer);
    }
}

int main()
{
    string meal_cost_temp;
    getline(cin, meal_cost_temp);

    double meal_cost = stod(ltrim(rtrim(meal_cost_temp)));

    string tip_percent_temp;
    getline(cin, tip_percent_temp);

    int tip_percent = stod(ltrim(rtrim(tip_percent_temp)));

    string tax_percent_temp;
    getline(cin, tax_percent_temp);

    int tax_percent = stod(ltrim(rtrim(tax_percent_temp)));

    solve(meal_cost, tip_percent, tax_percent);

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    return s;
}

string rtrim(const string& str) {
    string s(str);

    return s;
}
