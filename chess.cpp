#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 8
char board[8][8][8];
int playerOneBoard[16][4], playerTwoBoard[16][4];
//playerOneBoard[index][0] == piece kind
//playerOneBoard[index][1] == piece coordinat x
//playerOneBoard[index][2] == piece coordinat y
//playerOneBoard[index][3] == piece condition, playerOneBoard[index][0] == 0 this piece is alive, == 1 this piece is dead
// this function prepare board before player start game. This function give space to all value of main board and give first values of chess pieces to player's pieces's data.
void makeFirstBoard() {
    int i, j;
    for (i = 0; i < 16; i++) {
        if (i < 8) {
            playerOneBoard[i][0] = 1;
            playerOneBoard[i][1] = i;
            playerOneBoard[i][2] = 1;
            playerOneBoard[i][3] = 0;
            playerTwoBoard[i][0] = 1;
            playerTwoBoard[i][1] = i;
            playerTwoBoard[i][2] = 6;
            playerTwoBoard[i][3] = 0;
        } else {
            playerOneBoard[i][0] = 2;
            playerOneBoard[i][1] = i - 8;
            playerOneBoard[i][2] = 0;
            playerOneBoard[i][3] = 0;
            playerTwoBoard[i][0] = 2;
            playerTwoBoard[i][1] = i - 8;
            playerTwoBoard[i][2] = 7;
            playerTwoBoard[i][3] = 0;
        }
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            strcpy(board[i][j], " ");
        }
    }
}
// this function make changes to mainBoard when player make move. this one read player's piece's data and make loop and access all pieces value's then if that piece alive it change main board by that data
void makeChangeToBoard(int player1[16][4], int player2[16][4]) {
    int i;
    for (i = 0; i < 16; i++) {
        if (player1[i][3] == 0) {
            if (player1[i][0] == 1)
                strcpy(board[player1[i][2]][player1[i][1]], "♟︎");
            else
                strcpy(board[player1[i][2]][player1[i][1]], "♞");
        }
        if (player2[i][3] == 0) {
            if (player2[i][0] == 1)
                strcpy(board[player2[i][2]][player2[i][1]], "♙");
            else
                strcpy(board[player2[i][2]][player2[i][1]], "♘");
        }
    }
}
// this function make better made board style. data1 is the main board s data.
void DrawBoard(char data1[SIZE][SIZE][8]) {
    int i, iX, iY;
    for (i = 0; i < SIZE; i++) {
        if (i == 0)
            printf("    %c  ", 97 + i);
        else
            printf(" %c  ", 97 + i);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        if (i == 0)
            printf("  +---+");
        else
            printf("---+");
    }
    printf("\n");
    for (iY = 0; iY < SIZE; iY++) {
        for (iX = 0; iX < SIZE; iX++) {
            if (iX == 0)
                printf(" %d| %s |", iY + 1, data1[iY][iX]);
            else if (iX > 0 && iX < 20)
                printf(" %s |", data1[iY][iX]);
        }
        printf("\n");
        for (i = 0; i < SIZE; i++) {
            if (i == 0)
                printf("  +---+");
            else
                printf("---+");
        }
        printf("\n");
    }
}

// this function be used when player make move. this function's parameter is the player who is makeing move.
void makeMove(int playerData[16][4]){
    char char_piece, char_x;
    int x, y, piece;
    printf("coice your piece you will move.\nexample: p b 2 (p == pawn; b == x coordinat; 2 == y coordinat)");
    scanf("%c %c %d", &char_piece, &char_x, &y);

}

int main(){
    int i,j;
   //c_clrscr();
   makeFirstBoard();
   makeChangeToBoard(playerOneBoard, playerTwoBoard);
   DrawBoard(board);
//    while(1){
//         /makeMove();
//    }
}