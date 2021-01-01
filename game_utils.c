#include "deck_utils.h"

void moveCard(Card * d, int size, int source, int destination, Owner newOwner){

  if((source > size) || (destination > size)){
    return;
  }

  Card buff;
  buff = d[source];
  if(source > destination){
    for(int i = source - 1; i >= destination; i--){
      d[i + 1] = d[i];
    }
    d[destination] = buff;
  }else if(source < destination){
    for(int i = source + 1; i <= destination; i++){
      d[i - 1] = d[i];
    }
    d[destination] = buff;
  }
  d[destination].cardOwner = newOwner;
  return;
}

void beginGame(){
  //setup UNO Deck
  int numCards;
  Card * deck = createUNODeck(&numCards);

  shuffleDeck(deck, numCards);

  //distribute cards to each player
  for(int i = 0; i < 7; i++){
    moveCard(deck, numCards, i, i, PLAYER1);
  }for(int i = 7; i < 14; i++){
    moveCard(deck, numCards, i, i, PLAYER2);
  }



}
