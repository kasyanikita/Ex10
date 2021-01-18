// Copyright 2021 Kasyanov
#include <map>
#include <set>
#include "../include/postfix.h"
#include "../include/MyStack.h"

std::string infix2postfix(std::string infix) {
  std::string postfix;
  std::map<char, int> priority = {{'(', 0}, {')', 1}, {'+', 2},
                                  {'-', 2}, {'*', 3}, {'/', 3}};
  std::set<char> operations = {'+', '-', '*', '/', '(', ')'};
  MyStack<char> oper(200);
  for (int i = 0; i < infix.size(); ++i) {
    if (infix[i] == ' ') {
      continue;
    }
    if (operations.count(infix[i]) == 0) {
      postfix += infix[i];
      if (i < infix.size() - 1 && infix[i + 1] == ' ' || infix[i + 1] == ')') {
        postfix += ' ';
      }
      if (i == infix.size() - 1) {
        postfix += ' ';
      }
    } else {
      if (oper.isEmpty()) {
        oper.push(infix[i]);
      } else {
        if (infix[i] == '(') {
          oper.push(infix[i]);
          continue;
        }
        if (infix[i] == ')') {
          while (oper.get() != '(') {
            postfix += oper.pop();
            postfix += ' ';
          }
          oper.pop();
          continue;
        }
        while (!(oper.isEmpty()) &&
               priority[oper.get()] >= priority[infix[i]]) {
          postfix += oper.pop();
          postfix += ' ';
        }
        oper.push(infix[i]);
      }
    }
  }
  while (oper.CurrLen() > 1) {
    postfix += oper.pop();
    postfix += ' ';
  }
  if (oper.CurrLen() == 1) {
    postfix += oper.pop();
  }
  return postfix;
}
