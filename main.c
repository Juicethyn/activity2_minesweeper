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
void generate_board();
void reveal_cell();
void print_board();
void get_adjacent_cells();
void count_adjacent_mines();


// Mga bago na nilagay ko
void win();
void game_over();
void play_again();


int x,y;
int row, column;
int diff;
int number_of_mines = 0;
int mines = 0;
// Update From me
int player_life = 3;





int main(){
    printf("==============              =============\n");
    printf("\\\\\\           \\____________/           ///\n");
    printf(" \\\\\\                                  ///\n");
    printf("  \\\\\\ >>> WELCOME TO MINESWEPEER <<< ///\n");
    printf("  ///          ____________          \\\\\\\n");
    printf(" ///          /            \\          \\\\\\ \n");
    printf("==============              ==============\n");
    // difficulty();

    play_again();
    
    


    return 0;
}


void difficulty(){
    diff = 0;

    while((diff != 1) && (diff !=2) && (diff != 3)){
        printf("Choose a difficulty of your choice\n");
        printf("(1) Easy\n");
        printf("(2) Normal\n");
        printf("(3) Hard\n");
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
    
    printf("Size of Row: %d\n", row);
    printf("Size of Column: %d", column);
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





void generate_board(){
    int row = 10;
    int column = 10;

    printf("Hello World");
    
}


void reveal_cell(){


}

void print_board(){

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
        printf("Game Over YOU LOST!");
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
        difficulty();
    }
    else if ((option == 'N') || (option == 'n')){
        game_over();
    }
}
