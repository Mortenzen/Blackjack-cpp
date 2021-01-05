#include<iostream>
#include<stdexcept>
#include"CardGuessingGame.h"

using namespace std;

CardGuessingGame::CardGuessingGame(){}

//CARD GUESSING GAME AI
void CardGuessingGame::gameAi()
{

  cout<<"==========================================\n";
  cout<<"=== Welcome to the Card Guessing Game! ===\n";
  cout<<"==========================================\n"<<endl;

  bool gameon = true;
  string faces[] = { "Ace", "Two", "Three", "Four", "Five", "Six",
  "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

  while(gameon)
  {
    //================================================
    // GAME INIT
    //================================================
    cin.ignore(); //INPUT SETTING
    cin.clear();  //INPUT SETTING
    cin.sync();   //INPUT SETTING
    gameDeck.resetDeck();    //RESET DECK
    gameDeck.shuffleCards(); //SHUFFLE DECK
    bank.resetPlayer();      //PLAYER RESET
    bank.putInHand(gameDeck.dealACard()); //DEALING A CARD
    cout<<endl;

    cout<<"=============  Game started  =============\n"<<endl;
    cout<<" There is a card in the hand of the bank."<<endl;
    //cout<<"The card is "<<bank.readHandByNumber(0).print()<<endl;
    cout<<"   Please enter a card, for example \n   'Ten of Diamonds' or type quit..."<<endl;
    cout<<endl;
    int lenghtOfTheCardname = bank.readHandByNumber(0).print().size();
    bool tf = true;

    //================================================
    // GAME LOPP
    //================================================
    while(tf)
    {
      //cout<<"current CARD: "<<bank.readHandByNumber(0).print()<<endl;
      int value = 0;
      string inputCardName = "";
      char s[100];
      cin.getline(s,100);
      int i=0;

      //================================================
      // PROCESSIGN THE INPUT
      //================================================
      for (i = 0; i < lenghtOfTheCardname; i++)
      {
        inputCardName = inputCardName + s[i];
      }
      cout<<endl;cout<<endl;

      if(s[0]=='q' && s[1]=='u' && s[2]=='i' && s[3]=='t')
      {
        tf = 0;
      }

      //================================================
      // CHECKING IF THE FIRST TRY WAS SUCCESSFUL OR NOT
      //================================================
      if(inputCardName == bank.readHandByNumber(0).print())
      {
        cout<<"You won! Well done."<<endl;
        tf = false;
      }

      //================================================
      // LOADING THE FACES
      //================================================
      i=0;
      inputCardName = "";
      while( s[i] != ' ' && i!=5)
      {
        inputCardName = inputCardName + s[i];
        i++;
      }

      //================================================
      // CHECK FACES
      //================================================
      if(tf == true)
      {
        for(int j = 0; j < 13; j++)
        {
          int formatError=0;
          if(inputCardName == faces[j])
          {
            value = j+1;
            if(value == bank.readHandByNumber(0).cardValue())
            {
              cout<<"* The face is correct. "<<endl;
              formatError=1;
            }
            else if(value < bank.readHandByNumber(0).cardValue())
            {
              cout<<"* Try a bigger face. "<<endl;
            }
            else
            {
              cout<<"* Try a smaller face. "<<endl;
            }

            inputCardName = "";
            i=i+4;
            int temp = i;

            //================================================
            // LOADING THE SUITS
            //================================================
            while( s[i] != ' ' && i!= (temp + bank.readHandByNumber(0).getSuit().size()))
            {
              inputCardName = inputCardName + s[i];
              i++;
            }

            //================================================
            // CHECK SUITS
            //================================================
            if(inputCardName == bank.readHandByNumber(0).getSuit())
            {
              cout<<"* Correct suit."<<endl;
              if(formatError==1)
              {
                cout<<"* Although the suit and the face are correct, probably you have entered the card name incorrectly. Card format: 'FACES of SUITS'."<<endl;
              }
            }
            else
            {
              cout<<"* Incorrect suit."<<endl;
            }
          }
        }
      }
      if(tf == true)
      {
        cout<<"Please try again or type quit to [quit] current game.\n Your guess is: " <<endl;
      }
    }

    string d="";
    while(d != "n" && d != "y")
    {
      cout<<"Would you like to play again? [y]es / [n]o"<<endl;
      cin>>d;
    }

    if(d=="y"){gameon = true;}
    else if (d=="n"){gameon = false;}
  }

  cout<<endl;
  cout<<"Bye..."<<endl;
}
