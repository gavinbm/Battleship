#include "game.h"

char **board;

int main(int argc, char *argv[]) 
{

    if(argc != 3) {
        printf("Please enter length and width of board\n");
        printf("[%d]\n", argc);
        exit(1);
    } else {
        boat_t *player = (boat_t *)malloc(sizeof(boat_t));
        boat_t *comp = (boat_t *)malloc(sizeof(boat_t));
        char buf[MAXLEN], *tok;
        int arg_no = 0, placed = 0, score = 0, arg[MAXARGS];
        int rows = atoi(argv[1]), cols = atoi(argv[2]);
        
        board_init(cols, rows);
        board_print(cols, rows);

        // let the player put their ship down on the board
        fprintf(stdout, "Place your ship: ");
        // game loop
        while(strcmp(fgets(buf, MAXLEN, stdin), "exit") != 0) {
            
            // tokenize the input and store into arg
            // tokenize the input and store into arg
            arg_no = 0;
            tok = strtok(buf, " ");
            while (tok != NULL && arg_no < MAXARGS) {
                arg[arg_no] = atoi(tok);
                arg_no++;
                tok = strtok(NULL, "\0");
            }

            if(placed == 0) {
                user_place(player, arg, cols, rows);
                comp_place(comp, cols, rows);
                placed = 1;
            } else {
                // check for invalid input
                if(arg[0] > cols || arg[1] > rows || arg[0] < 0 || arg[1] < 0) {
                    printf("Invalid input\n");
                    goto nextmove;
                } else {
                    // process the player's move
                    if(arg[0] == comp->y_pos && arg[1] == comp->x_pos) {
                        board[arg[1]][arg[0]] = 'X';
                        printf("You Win!\n");
                        board_print(cols, rows);
                        break;
                    } else {
                        board[arg[1]][arg[0]] = 'M';
                        printf("You Missed!\n");
                        if(comp_move(comp, cols, rows)) {
                            printf("Computer Win!\n");
                            board_print(cols, rows);
                            break;
                        } else {
                            printf("Computer Missed!\n");
                        }
                        goto nextmove;
                    }   
                }
            }

            // print the prompt and flush stdout
            nextmove:
                board_print(cols, rows);
                fprintf(stdout, "Fire on which coordinates?: ");
            fflush(stdout);
        }
        free(player);
        free(comp);
        board_free(rows);
    }
    return 0;
}