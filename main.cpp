// File name: Main.cpp
// Author: Jeffrey Pan
// VUnetid: panjw
// Email: Jeffrey.w.pan@vanderbilt.edu
// Class: CS3252
// Description: This holds the test cases to test the AssemblyGenerator

#include "AssemblyGenerator.h"
#include <vector>

int main() {
  std::cout << "These are the test cases" << std::endl;

  AssemblyGenerator gen;
  std::vector<std::string> vctr;

  AssemblyGenerator();
  vctr.push_back("12");
  vctr.push_back("(12)");
  vctr.push_back("3 + 4 * 2");
  vctr.push_back("3 * 4 + 2");
  vctr.push_back("(3 + 4) * 2");
  vctr.push_back("(((3 + 4) * 2 + 4))");
  vctr.push_back("(12 * 2) + ((2 + 4) * 3)) * (((3 * 2) + 4))");
  vctr.push_back("2 + ((3 *(((5 + 7) * 2)) + 17 * 3) + 1) * 3");
  // The case above didn't have an operator next to the first 3, so I assume its
  // addition
  vctr.push_back("(((((2 * 3) + 1) )))");
  vctr.push_back("(( 3 * 32) + 1) * ((2 + 7 * 2) + ((4 * 3)))");

  //// Performs the calculation and prints it, then clears the gen.
  for (size_t i = 0; i < 10; ++i) {
    std::cout << "[" << i + 1 << "] -> ";
    std::cout << std::to_string(gen.evaluateValue(vctr[i])) << std::endl;
    gen.clear();
  }

  return 0;
}
