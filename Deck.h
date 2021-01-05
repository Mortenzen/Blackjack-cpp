#ifndef Deck_H_
#define Deck_H_
#include "Card.h"
#include "CardStack.h"

static const std::size_t deckSize = 52;

class Deck
{
public:
  Deck();
  void printDeck();
  void shuffleCards();
  Card dealACard();
  void resetDeck();

private:
  CardStack<Card> deck;
  int numberOfCardsInTheDeck;
};

#endif /* DECK_H_ */
