#include <iostream>
#include <cmath>
using namespace std;

int int_conversion(string s) {

    /*
        This function converts a string to a number and checks whether the number is in the range of __int32_t.
    */

    int num;
    try {
    
        num = stoi(s);
    
    } catch(invalid_argument const& ex) {
    
        throw invalid_argument("Error while converting string to number, please try again.\n");
    
    } catch(out_of_range const& ex) {
    
        throw invalid_argument("This calculator can only handle double, please try again with a smaller input.\n");
    
    }
    return num;
}


double double_conversion(string s) {

    /*
        This function converts a string to a number and checks whether the number is in the range of double.
    */

    double num;
    try {
    
        num = stod(s);
    
    } catch(invalid_argument const& ex) {
    
        throw invalid_argument("Error while converting string to number, please try again.\n");
    
    } catch(out_of_range const& ex) {
        
        throw invalid_argument("This calculator can only handle double, please try again with a smaller input.\n");
    
    }
    return num;
}

int main(int argc, char** argv) {
    
    if (argc == 4) {

        /*
            Format: 
            argv[1]: First number.
            argv[2]: Operator, one of the following: {"+","-","x","/", "%"}.
            argv[3]: Second number.
            Do not handle the case where the result is overflowed.
        */

        int firstNumber, secondNumber;
        string op = argv[2];

        firstNumber = int_conversion(argv[1]);
        secondNumber = int_conversion(argv[3]);

        if (op == "+") {

            cout << firstNumber + secondNumber << endl;

        } else if (op == "-") {

            cout << firstNumber - secondNumber << endl;

        } else if (op == "x") {

            cout << firstNumber * secondNumber << endl;

        } else if (op == "/") {
            
            // Need to handle the case where the second number is zero.
            if (secondNumber == 0) {
                throw invalid_argument("Division by zero!\n");
                exit(0);
            }
            cout << firstNumber / secondNumber << endl;

        } else if (op == "%") { 

            // Need to handle the case where the second number is zero.
            if (secondNumber == 0) {
                throw invalid_argument("Division by zero!\n");
                exit(0);
            }

            cout << firstNumber % secondNumber << endl;

        } else {

            throw invalid_argument("Your operator is not supported!\n");
        
        }
    }
    
    else if (argc == 3) {

        /*
            Format: 
            argv[1]: Operator, one of the following: {"sin", "cos", "tan", "sqrt"}
        */

        string op = argv[1];
        double firstNumber = double_conversion(argv[2]);

        if (op == "sin") {
        
            cout << sin(firstNumber) << endl;
        
        } else if (op == "cos") { 
        
            cout << cos(firstNumber) << endl;
        
        } else if (op == "tan") {
        
            // Maybe I need to handle the case where the tan function is undefined?
            cout << tan(firstNumber) << endl;
        
        } else if (op == "sqrt") {
        
            if (firstNumber < 0) {
                throw invalid_argument("Taking square root of a negative number!");
            }

            cout << sqrt(firstNumber) << endl;
        
        } else {

            throw invalid_argument("Your operator is not supported!\n");
        
        }
    }

    else {

        throw invalid_argument("Your operator is not supported!\n");

    }
}