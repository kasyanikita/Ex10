// Copyright 2021 Kasyanov
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
 private:
  T* Mystack;
  int len;
  int top;
 public:
  explicit MyStack(int);
  MyStack(const MyStack&);
  ~MyStack();
  int CurrLen() const;
  T get() const;
  void push(T);
  T pop();
  bool isFull() const;
  bool isEmpty() const;
};

template<class T>
MyStack<T>::MyStack(int _len): top(-1), len(_len), Mystack(new T[len]) {}

template<class T>
MyStack<T>::MyStack(const MyStack& another_Mystack) {
    top = another_Mystack.top;
    Mystack = new T[another_Mystack.len];
    len = another_Mystack.len;
    for (int i = 0; i < len; ++i) {
        Mystack[i] = another_Mystack.Mystack[i];
    }
}

template<class T>
MyStack<T>::~MyStack() {
    delete[] Mystack;
}

template<class T>
int MyStack<T>::CurrLen() const {
    return top + 1;
}

template<class T>
bool MyStack<T>::isEmpty() const {
    return top == -1;
}

template<class T>
bool MyStack<T>::isFull() const {
    return top == len - 1;
}

template<class T>
T MyStack<T>::get() const {
    if (!isEmpty()) {
        return Mystack[top];
    } else {
        throw "The Mystack is empty";
    }
}

template<class T>
void MyStack<T>::push(T x) {
    if (isFull()) {
        throw "The Mystack is full";
    } else {
        Mystack[++top] = x;
    }
}

template<class T>
T MyStack<T>::pop() {
    if (isEmpty()) {
        throw "The Mystack is empty";
    } else {
        return Mystack[top--];
    }
}

#endif  // INCLUDE_MYSTACK_H_
