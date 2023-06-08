#include "Poker.h"
#include "Struct.h"
/*I was helped by my Father with the majority of the program. We got stuck on the redrawing a card function it keeps causing the game to crash to desktop.*/
char Instructions, Play_The_Game,contributions, quit;
int choice = 0;
void menu()
{
	printf("Poker Game\n\n");
	printf("Created by Cougar Fischer\n");
	printf("1. Instructions\n");
	printf("2. Play the game\n");
	printf("3. People and websites that has helped me understand how to get this program to work\n");
	printf("4. Quit\n");
	scanf_s("%d", &choice);

	switch (choice)
	{
	case 1: 
		printf("There are five cards that are dealt to each player.\n");
		printf("Each player may then draw 0 - 4 cards to try to better his or her hand\n");
		printf("The goal is for each player to get the best hand to win\n");
		printf("these hands are listed below in order from least to best:\n");
		printf("no pair high card only.\n");
		printf("One Pair.\n");
		printf("Two Pair.\n");
		printf("Three of a kind\n");
		printf("Four of a kind.\n");
		printf("And a Straight\n");
		printf("A Flush\n\n");

		exit(0);
	case 2: 
		break;
	case 3:
		printf("Contributions:\n");
		printf("Contributions to the code:\n");
		printf("My Father\n");
		printf("Jeffory Fonda Tutor\n");
		printf("Stack Overflow\n\n");
		printf("To figure out bubble sort I used a book called Learn C the Hard Way by Zed A. Shaw that I bought at Barns, and Nobles.\n");
		printf("to discribe and go into more detail about bubble sort.\n");
		printf("Thanks to the teacher Mr. O'Fallon for taking the time to help me\n\n");
		printf("Thanks to my friend Jacob for helping me to teach me how the game works and how to get some of the cards to work!\n");
		printf("And Last but not least Thanks to the TA's mainly Austin for helping me out at his office hours I really appreciate it!\n");

		exit(0);
	case 4: 
		exit(0);
	}
}



/* shuffle cards in deck */
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
/*This one works as well with dealing the cards.*/
int deal(const int wDeck[][13], const char *wFace[], const char *wSuit[],struct Hand *player, struct Hand *dealer)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int i = 0;
	
					/* deal each of 10 cards */
	for (card = 1; card <= 10; card++) //you can modify this as a count
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					/*This is player 1s Hand*/
					if (card == 1)
					{
						player->row[1] = row;
						player->col[1] = column;
						//printf("player card 1 = %5s of %-8s%c\n", wFace[player.col[1]], wSuit[player.row[1]]);
					}
						/*This is the dealer's hand*/
					else if (card == 2)
					{
						dealer->row[1] = row;
						dealer->col[1] = column;
						//printf("dealer card 1 = %5s of %-8s%c\n", wFace[dealer.col[1]], wSuit[dealer.row[1]]);
					}
					else if (card == 3)
					{
						player->row[2] = row;
						player->col[2] = column;
						//printf("player card 2 = %5s of %-8s%c\n", wFace[player.col[2]], wSuit[player.row[2]]);
					}
					else if (card == 4)
					{
						dealer->row[2] = row;
						dealer->col[2] = column;
						//printf("dealer card 2 = %5s of %-8s%c\n", wFace[dealer.col[2]], wSuit[dealer.row[2]]);
					}
					else if (card == 5)
					{
						player->row[3] = row;
						player->col[3] = column;
						//printf("player card 3 = %5s of %-8s%c\n", wFace[player.col[3]], wSuit[player.row[3]]);
					}
					else if (card == 6)
					{
						dealer->row[3] = row;
						dealer->col[3] = column;
						//printf("dealer card 3 = %5s of %-8s%c\n", wFace[dealer.col[3]], wSuit[dealer.row[3]]);
					}
					else if (card == 7)
					{
						player->row[4] = row;
						player->col[4] = column;
						//printf("player card 4 = %5s of %-8s%c\n", wFace[player.col[4]], wSuit[player.row[4]]);
					}
					else if (card == 8)
					{
						dealer->row[4] = row;
						dealer->col[4] = column;
						//printf("dealer card 4 = %5s of %-8s%c\n", wFace[dealer.col[4]], wSuit[dealer.row[4]]);
					}
					else if (card == 9)
					{
						player->row[5] = row;
						player->col[5] = column;
						//printf("player card 5 = %5s of %-8s%c\n", wFace[player.col[5]], wSuit[player.row[5]]);
					}
					else if (card == 10)
					{
						dealer->row[5] = row;
						dealer->col[5] = column;
						//printf("dealer card 5 = %5s of %-8s%c\n", wFace[dealer.col[5]], wSuit[dealer.row[5]]);
					}				
				}
			}
		}//the row corrisponds to the suit the column corrisponds to the face.
	}
	printf("Player 1's Hand\n");
	printf("player card 1 = %5s of %-8s%c\n", wFace[player->col[1]], wSuit[player->row[1]], NULL);
	printf("player card 2 = %5s of %-8s%c\n", wFace[player->col[2]], wSuit[player->row[2]], NULL);
	printf("player card 3 = %5s of %-8s%c\n", wFace[player->col[3]], wSuit[player->row[3]], NULL);
	printf("player card 4 = %5s of %-8s%c\n", wFace[player->col[4]], wSuit[player->row[4]], NULL);
	printf("player card 5 = %5s of %-8s%c\n\n\n", wFace[player->col[5]], wSuit[player->row[5]], NULL);
	printf("Dealer's hand\n");
	printf("dealer card 1 = %5s of %-8s%c\n", wFace[dealer->col[1]], wSuit[dealer->row[1]], NULL);
	printf("dealer card 2 = %5s of %-8s%c\n", wFace[dealer->col[2]], wSuit[dealer->row[2]], NULL);
	printf("dealer card 3 = %5s of %-8s%c\n", wFace[dealer->col[3]], wSuit[dealer->row[3]], NULL);
	printf("dealer card 4 = %5s of %-8s%c\n", wFace[dealer->col[4]], wSuit[dealer->row[4]], NULL);
	printf("dealer card 5 = %5s of %-8s%c\n", wFace[dealer->col[5]], wSuit[dealer->row[5]], NULL);
		
	printf("card = %d\n", card);
	printf("deal complete\n");
	return card;
}
/*This is the discard function the discard function does not want to work at all. If I change anything it causes the program to crash.*/
int discard(const int wDeck[][13], const char *wFace[], const char *wSuit[], int card, struct Hand *player, struct Hand *dealer)
{
	int cardnumber = -1;
	int row = 0;
	int column = 0;
	int i = 0;


	for (i = 0; i < 4 && cardnumber != 0; i++)
	{
		printf("Which card would you like to discard\n");
		printf("enter 0 for none - enter 1-5 for the card you like to discard\n");
		scanf("%d", &cardnumber);
		
		if (cardnumber != 0)
		{
			/* loop through rows of wDeck */
			for (row = 0; row <= 3; row++)
			{
				/* loop through columns of wDeck for current row  for the next card*/
				for (column = 0; column <= 12; column++)
				{
					/* if slot contains current card, display card */
					if (wDeck[row][column] == card)
					{
						player->row[cardnumber] = row;
						player->col[cardnumber] = column;
						
						printf("card = %d\n", card);
						printf("Player card %d\n", cardnumber);
						card = card++;
					}
					else if ((cardnumber >= 6 || cardnumber <= 0))
						printf("You enterd an invalid input enter in a number between 1-5\n"), cardnumber;
					//printf("enter in a number between 1-5\n", cardnumber);
								
				}
			}
		}
	}
	return (card);
	/*else if (!(column > 6 && row >6))
	printf("You enterd an invalid input enter in a number between 1-5\n"), cardnumber;
	printf("enter in a number between 1-5\n", cardnumber);
	break;*/
}
/*This is my display hand function. This function works properly.*/
void display_hands(const int wDeck[][13], const char *wFace[], const char *wSuit[], struct Hand *player, struct Hand *dealer)
{
	
	printf("Player 1's Hand\n");
	printf("player card 1 = %5s of %-8s%c\n", wFace[player->col[1]], wSuit[player->row[1]], 0);
	printf("player card 2 = %5s of %-8s%c\n", wFace[player->col[2]], wSuit[player->row[2]], 0);
	printf("player card 3 = %5s of %-8s%c\n", wFace[player->col[3]], wSuit[player->row[3]], 0);
	printf("player card 4 = %5s of %-8s%c\n", wFace[player->col[4]], wSuit[player->row[4]], 0);
	printf("player card 5 = %5s of %-8s%c\n\n\n", wFace[player->col[5]], wSuit[player->row[5]], 0);
	printf("Dealer's hand\n");
	printf("dealer card 1 = %5s of %-8s%c\n", wFace[dealer->col[1]], wSuit[dealer->row[1]], 0);
	printf("dealer card 2 = %5s of %-8s%c\n", wFace[dealer->col[2]], wSuit[dealer->row[2]], 0);
	printf("dealer card 3 = %5s of %-8s%c\n", wFace[dealer->col[3]], wSuit[dealer->row[3]], 0);
	printf("dealer card 4 = %5s of %-8s%c\n", wFace[dealer->col[4]], wSuit[dealer->row[4]], 0);
	printf("dealer card 5 = %5s of %-8s%c\n", wFace[dealer->col[5]], wSuit[dealer->row[5]], 0);
}
/*This is the sorting hand function I am trying to sort the cards to see if you have a good hand using bubble sort.
*/
void sorting_hand(void *pair, void *two_pairs, void *three_of_a_kind, void *four_of_a_kind, void *flush, struct Hand *player, struct Hand *dealer)
{
	int i, j;
	int x[5] = { 1, 2, 3, 4, 5 };
	int rank[5] = { 0 };

	for (i = 0; i < 5; i++)
	{
		int curRank = 1;

		for (j = 0; j < i; j++)
		{
			if (x[i] > x[j])
			{
				curRank++;
			}
			else
			{
				rank[j]++;
			}
		}
		rank[i] = curRank;
	}

	for (i = 0; i < 5; i++) {
		printf("%ld %d\n", x[i], rank[i]);
	}
}
//	for (i = 0; pair < two_pairs || i = 2; i < three_of_a_kind)
	
		/*for (pair = 1; pair < 5;)
	{
		printf("Checking player 1's Hand\n");
		
	}
	printf("Checking dealer's Hand\n");
	return (0);
}*/
