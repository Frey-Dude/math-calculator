#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// i hate github sometimes
float rounding(float var)
{
    char str[40];
    sprintf(str, "%.2f", var);
    sscanf(str, "%f", &var);
    return var;
}

int interest(float P, float R, float T, float paid) {
    for (int i = 0; i < T; i++) {
        float I = P*R;
        I = rounding(I);
        P += I;
        P = rounding(P);
        cout << "new_principle / interest / post paid " << endl;
        cout << P << " / " << I << " / ";
        P -= paid;
        cout << P << endl;
    }
    return 0;
}

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    string input_function;
    cout << "Use 'help' to get list of commands \n enter command now: ";
    cin >> input_function;
    transform(input_function.begin(), input_function.end(), input_function.begin(),
    [](unsigned char c){ return std::tolower(c); });

    if (input_function == "help") {
        cout << "available commands \n interest: I=PRT (with loop for multiple entries at once";
        cout << "\n round: rounds to two decimel places";
    } else if (input_function == "interest") {
        float P, R, T, paid;
        cout << "principle: ";
        cin >> P;
        cout << "rate: ";
        cin >> R;
        cout << "time: ";
        cin >> T;
        std::cout << "paid each period: ";
        std::cin >> paid;
        interest(P, R, T, paid);
    } else if (input_function == "round") {
        float number;
        cout << "enter num: ";
        cin >> number;
        number = rounding(number);
        cout << number;
    }

    return 0;
}