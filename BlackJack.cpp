#include<iostream>
#include<stdexcept>
#include "BlackJack.h"
#include "Statistic.h"

using namespace std;

//CONSTRUCTOR
BlackJack::BlackJack(){}

//BLACKJACK AI
void BlackJack::gameAi()
{

  cout<<"==========================================\n";
  cout<<"===   Welcome to the Black Jack Game!  ===\n";
  cout<<"==========================================\n"<<endl;

  bool gameon = true;
  Statistic stats;
  int j;

  cout<<endl;
  cout<<"=============  Game started  =============\n"<<endl;
  cout<<"           The cards are dealed.            "<<endl;
  cout<<endl;

  //MAIN GAME WHILE
  while(gameon)
  {
    //================================================
    // GAME INIT
    //================================================
    cin.clear();                                //INPUT SETTINGS
    cin.sync();                                 //INPUT SETTINGS
    gameDeck.resetDeck();                       //NEW DECK
    gameDeck.shuffleCards();                    //SHUFFLE DECK
    //gameDeck.printDeck();                     //PRINT FOR TEST
    bank.resetPlayer();                         //RESETING PLAYERS
    player.resetPlayer();                       //RESETING PLAYERS
    bank.putInHand(gameDeck.dealACard());       //DEALING A CARD
    bank.putInHand(gameDeck.dealACard());       //DEALING A CARD
    player.putInHand(gameDeck.dealACard());     //DEALING A CARD
    player.putInHand(gameDeck.dealACard());     //DEALING A CARD
    bool outcome = true;
    string choice= "t";
    int j2=0;
    int j1=0;

    //================================================
    // PLAYER ROUND
    //================================================
    while(choice=="t")
    {

      //ASKING FOR CARD
      if(j1!=0)
      {
        player.putInHand(gameDeck.dealACard());//DEALING A CARD
      }
      cout<<"The cards in your hand are: "<<endl;

      //PRINTING CARDS IN HAND
      for(int i=0; i < player.numOfCardsInHand(); i++)
      {
        cout<<"|| "<<player.readHandByNumber(i).print()<<" ||"<<endl;
      }
      cout<<"The value of the cards is: "<<player.readHandValue()<<endl;

      //CHECKING FOR BUST
      if(player.readHandValue()> 21)
      {
        cout<<endl;
        cout<<"BUST!!!"<<endl;
        cout<<"Bad luck, the bank won."<<endl;
        outcome = false;
        break;
      }

      //HAND IS FULL
      if(j1==3)
      {
        cout<<"You have five cards in your hand. \n"<<endl;
        break;
      }

      //STICK OR TWIST
      choice=" ";
      while(choice != "t" && choice != "s" )
      {
        cout<<endl;
        cout<<"[s]tick or [t]wist?"<<endl;
        cin>>choice;
        cout<<endl;
      }
      j1++;
    }

    //================================================
    // BANK ROUND
    //================================================
    j2 = 0;
    while(j2 != 4 && outcome != false)
    {

      //ASKING FOR CARD IF ITS NOT THE FIRST BANK TURN
      if(j2!=0)
      {
        bank.putInHand(gameDeck.dealACard());
        cout<<"the bank draws a card... \n" <<endl;
      }

      cout<<"The cards in the hand of the bank are: "<<endl;
      for(int i=0; i < bank.numOfCardsInHand(); i++)
      {
        cout<<"|| "<<bank.readHandByNumber(i).print()<<" ||"<<endl;
      }

      cout<<"The value of the cards is: "<<bank.readHandValue()<<"\n"<<endl;

      //CHECKING FOR BANK BUST
      if(bank.readHandValue()> 21)
      {
        cout<<endl;
        cout<<"BUST!!!"<<endl;
        cout<<"Well done, you won!!! "<<endl;
        outcome = true;
        break;
      }

      //CHECKING FOR 21 FOR BOTH BANK AND PLAYER
      if(bank.readHandValue() == 21 && player.readHandValue() == 21)
      {
        cout<<endl;
        if(bank.numOfCardsInHand() > player.numOfCardsInHand())
        {
          cout<<"Bad luck, the bank won."<<endl;
          outcome = false;
          break;
        }
        else if(bank.numOfCardsInHand() > player.numOfCardsInHand())
        {
          cout<<"Well done, you won!!!"<<endl;
          outcome = true;
          break;
        }
        else if(bank.numOfCardsInHand() == player.numOfCardsInHand())
        {
          cout<<"Well done, you won!!!"<<endl;
          outcome = true;
          break;
        }
      }

      //CHECKING IF THE BANK WON
      if(bank.readHandValue() > player.readHandValue())
      {
        cout<< "Bad luck, the bank won.";
        outcome = false;
        break;
      }
      j2++;
      //IF BANK HAS 5 CARD AND THE VALUE IS SMALLER THAN PLAYER'S... PLAYER WINS
      if(j2 == 4 && bank.readHandValue() < player.readHandValue())
      {
        cout<<"Well done, you won!!!"<<endl;
        outcome = true;
        break;
      }
      //IF BANK HAS 5 CARD AND THE VALUE EQUALS TO PLAYER'S... PLAYER WINS
      if(j2 == 4 && bank.readHandValue() == player.readHandValue())
      {
        cout<<"Well done, you won!!!"<<endl;
        outcome = true;
        break;
      }
    }

    stats.recordData(outcome);

    //================================================
    // WANT TO PLAY AGAIN?
    //================================================
    string choice2= " ";
    while(choice2 != "n" && choice2 != "y" )
    {
      cout<<endl;
      cout<<"Would you like to play again? ([y]es/[n]o)"<<endl;
      cin>>choice2;
      cout<<endl;
    }
    if(choice2 == "y"){gameon=1;}
    if(choice2 == "n"){gameon=0;}
  }

  //================================================
  // STATISTICS
  //================================================
  cout<<"Rounds: "<<stats.getDataSize()<<endl;
  cout<<"Won   : "<<stats.numberOfWin()<<endl;
  cout<<"Lose  : "<<stats.numberOfLose()<<endl;
  cout<<"--"<<endl;

  for(int o = 0; o < stats.getDataSize(); o++)
  {
    if(stats.getData(o) == 1)
    {
      cout<<"Round "<<(o+1)<<": won. \n"<<endl;
    }
    if(stats.getData(o) == 0)
    {
      cout<<"Round "<<(o+1)<<": lost. \n"<<endl;
    }
  }

  // BYE
  cout<<"Thanks, bye!"<<endl;
}
