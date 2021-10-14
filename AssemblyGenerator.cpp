// File name: AssemblyGenerator.cpp
// Author: Jeffrey Pan
// VUnetid: panjw
// Email: Jeffrey.w.pan@vanderbilt.edu
// Class: CS3252
// Description: This implements the functions of the AssemblyGenerator

#include "AssemblyGenerator.h"

AssemblyGenerator::AssemblyGenerator() {
  // Nothing to do
}

int AssemblyGenerator::evaluateValue(std::string str) {
  for (uint32_t i = 0; i < str.length(); ++i) {
    if (str[i] == ' ') {
      ++i; // If space go to the next char
    }

    if (str[i] == '(') {
      charstk.push(str[i]);
    }

    else if (isdigit(str[i])) {
      int val = 0;

      // If an integer is found, find the whole number and add it to intstk
      while (i < str.length() && isdigit(str[i])) {
        val = 10 * val + str[i] - '0';
        ++i;
      }

      --i; // This is here because the while loop will increment over the next
           // char
      intstk.push(val);

    } else if (str[i] == ')') {
      // Perform operations until the closing parenthesis is found.
      while (!charstk.empty() && charstk.top() != '(') {
        performOperation();
      }

      // Should pop the remaining ( unless charstk is empty
      if (!charstk.empty()) {
        charstk.pop();
      }
    }

    // If no more parenthesis, perform operations based on precedence
    else {
      while (!charstk.empty() &&
             precedence(charstk.top()) >= precedence(str[i])) {
        performOperation();
      }
      charstk.push(str[i]);
    }
  }

  // Empty the stacks
  while (!charstk.empty()) {
    performOperation();
  }

  return intstk.top();
}

void AssemblyGenerator::clear() {
  while (!intstk.empty()) {
    intstk.pop();
  }
  while (!charstk.empty()) {
    charstk.pop();
  }
}

int AssemblyGenerator::applyOperation(int a, int b, char op) {
  if (op == '+') {
    return a + b;
  }
  if (op == '-') {
    return a - b;
  }
  return a * b;
}

int AssemblyGenerator::precedence(char a) {
  if (a == '*' || a == '/')
    return 2; // Goes first
  if (a == '+' || a == '-')
    return 1; // Goes Second

  return 0;
}

void AssemblyGenerator::performOperation() {
  char operations = charstk.top();
  charstk.pop();
  int first = intstk.top();
  intstk.pop();
  int second = intstk.top();
  intstk.pop();
  int endVal = applyOperation(first, second, operations);
  intstk.push(endVal);
}