#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAXBOMB 10

COORD coord={0,0};

int bombx[MAXBOMB];
int bomby[MAXBOMB];

void gotoxy(int, int);
int randome(int, int);
void bombs(void);

int main(){

    srand(time(0));

    gotoxy(0,1); printf("Welcome to Minesweeper");
    bombs();

    for(int ctry=0; ctry<MAXBOMB; ctry++){
        gotoxy(5,6+ctry); printf("%i) x=%i v=%i", ctry+1, bombx[ctry], bomby[ctry]);
    }



    return 0;
}


void gotoxy(int x, int y){

    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    return;
}

int randome(int lower, int upper){

    return(rand() % (upper-lower+1)+lower);
}

void bombs(void){
    for(int ctr=0; ctr<MAXBOMB; ctr++){

        bombx[ctr]=randome(0,79);
        bomby[ctr]=randome(0,24);
    }
}


