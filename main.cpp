#include <iostream>
#include <vector>
#include "Deck.h"
#include "Card.h"
#include "CardStack.h"
#include "Game.h"
#include "BlackJack.h"
#include"CardGuessingGame.h"
#include "Player.h"
#include "Statistic.h"

using namespace std;

string greatings()
{
  cout<<endl;cout<<endl;cout<<endl;cout<<endl;
  cout<<"==================================================\n";
  cout<<"==================================================\n";
  cout<<"=======  Welcome, please choose an option: =======\n";
  cout<<"==================================================\n";
  cout<<"==================================================\n";
  cout<<endl;cout<<endl;
  cout<<"* If you would like to play a Card Guessing Game please enter [1],\n";
  cout<<"* or if you would like to play BlackJack enter [2].\n";
  cout<<"* To quit program enter a [q].\n";
  cout<<endl;
  string x;
  cin>>x;cout<<endl;cout<<endl;
  while(x != "1" && x != "2" && x != "q")
  {

    cout<<endl;cout<<endl;cout<<endl;cout<<endl;
    cout<<"*** Incorrect input! Please enter 1, 2 or q ***\n";
    cout<<"* If you would like to play a Card Guessing Game please enter 1,\n";
    cout<<"* or if you would like to play BlackJack enter 2.\n";
    cout<<"* To quit program enter a q.\n";
    cout<<endl;
    cin>>x;cout<<endl;cout<<endl;
  }
  return x;
}

//MAIN
int main()
{
  CardGuessingGame game1;
  BlackJack game2;
  vector<Game *> games(2);
  games[0] = &game1;
  games[1] = &game2;
  string x = greatings();

  if( x == "1")
  {
    games[0]->gameAi();
  }
  if( x == "2")
  {
    games[1]->gameAi();
  }
  if( x == "q"){cout<<"Good bye ..."<<endl;}

  return 0;
}

/*
Deck x;
x.printDeck();
cout<<endl;
for(int i = 0; i < 42; i++)
{
x.dealACard();
}
cout<<endl;
x.printDeck();
x.shuffleCards();
cout<<endl;
x.printDeck();
x.shuffleCards();
cout<<endl;
x.printDeck();
cout<<endl;
x.dealACard();
x.dealACard();
x.dealACard();
x.printDeck();
x.shuffleCards();
cout<<endl;
x.printDeck();
cout<<endl;
cout<<endl;
x.resetDeck();
cout<<endl;
x.printDeck();
}
*/
