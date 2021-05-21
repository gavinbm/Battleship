#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 5
#define MAXARGS 2

struct boat_t {
    int x_pos;
    int y_pos;
};

typedef struct boat_t boat_t;

void board_init(int cols, int rows);
void board_free(int rows);
void board_print(int cols, int rows);
int comp_move(boat_t *comp, int cols, int rows);
void comp_place(boat_t *comp, int cols, int rows);
void user_place(boat_t *player, int arg[], int cols, int rows);