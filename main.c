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
void print_board();
void player_guess();
int cell_valid(int x, int y);
void reveal_cell();
int count_adjacent_bombs();


// Mga bago na nilagay ko
void win();
void game_over();
void play_again();


int x,y;
int row = 20; 
int column = 20;
int diff;
int number_of_bombs = 5;
int bombs;
int player_life = 3;
int board[25][25];
int empty_board[25][25];
int final_board[25][25];




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
            board[i][j] = '-';
        }
    }

    place_bombs();
    print_board();
}

void place_bombs(){ // A Function to randomly place the bombs on the board
    
    srand(time(0));

    int bombs;

    while (bombs < number_of_bombs){
        int i = rand() % row;
        int j = rand() % column;

        if (board[i][j] != '*'){ 
            board[i][j] = '-';
            bombs++;
        }
    }

}

void print_board(){ // Function to print the current board
    int i ;
    int j;

    // system("cls"); // Clears the output screen

    printf("\n        ");
    
    for (i = 0; i < row; i++){
        printf("%-3d", i+1);
    }

    printf("\n");
    
    for (i = 0; i < column; i++){ // This section prints the board of the game
        printf("|%2d| ", i+1);
        printf("%s", "||");
        for (j = 0; j < column; j++){
            if (board[i][j] >= 0){
                printf(" ");
            }
            if (board[i][j] == -1){
                printf(" ");
            }
            printf("%c ", board[i][j]);
        }
        printf("||\n");
    }
    printf("\n");
}


void player_guess(){
    //None for now
    printf("Enter row and column (x, y): ");
    scanf("%d %d", &x, &y);
    x--;
    y--;
}

int cell_valid(int x, int y){

    if (x < 0 || x >= row || y < 0 || y >= column){
        printf("\n Cell already revealed, enter another cell");
        player_guess();
    }
    
}

int count_adjacent_bombs(int x, int y){
    int bombs = 0;
    int i;
    int j;

    for (i=x-1; i <= x+1; i++){
        for (j = y-1; j <= y+1; j++){
            if (cell_valid(i,j) && board[i][j] == '-'){
                bombs++;
            }
        }
    }

}

void reveal_cell(int x, int y){

    if (board[x][y] == '*'){
        player_life--;
        print_board();
    }
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
