#ifndef GAME_H_
#define GAME_H_
#include "Deck.h"
#include "Player.h"

class Game
{
public:
  Game();
  virtual void gameAi() = 0;
  Deck gameDeck;
  Player player;
  Player bank;

private:
};

#endif /* GAME_H_ */
