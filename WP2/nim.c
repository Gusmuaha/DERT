/*
 *  File    : nim.c
 *  Program : Nim game
 *  Author  : Hassan Mualla && Hannah Maltkvist && Carl Nihlmar
 *  This is task 8 of WP2 of Development of Embedded Real-Time Systems 34195
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define MAX_COINS 13
const int HUMAN = 0;
const int COMPUTER = 1;
/* ------------- IO --------------- */
/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );
/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in:
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/
/*
 * computer_choice
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);
/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );
/* --------------------- Utilities -------------*/
void clear_stdin();
/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
  int pile = MAX_COINS,             /* This is how many coins we have */
    player,             /* Who is playing? */
    n_coins;                  /* Number of coins taken */
  srand( time(0) );           /* Setup random */
  printf("Valkommen till NIM by Hassan och Hannah");

  pile = MAX_COINS;           /* Set start values (= init) */
  player = HUMAN;
  /*
   *  Program main loop
   */
  while( true ) {
    printf("Det ligger %d  mynt i h gen\n", pile );

    if( player == HUMAN ){
      n_coins = human_choice(pile);
    }else{
      n_coins = computer_choice(pile);
      printf("- Jag tog %d\n", n_coins);
    }
    pile -= n_coins;
    player = toggle( player );
    if( pile <= 1 ){
      break;
    }
  }
  /*
   * end main loop
   */
  write_winner( player );
  printf("Avslutat\n");
  return 0;
}
/******************************************************
 *
 *  DEFINITIONS
 *
 ******************************************************/
void clear_stdin()
{
  while( getchar() != '\n' ){
    ;
  }
}
int human_choice(int pile)
{
    printf("%d\n", pile);
    if (pile < 2){
            printf("Take a coin! from the pile! \nThe pile contains %d coin! \nenter 1 to pick up. \n", pile);
            return 1;
        } else if (pile < 3) {
            printf("Choose number of coins to pick!\n1 coin: enter 1\n2 coins: enter 2\n\nNumber of coins left in the pile is %d\n", pile);
            int coinsPicked;
            scanf("you have entered: %d\n", coinsPicked);
            return coinsPicked;
        }else {
            printf("Choose number of coins to pick!\n1 coin: enter 1\n2 coins: enter 2\n3 coins: enter 3\n\nNumber of coins left in the pile is %d\n", pile);
            int coinsPicked;
            scanf("%d", &coinsPicked);
            return (int)coinsPicked;
        }
}
int computer_choice(int pile){
    if (pile <= 5) {
        if (pile == 4) {
            return 3;
        } else if ( pile == 3) {
            return 2;
        } else {
            return 1;
        }
    } else {
        return rand()%2 + 1;
    }
}

void write_winner(int player ){
    if ( player == HUMAN ) {
        printf("GAME OVER\n");
    } else {
        printf("YOU WON\n");
    }
}

int play_again(){
    char choice;
    scanf("Do you want to play again?\nAnswer with n or N if you don't want to,\notherwise click any keyboard button to play again!", &choice);
    if (choice == "n" || choice == "N"){
        return 0;
    } else {
        return 1;
    }
}

int toggle( int player ){
    if (player == HUMAN){
        return COMPUTER;
    } else {
        return HUMAN;
    }
}

