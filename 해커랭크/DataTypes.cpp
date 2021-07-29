#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";


    // Declare second integer, double, and String variables.

    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.

    // Print the sum of both integer variables on a new line.

    // Print the sum of the double variables on a new line.

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

    int m_nInput = 0;
    double m_dInput = 0.0f;
    string str_input="";
    cin >> m_nInput;
    cin >> m_dInput;
    getline(cin, str_input);
    getline(cin, str_input);
    cout << m_nInput + i << endl;
    printf("%0.1f\n", m_dInput + d);
    cout<< s<<str_input;
    return 0;
}
