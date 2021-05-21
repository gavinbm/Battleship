#include "game.h"

extern char **board;

// allocate the space for the board and fill in the spaces
void board_init(int cols, int rows) 
{
    // malloc the board matrix
    board = (char **)malloc(rows * sizeof(char*));
    printf("in init\n");
    // malloc each line in the board matrix
    for(int i = 0; i < rows; i++) {
        board[i] = (char *)malloc(cols * sizeof(char));
        for(int k = 0; k < cols; k++) {
            board[i][k] = 'O';
        }
    }
}

// clear the board and free the allocated memory
void board_free(int rows) 
{
    for(int i = 0; i < rows; i++) {
        free(board[i]);
    }

    free(board);
}

// print the board
void board_print(int cols, int rows) 
{
    // print the column markers along the top of the board
    printf("\n\t");
    for(int j = 0; j < rows; j++)
        printf("[%d]\t", j);
    
    // print the row markers down the side of the board and the board itself
    printf("\n");
    for(int i = 0; i < rows; i++) {
        printf("[%d]\t", i);
        for(int k = 0; k < cols; k++) {
            printf("%c\t", board[i][k]);
        }
        printf("\n");
    }
}

// computer picks a random empty space within the board and fires
int comp_move(boat_t *comp, int cols, int rows) 
{
    int x = rand() % cols;
    int y = rand() % rows;

    while(board[y][x] == 'M' || (comp->x_pos == x && comp->y_pos == y)) {
        x = rand() % cols;
        y = rand() % rows;
    }

    if(board[y][x] == 'P') {
        board[y][x] = 'X';
        return 1;
    } else {
        board[y][x] = 'M';
        return 0;
    }
}

// computer places their boat at the start of the game
void comp_place(boat_t *comp, int cols, int rows) 
{
    int x = rand() % cols;
    int y = rand() % rows;

    while(board[y][x] == 'P') {
        x = rand() % cols;
        y = rand() % rows;
    }

    comp->x_pos = x;
    comp->y_pos = y;
}

// let the user place their ship
void user_place(boat_t *player, int arg[], int cols, int rows) 
{
    // check for invalid input
    if(arg[0] > cols || arg[1] > rows || arg[0] < 0 || arg[1] < 0) {
        printf("Invalid input\n");
    } else {
        // place the ship
        player->x_pos = arg[1];
        player->y_pos = arg[0];
        board[arg[1]][arg[0]] = 'P';
    }
}

