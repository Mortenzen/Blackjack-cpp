#ifndef CARDGUESSINGGAME_H_
#define CARDGUESSINGGAME_H_
#include "Game.h"

class CardGuessingGame: public Game
{
public:
  CardGuessingGame();
  virtual void gameAi() override;

private:
};

#endif
