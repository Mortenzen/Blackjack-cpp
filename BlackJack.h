#ifndef BLACKJACK_H_
#define BLACKJACK_H_
#include "Game.h"

class BlackJack: public Game{

public:
  BlackJack();
  virtual void gameAi() override;

private:
};

#endif
