#include <iostream>
#include "Card.h"

Card::Card(const std::string &face, const std::string &suit)
{
  this -> face = face;
  this -> suit = suit;
}

Card::Card(){} //SECOND INSTRUCTOR TO CREATE AN ARRAY

std::string Card::print()
{
  return(face + " of " + suit);
}

std::string Card::getFace()
{
  return face;
}
std::string Card::getSuit()
{
  return suit;
}

//VALUE FOR THE BLACKJACK GAME
int Card::cardValueBJ()
{
  int x=0;
  if (face == "Ace")   x = 1;
  if (face == "Two")  x =  2;
  if (face == "Three") x = 3;
  if (face == "Four") x =  4;
  if (face == "Five") x =  5;
  if (face == "Six")   x = 6;
  if (face == "Seven") x =  7;
  if (face == "Eight") x =  8;
  if (face == "Nine") x =  9;
  if (face == "Ten") x =  10;
  if (face == "Jack") x =  10;
  if (face == "Queen") x =  10;
  if (face == "King") x =  10;
  return x;
}

//VALUE FOR THE CARD GUESSING GAME
int Card::cardValue()
{
  int x=0;
  if (face == "Ace")   x = 1;
  if (face == "Two")  x =  2;
  if (face == "Three") x = 3;
  if (face == "Four") x =  4;
  if (face == "Five") x =  5;
  if (face == "Six")   x = 6;
  if (face == "Seven") x =  7;
  if (face == "Eight") x =  8;
  if (face == "Nine") x =  9;
  if (face == "Ten") x =  10;
  if (face == "Jack") x =  11;
  if (face == "Queen") x =  12;
  if (face == "King") x =  13;
  return x;
}
