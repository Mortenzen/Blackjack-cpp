#ifndef PLAYER_H_
#define PLAYER_H_
#include <array>
#include "Card.h"

class Player
{
public:
  Player();
  void putInHand(const Card &);
  int readHandValue();
  Card readHandByNumber(const int &);
  void resetPlayer();
  int numOfCardsInHand();

private:
  std::array<Card, 5> playerHand;
  int numOfCards;
};

#endif /* GAME_H_ */
