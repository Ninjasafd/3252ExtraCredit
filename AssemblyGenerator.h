// File name: AssemblyGenerator.h
// Author: Jeffrey Pan
// VUnetid: panjw
// Email: Jeffrey.w.pan@vanderbilt.edu
// Class: CS3252
// Description: This declares the AssemblyGenerator functions

#ifndef INC_3252EXTRAC_ASSEMBLYGENERATOR_H
#define INC_3252EXTRAC_ASSEMBLYGENERATOR_H

#include <iostream>
#include <stack>
#include <string>
class AssemblyGenerator {
public:
  /**
   * Constructor
   */
  AssemblyGenerator();

  /**
   * pushOnto
   * @brief   This method pushes the necessary chars onto the stack
   * @param   <str> holds the characters to be pushed
   */
  int evaluateValue(std::string str);

  /**
   * clear
   * @brief   Clears the symbols on the stack
   */
  void clear();

  /**
   * Applies the operation on a and b and returns it
   * @param <a> First integer
   * @param <b> Second integer
   * @param <op> Operator used
   * @return <op> result of operation
   */
  int applyOperation(int a, int b, char op);

  /**
   * Returns value of precedence, 2 for * or division, 1 for +-, else (no
   * parenthesis)
   * @param <a> operator
   * @return the value of the precedence
   */
  int precedence(char a);

  /**
   * Takes the top two values from intstk and top value of charstk and performs
   *    the proper calculation
   */
  void performOperation();

private:
  // Stores the operators
  std::stack<char> charstk;

  // Stores the values of integers
  std::stack<int> intstk;
};

#endif // INC_3252EXTRAC_ASSEMBLYGENERATOR_H
