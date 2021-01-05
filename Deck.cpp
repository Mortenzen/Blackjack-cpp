#include <iostream>
#include "Deck.h"
#include <time.h>

Deck::Deck()
{
  std::string faces[] = { "Ace", "Two", "Three", "Four", "Five", "Six",
  "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  std::string suits[] = {"Diamonds", "Spades", "Hearts", "Clubs"};

  for(int i = 0; i < 52; i++)
  {
    deck.push(Card(faces[i % 13],suits[i / 13]));
  }
}

void Deck::printDeck()
{
  for(int i=0; i< deck.getSize(); i++)
  {
    std::cout<<deck.printVector(i).print()<<" \n";
  }
}

void Deck::shuffleCards()
{
  deck.shuffle();
}

Card Deck::dealACard()
{
  return deck.deal();
}

void Deck::resetDeck()
{
  std::string faces[] = { "Ace", "Two", "Three", "Four", "Five", "Six",
  "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  std::string suits[] = {"Diamonds", "Spades", "Hearts", "Clubs"};
  int x = deck.getSize();
  for(int j=0; j < x ; j++)
  {
    deck.deal();
  }

  for(int i = 0; i < 52; i++)
  {
    deck.push(Card(faces[i % 13],suits[i / 13]));
  }
}
