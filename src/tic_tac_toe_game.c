/**
 * AUTHOR: Khaled Badran
 * DATE:   01/09/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef char *String;
char play_field[3][3]; 
char player1 = 'x', player2 = 'o';
/**
 * the play_field variable should be defined globally,
 * so that we can access it from any function and update it.
*/

void print_field(){ // to print the game drid
    printf("  *X_O GAME*\n");
    printf("please choose the slot, where you want to play\n");
    for(int i = 0; i < 3;i++){
        for(int j=0; j < 3; j++){
            printf("|%c", play_field[i][j] = '_' );
        }
        printf("|\n");
    }
}

void print_game(int row, int column, char input){
    while (play_field[row][column] != '_'){ // if the cell is not empty
        printf("This is an invalid move.\n");
        printf("please choose the slot, where you want to play\n");
        scanf("%d %d", &row, & column);
    }

    for(int i = 0; i < 3;i++){
        for(int j=0; j < 3; j++){
            if (i == row && j == column){
                printf("|%c", play_field[i][j]= input);
            } else {
                printf("|%c", play_field[i][j] );
            }
        }
        printf("|\n");
    } 
}


bool game_over(){//checks wheather x or o wins: else draw. 
    int player;
    char input;
    for (int x = 1; x < 3; x++){//this loop is to alternate player's turn with the computer's turn.
        player = x % 2;
        if (player != 0) input = 'x';
        if (player == 0) input = 'o';
        //checks rows and columns
        for (int i = 0; i<3 ;i++){
            if(play_field[i][0]== input && play_field[i][1]== input && play_field[i][2]== input){
                //if a row is completely the same.
                printf("player%d wins (%c) :)\n",x , input);
                return true;
            }
            if(play_field[0][i] == input && play_field[1][i] == input && play_field[2][i]== input){
                //if a column is completely the same.
                printf("player%d wins (%c) :)\n",x , input);
                return true;
            }

        }
        //if any diagonal is completely filled with the same input.
        if(play_field[0][0]== input && play_field[1][1]==input && play_field[2][2]== input){
            printf("player%d wins (%c) :)\n",x , input);
            return true;
        }

        if(play_field[0][2]== input && play_field[1][1]== input && play_field[2][0]== input){
            printf("player%d wins (%c) :)\n",x , input);
            return true;
        } 
    }
    return false;   
}

void computer_turn(){
    srand(time(NULL));
    int range = 3;
    int row = (rand() % range); //the random numbers are [0:2].
    int col = (rand() % range);
    while (play_field[row][col] != '_'){
        row = (rand() % range);
        col = (rand() % range);
    }
    print_game(row, col, player2);
}

void game(){ 
    int row, column;
    print_field();
    printf("player1's turn (x)\n");
    for(int turns = 0 ; turns < 9; turns++ ){
        int player = turns % 2;

        switch (player){
            case 0: 
                scanf("%d %d",&row ,&column);
                print_game(row, column, player1);
                if (game_over()==true) return; // if anyone won, end the loop
                printf("player2's turn (o)\n");
                break;
            default:
                computer_turn();
                if (game_over()==true) return; // if anyone won, end the loop
                printf("player1's turn (x)\n");
                break;
        }
        if (game_over()==true) return;
    }
    printf("draw!! no one wins");
}

int main(){
    game();
    return 0;
}