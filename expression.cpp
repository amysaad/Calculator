#include <iostream>
#include <iomanip>
#include <cmath>
#include "expression.h"


using namespace std;

//Method Comments: This method prompts the user to enter a
// calculation, then converts it into postfix and stores the value
//Precondition: Valid user input of a calculation using +,-,*,/,%, or ^ and ending in '='
//Post-condition: Postfix of input calculation

void Expression::CalcInput(float Operand, char Operation) {
    cout << "Enter a calculation: ";
    cin >> Operand;                     //reads operand
    NumStack(Operand);          //pushes operand to vector

    while (true) {
        cin >> Operation;               //reads next operand
        if (Operation == '=') {
            break;
        }
        CharStack(Operation);  //pushes operand to vector
        cin >> Operand;                   //reads next operand
        NumStack(Operand);        //pushes operand to vector
    }
}

//Method Comments: This method looks at the operators when converting
// to postfix and puts them in order of precedence
//Precondition: Operator must be a float
//Post-condition: Operator put in order of precedence

void Expression::CharStack(char TheOperator) {
    if (CharsStack.isFullStack()) {
        CharsStack.push(TheOperator);       //pushes operator to char stack
    } else {
        int operatorPrecedence = Precedence(TheOperator);   //gets precedence of operator

        while (!CharsStack.isFullStack() and operatorPrecedence <= Precedence(CharsStack.top())) {
            PostfixExpression element;              //makes element for postfix expression
            element.Operator = CharsStack.top();    //operator from stack
            element.Number = 0.0;                   //sets number to 0
            element.CheckType = 1;                  //type indicates it's an operator

            PostfixVector.push_back(element);       //adds element to vector
            CharsStack.pop();                       //pops operator from stack
        }

        CharsStack.push(TheOperator);       //pushes current operator to char stack
    }
}

//Method Comments: This method adds a number to the postfix vector
//Precondition: Valid float number
//Post-condition: Number added to vector

void Expression::NumStack(float number) {
    PostfixExpression element;              //makes element for postfix expression
    element.CheckType = 0;                  //type indicates it's a number
    element.Number = number;                //sets number to number
    PostfixVector.push_back(element);       //adds element to vector
}

//Method Comments: This method looks at the operator for its precedence
//Precondition: The operator must be +,-,*,/,%, or ^
//Post-condition: Returns precedence of operator, returns error message if invalid

int Expression::Precedence(char TheOperator) {
    if (TheOperator == ADD or TheOperator == SUBTRACT) {
        return 0;            //returns 0 for + and -
    } else if (TheOperator == MULTIPLY or TheOperator == DIVIDE or TheOperator == MODULO) {
        return 1;            //returns 1 for *, /, and %
    } else if (TheOperator == POWER) {
        return 2;            //returns 2 for ^
    } else {
        cout << "Hm.... error" << endl;
        return 0;
    }
}

//Method Comments: This method completes the calculation based
// on the operator and operand
//Precondition: At least 2 numbers in stack with a valid operator
//Post-condition: Returns the solution of the operation

float Expression::Calculation(char operation, float FirstNum, float SecondNum) {
    float Solution;     //float to store solution

    if (operation == ADD) {
        Solution = SecondNum + FirstNum;    //addition
    } else if (operation == SUBTRACT) {
        Solution = SecondNum - FirstNum;    //subtraction
    } else if (operation == MULTIPLY) {
        Solution = SecondNum * FirstNum;    //multiplication
    } else if (operation == DIVIDE) {
        Solution = SecondNum / FirstNum;    //division
    } else if (operation == MODULO) {
        Solution = fmod(SecondNum, FirstNum);   //modulo division
    } else if (operation == POWER) {
        Solution = pow(SecondNum, FirstNum);    //exponentiation
    } else {
        cout << "Hm.... error" << endl;
        return 0;
    }

    return Solution;    //returns solution
}

//Method Comments: This method looks at the postfix expression
// in the vector and displays the solution
//Precondition: No precondition
//Post-condition: Postfix expression

void Expression::PostFix() {
    for (const PostfixExpression& element : PostfixVector) {
        if (element.CheckType == 0) {
            FloatStack.push(element.Number);    //pushes number onto float stack
        } else {
            float number1 = FloatStack.top();           //gets top of stack
            FloatStack.pop();                           //pops top of stack

            float number2 = FloatStack.top();           //gets next number from stack
            FloatStack.pop();                           //pops next number from stack

            FloatStack.push(Calculation(element.Operator, number1, number2)); //pushes solution to stack

        }
    }

    Display();   //displays result
}

//Method Comments: This method displays the solution
//Precondition: Only one number left in stack
//Post-condition: The solution of the calculation is displayed and removed from the stack

void Expression::Display() {
    cout << fixed << showpoint;
    float FirstValue = FloatStack.top();                          //gets top of stack
    cout << endl << setprecision(3) << FirstValue << endl;     //displays solution with 3 decimal places
    FloatStack.pop();                                             //pops top of stack

}

//Method Comments: This method takes user input of a calculation
// and converts it into postfix and evaluates it
//Precondition: No precondition
//Post-condition: Instance of class made, postfix evaluated

Expression :: Expression() {
    char Operation;
    float Operand;

    CalcInput(Operand, Operation);      //calls method to convert input to postfix
    if (!CharsStack.isFullStack()) {
        while (!CharsStack.isEmptyStack()) {
            PostfixExpression element;              //makes element for postfix expression
            element.Operator = CharsStack.top();    //operator from stack
            element.Number = 0.0;                   //sets number to 0
            element.CheckType = 1;                  //type indicates it's an operator
            PostfixVector.push_back(element);       //adds to vector
            CharsStack.pop();                       //pops from stack
        }

    }
    PostFix();      //postfix method
}













