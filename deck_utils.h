#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef enum{
  RED,
  YELLOW,
  BLUE,
  GREEN,
  NA
}Color;

typedef enum{
  NUMBER,
  ADD2,
  WILDADD4,
  WILD,
  SKIP,
  REVERSE
}CardType;

typedef enum{
  DECK = 0,
  DISCARD = 1,
  PLAYER1 = 2,
  PLAYER2 = 3
}Owner;

typedef struct{
  Owner cardOwner;
  Color color;
  CardType type;
  int number;
} Card;
/*
* returns card type as a string
*/
char * getCardType(CardType t);
/*
* returns card color as a string
*/
char * getColor(Color c);
/*
* returns card owner as a string
*/
char * getOwner(Owner o);
/*
* returns an array of cards, uninitilized
*/
Card * createCards(int numCards);
/*
* initilizes given card to properties set by given parameters
* if the paramater is set to NULL it is ignored
*/
void initializeCard(Card * c, Owner cardOwner, Color color, CardType type, int num);
/*
* creates a standard uno deck, allocates & initilizes cards itself
*/
Card * createUNODeck(int * size);
/*
* prints basic info for each card in a deck
*/
void printDeck(Card * deck, int size);
/*
* simulates the shuffling of an UNO
* deck by swaping random cards 500 times
*/
void shuffleDeck(Card * d, int size);
