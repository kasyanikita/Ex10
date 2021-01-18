// Copyright 2021 Kasyanov
#include <iostream>
#include <string>
#include "../include/postfix.h"

int main() {
  std::string s("3 + 2.6");
  std::cout << infix2postfix(s) << '\n';
  s = "2 + (6 - 2.7) * 7";
  std::cout << infix2postfix(s) << '\n';
  s = "2 + (6 - 154.7) * 7";
  std::cout << infix2postfix(s) << '\n';
  s = "2.547 * (6.487 - 154.7) / 7.46468";
  std::cout << infix2postfix(s) << '\n';
  return 0;
}
