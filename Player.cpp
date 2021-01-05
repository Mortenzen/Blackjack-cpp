#include <iostream>
#include "Player.h"

Player::Player()
{
  numOfCards =0;
}

void Player::putInHand(const Card &card)
{
  playerHand[numOfCards]= card;
  numOfCards++;
}

int Player::readHandValue()
{
  int value = 0;
  for(int i=0; i < numOfCards; i++)
  {
    playerHand[i].print();
    value = value + playerHand[i].cardValueBJ();
  }
  return value;
}

Card Player::readHandByNumber(const int &x)
{
  return playerHand[x];
}

void Player::resetPlayer()
{
  numOfCards = 0;
}

int Player::numOfCardsInHand()
{
  return numOfCards;
}
