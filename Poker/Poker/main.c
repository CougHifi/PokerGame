#include "Poker.h"
#include "Struct.h"
//I was helped by Jeffory Fonda the tutor.
/*My father also helped out a ton on my program.*/
/*I have looked onto stack overflow website to figure out possible ways to work on the code.*/
/*programming simplified to figure out bubble sort as well, As well as some C book Called "Learn C the Hard Way" by Zed A. Shaw
that I bought to discribe and go into more detail about bubble sort.*/
/*These */
void menu();
void shuffle(int wDeck[][13]);
int deal(const int wDeck[][13], const char *wFace[], const char *wSuit[],struct Hand *player, struct Hand *dealer);
int discard(const int wDeck[][13], const char *wFace[], const char *wSuit[], int card, struct Hand *player, struct Hand *dealer);
void display_hands(const int wDeck[][13], const char *wFace[], const char *wSuit[], struct Hand *player, struct Hand *dealer);
void sorting_hand(void *pair, void *two_pairs, void *three_of_a_kind, void *four_of_a_kind, void *flush, struct Hand *player, struct Hand *dealer);


int main(void)
{
	//struct Hand player;
	//struct Hand dealer;
	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };
	struct Hand player;
	struct Hand dealer;
	int count = 0;
	int card = 0;

	srand((unsigned)time(NULL)); /* seed random-number generator */
	menu();
	shuffle(deck);
	card = deal(deck, face, suit, &player, &dealer);
	discard(deck, face, suit, card, &player, &dealer);
	display_hands(deck, face, suit, &player, &dealer);
	//sorting_hand(pair, two_pairs, three_of_a_kind, four_of_a_kind, flush, &player, &dealer);
		
	return 0;
}
