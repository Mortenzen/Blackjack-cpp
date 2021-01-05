#ifndef STATISTIC_H_
#define STATISTIC_H_
#include <vector>

class Statistic
{
public:
  Statistic();
  void recordData(bool x);
  int getData(const int &);
  int getDataSize();
  int numberOfWin();
  int numberOfLose();

private:
   std::vector<int> stat;
};

#endif /* STATISTIC_H_ */
