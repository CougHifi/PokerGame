#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*These are my prototypes in my program*/
typedef int(*compare_cards)(const void *pair, const void *two_pairs, const void *three_of_a_kind, const void *four_of_a_kind, const void *flush);
int sort_cards(compare_cards);
int deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], struct Hand *player, struct Hand *dealer);
int discard(const int wDeck[][13], const char *wFace[], const char *wSuit[], int card, struct Hand *player, struct Hand *dealer);
void display_hands(const int wDeck[][13], const char *wFace[], const char *wSuit[], struct Hand *player, struct Hand *dealer);
void sorting_hand(const void *pair, const void *two_pairs, const void *three_of_a_kind, const void *four_of_a_kind, const void *flush, struct Hand *player, struct Hand *dealer);
