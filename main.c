#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



void difficulty();
void easy();
void normal();
void hard();
void generate_board();
void reveal_cell();
void print_board();
void get_adjacent_cells();
void count_adjacent_mines();
void play_game();


int x,y;
int row, column;
int diff;
int number_of_mines = 0;
int mines = 0;




int main(){

    printf("Welcome to Minesweeper\n");
    difficulty();
    printf("HEHEHEHEHEHE");
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
        printf("This is number 1");
    }
    else if (diff == 2){
        printf("This is number 2");
    }
    else if (diff == 3){
        printf("This is number 3");
    }

}

void easy(){


}

void normal(){


}

void hard(){


}





void generate_board(){
    
}


void reveal_cell(){


}

void print_board(){

}

void get_adjacent_cells(){

}

void count_adjacent_mines(){

}

void play_game(){


}