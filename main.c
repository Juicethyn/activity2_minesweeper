#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// GOAL FOR THIS PROGRAM
// USER HAVE 3 LIVES AND ONCE IT GETS 0 = GAME OVER




void difficulty();
void easydiff();
void normaldiff();
void harddiff();
void init_board();
void place_bombs();
void reveal_cell();
void print_board();
void get_adjacent_cells();
void count_adjacent_mines();


// Mga bago na nilagay ko
void win();
void game_over();
void play_again();


int x,y;
int row = 10; 
int column = 10;
int diff;
int number_of_bombs = 5;
int bombs;
int player_life = 3;
int board[20][20];
int empty_board[20][20];
int final_board[20][20];




int main(){

    // printf("==============              =============\n");
    // printf("\\\\\\           \\____________/           ///\n");
    // printf(" \\\\\\                                  ///\n");
    // printf("  \\\\\\ >>> WELCOME TO MINESWEPEER <<< ///\n");
    // printf("  ///          ____________          \\\\\\\n");
    // printf(" ///          /            \\          \\\\\\ \n");
    // printf("==============              ==============\n");
    // difficulty();

    // play_again();

    // game_over();
    
    init_board();


    return 0;
}


void difficulty(){ // THIS FUNCTION FOCUSES ON WHAT KIND OF DIFFICULTY YOU WANT TO PLAY
    diff = 0;

    while((diff != 1) && (diff !=2) && (diff != 3)){
        printf("     >>> SELECT YOUR DIFFICULTY <<<\n");
        printf("       \\\\======================//\n");
        printf("       ||  (1) EASY [8x8]     ||\n");
        printf("       |]=====================[|\n");
        printf("       ||  (2) NORMAL [12x12] ||\n");
        printf("       |]=====================[|\n");
        printf("       ||  (3) HARD [20x20]   ||\n");
        printf("       //=====================\\\\\n");
        printf("Enter a number: ");
        scanf("%d", &diff);
        
        if( (diff != 1) && (diff !=2) && (diff != 3)){
            printf("Invalid Number, Please only choose from 1-3\n");
        }
    }

    if (diff == 1){
        easydiff();
    }
    else if (diff == 2){
        normaldiff();
    }
    else if (diff == 3){
        harddiff();
    }

}

void easydiff(){
    int row = 8;
    int column = 8;
    int number_of_bombs = 10;
    
    init_board();
}

void normaldiff(){
    int row = 12;
    int column = 12;
    
    printf("Size of Row: %d\n", row);
    printf("Size of Column: %d", column);

}

void harddiff(){
    int row = 20;
    int column = 20;
    
    printf("Size of Row: %d\n", row);
    printf("Size of Column: %d", column);

}


void init_board(){

    int i;
    int j;

    for(i=0; i < row; i++){
        for(j=0; j < column; j++){
            board[i][j] = 0;
        }
    }

    place_bombs();
    print_board();
}

void place_bombs(){ // A Function to randomly place the bombs on the board
    
    srand(time(0));

    int count;

    while (count < number_of_bombs){
        int i = rand() % row;
        int j = rand() % column;

        if (board[i][j] == 0){
            board[i][j] = -1;
            count++;
        }
    }

}

void print_board(){ // Function to print the current board
    int i;
    int j;

    printf("\n");
    
    for (i = 0; i < row; i++){
        printf("%d", i+1);
    }
    printf("\n");
    for (i = 0; i < column; i++){
        printf("|%2d| ", i+1);
        printf("%1s", "||");
        for (j = 0; j < column; j++){
            if (board[i][j] >= 0){
                printf(" ");
            }
            printf("%d ", board[i][j]);
        }
        printf("||\n");
    }

    printf("\n");
}


void reveal_cell(){

}

void get_adjacent_cells(){

}

void count_adjacent_mines(){

}


void win(){
    // Wala na muna need ko code ni aubrey

}


void game_over(){
    if (player_life == 0){
        printf("=================\n");
        printf("\\\\  GAME OVER  //\n");
        printf("//  YOU LOSE!  \\\\\n");
        printf("=================\n");
        play_again();
    }
    else{
        printf("THANK YOU FOR PLAYING");
    }

}

void play_again(){
    char option;

    printf("Do you want to play again? (Y/N): ");
    scanf("%c", &option);

    if ((option == 'Y') || (option == 'y')){
        player_life = 3;
        difficulty();
    }
    else if ((option == 'N') || (option == 'n')){
        player_life = 3;
        game_over();
    }
}
