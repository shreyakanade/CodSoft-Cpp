#include <iostream>
using namespace std;

int main() {
    char op;
    double a, b, res;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    switch (op) {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    default:
        cout << "Invaild choice";
        return res ;
    }
    
     
   
    cout << "Result: " << res;
    return 0;
}
