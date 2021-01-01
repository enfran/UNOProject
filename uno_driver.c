#include "deck_utils.h"
#include "game_utils.h"

int main(){
  int size;
  Card * deck = createUNODeck(&size);

  printDeck(deck, size);

  shuffleDeck(deck, size);

  printDeck(deck, size);

  return 0;
}
