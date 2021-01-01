#include "deck_utils.h"

const char * getCardType(CardType t){
  switch(t){
    case NUMBER: return "Number";
    case ADD2: return "add2";
    case WILDADD4: return "Wild Card Add 4";
    case WILD: return "Wild Card";
    case SKIP: return "Skip";
    case REVERSE: return "Reverse";
    default: return "ERROR";
  }
}

const char * getColor(Color c){
  switch(c){
    case RED: return "Red";
    case YELLOW: return "Yellow";
    case BLUE: return "Blue";
    case GREEN: return "Green";
    case NA: return "N/A";
    default: return "ERROR";
  }
}

const char * getOwner(Owner o){
  switch(o){
    case DECK: return "deck";
    case PLAYER1: return "player 1";
    case PLAYER2: return "player 2";
    default: return "ERROR";
  }
}

Card * createCards(int numCards){
  Card * cards = (Card *) malloc(sizeof(Card) * numCards);
  return cards;
}

void setCard(Card * c, Owner cardOwner, Color color, CardType type, int num){
  c->cardOwner = cardOwner;
  c->color = color;
  c->type = type;
  c->number = num;
  return;
}

Card * createUNODeck(int * size){
  //create array of empty cards
  //there are 108 cards in an UNO game
  *size = 108;
  Card * deck = createCards(*size);
  //red numbered cards
  int cardNum = 0;
  setCard(&deck[cardNum], DECK, RED, NUMBER, 0);
  cardNum++;
  for(int i = 2; i <= 19; i++){
    setCard(&deck[cardNum], DECK, RED, NUMBER, i/2);
    cardNum++;
  }
  //green numbered cards
  setCard(&deck[cardNum], DECK, GREEN, NUMBER, 0);
  cardNum++;
  for(int i = 2; i <= 19; i++){
    setCard(&deck[cardNum], DECK, GREEN, NUMBER, i/2);
    cardNum++;
  }
  //yellow numbered cards
  setCard(&deck[cardNum], DECK, YELLOW, NUMBER, 0);
  cardNum++;
  for(int i = 2; i <= 19; i++){
    setCard(&deck[cardNum], DECK, YELLOW, NUMBER, i/2);
    cardNum++;
  }
  //blue numbered cards
  setCard(&deck[cardNum], DECK, BLUE, NUMBER, 0);
  cardNum++;
  for(int i = 2; i <= 19; i++){
    setCard(&deck[cardNum], DECK, BLUE, NUMBER, i/2);
    cardNum++;
  }

  //draw 2
  setCard(&deck[cardNum], DECK, RED, ADD2, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, RED, ADD2, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, GREEN, ADD2, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, GREEN, ADD2, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, YELLOW, ADD2, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, YELLOW, ADD2, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, BLUE, ADD2, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, BLUE, ADD2, -1);
  cardNum++;
  //reverse
  setCard(&deck[cardNum], DECK, RED, REVERSE, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, RED, REVERSE, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, GREEN, REVERSE, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, GREEN, REVERSE, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, YELLOW, REVERSE, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, YELLOW, REVERSE, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, BLUE, REVERSE, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, BLUE, REVERSE, -1);
  cardNum++;
  //skip
  setCard(&deck[cardNum], DECK, RED, SKIP, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, RED, SKIP, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, GREEN, SKIP, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, GREEN, SKIP, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, YELLOW, SKIP, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, YELLOW, SKIP, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, BLUE, SKIP, -1);
  cardNum++;
  setCard(&deck[cardNum], DECK, BLUE, SKIP, -1);
  cardNum++;

  for(int i = 0; i < 4; i++){
    setCard(&deck[cardNum], DECK, NA, WILD, -1);
    cardNum++;
  }
  for(int i = 0; i < 4; i++){
    setCard(&deck[cardNum], DECK, NA, WILDADD4, -1);
    cardNum++;
  }


  return deck;
}

void printDeck(Card * deck, int size){

  for(int i = 0; i < size; i++){
    printf("Owner: %s Type: %s Number: %d Color: %s\n", getOwner(deck[i].cardOwner), getCardType(deck[i].type), deck[i].number, getColor(deck[i].color));
  }
  return;
}

void shuffleDeck(Card * d, int size){

  Card buffer;

  //seed RNG
  srand(time(0));
  //swap 500 randomly selected cards to simulate shuffling
  for(int i = 0; i < 500; i++){
    //choose two random indexes
    int swap1 = rand() % size;
    int swap2 = rand() % size;
    //swap cards
    setCard(&buffer, d[swap1].cardOwner, d[swap1].color, d[swap1].type, d[swap1].number);
    setCard(&d[swap1], d[swap2].cardOwner, d[swap2].color, d[swap2].type, d[swap2].number);
    setCard(&d[swap2], buffer.cardOwner, buffer.color, buffer.type, buffer.number);
  }
  return;
}
