#include <iostream>
#include "Statistic.h"

Statistic::Statistic(){}

void Statistic::recordData(bool x)
{
  if(x==true)stat.push_back(1);
  if(x==false)stat.push_back(0);
}

int Statistic::getData(const int &x)
{
  return stat[x];
}

int Statistic::getDataSize()
{
  return stat.size();
}

int Statistic::numberOfWin()
{
  int win = 0;
  for(int i=0; i < stat.size(); i++)
  {
    if(stat[i] == 1) win++;
  }
  return win;
}

int Statistic::numberOfLose()
{
  int lose = 0;
  for(int i=0; i < stat.size(); i++)
  {
    if(stat[i] == 0) lose++;
  }
  return lose;
}
