#ifndef CARDSTACK_H
#define CARDSTACK_H
#include <stdlib.h>
#include <vector>
#include <new>
#include <stdio.h>
#include <iostream>
#include <time.h>

template<typename T>
class CardStack{

public:
  CardStack();
  T printVector(const int &x);
  T deal();
  void shuffle();
  void push(T const& elem);
  int getSize();

private:
  std::vector<T> vectorElements;
};

template <typename T>
CardStack<T>::CardStack(){}

template <typename T>
void CardStack<T>::push(T const& elem)
{
  vectorElements.push_back(elem);
}

template <typename T>
T CardStack<T>::printVector(const int &x)
{
  return vectorElements[x];
}

template <typename T>
void CardStack<T>::shuffle()
{
  srand( (unsigned)time(NULL) );
  for(int i=0; i<vectorElements.size();i++)
  {
    T temp;
    int x = rand()%vectorElements.size();
    temp = vectorElements[x];
    vectorElements[x] = vectorElements[i];
    vectorElements[i] = temp;
  }
}

template <typename T>
T CardStack<T>::deal()
{
  Card temp;
  temp = vectorElements.back();
  vectorElements.pop_back();
  //std::cout<<"| "<<temp.print()<<" |"<<" was dealed.\n";
  return temp;
}

template <typename T>
int CardStack<T>::getSize()
{
  return vectorElements.size();
}

#endif
