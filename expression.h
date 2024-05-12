#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "stack.h"
#include "expression.h"
using namespace std;


enum TheOperation  {
    ADD = '+',          //addition operation
    SUBTRACT = '-',     //subtraction operation
    MULTIPLY = '*',     //multiplication operation
    DIVIDE = '/',       //division operation
    MODULO = '%',       //modulo operation
    POWER = '^',        //exponential operation
};

class Expression {
public:
    void CalcInput(float, char);            //method for user input
    void CharStack(char);                   //method for char stack
    void NumStack(float);                   //method for num stack
    int Precedence(char);                   //method to return precedence of operation
    float Calculation(char, float, float);  //method that calculates based on operation and operand
    void PostFix();                         //method to evaluate postfix expression
    void Display();                         //method to display the solution to calculation
    Expression();

    struct PostfixExpression {              //struct for vector
        char Operator;                      //operator
        float Number;                       //number value
        int CheckType;                      //checks input type

    };


    stackType<float> FloatStack;              //float stack
    stackType<char>  CharsStack;              //char stack
    vector<PostfixExpression> PostfixVector;  //vector for postfix

};

#endif //EXPRESSION_H