/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <unistd.h>

int ChessBoard[8][8];
int currentState = 1;
#define CHESSBOARD_SIZE     8

void MoveCheckHorse(int x, int y);
void CheckChessBoard();

void MoveCheckHorse(int x, int y)
{
    
//    printf("currentState = %d\n", currentState);
//    printf("x = %d, y = %d\n", x ,y);

    if(x + 2 < CHESSBOARD_SIZE && y - 1 >= 0 && ChessBoard[x + 2][y - 1] == 0)
    {
        // Pos 1
        
        
        currentState++;
        ChessBoard[x + 2][y - 1] = currentState;
        MoveCheckHorse(x + 2, y - 1);   
        ChessBoard[x + 2][y - 1] = 0;
        currentState--;
    }
    if(x + 2 < CHESSBOARD_SIZE && y + 1 < CHESSBOARD_SIZE && ChessBoard[x + 2][y + 1] == 0)
    {
        // Pos 2
        //printf("Pos1\n");
        
        currentState++;
        ChessBoard[x + 2][y + 1] = currentState;
        MoveCheckHorse(x + 2,y + 1);   
        ChessBoard[x + 2][y + 1] = 0;
        currentState--;
    }
    if(x + 1 < CHESSBOARD_SIZE && y + 2 < CHESSBOARD_SIZE && ChessBoard[x + 1][y + 2] == 0)
    {
        // Pos 3
        //printf("Pos1\n");
        
        currentState++;
        ChessBoard[x + 1][y + 2] = currentState;
        MoveCheckHorse(x + 1, y + 2);   
        ChessBoard[x + 1][y + 2] = 0;
        currentState--;
    }

    if(x - 1 >= 0 && y + 2 < CHESSBOARD_SIZE && ChessBoard[x - 1][y + 2] == 0)
    {
        // Pos 4
        //printf("Pos1\n");
        
        currentState++;
        ChessBoard[x - 1][y + 2] = currentState;
        MoveCheckHorse(x - 1, y + 2);   
        ChessBoard[x - 1][y + 2] = 0;
        currentState--;
    }
    if(x - 2 >= 0 && y + 1 < CHESSBOARD_SIZE && ChessBoard[x - 2][y + 1] == 0)
    {
        // Pos 5
        //printf("Pos1\n");
        
        currentState++;
        ChessBoard[x - 2][y + 1] = currentState;
        MoveCheckHorse(x - 2, y + 1);   
        ChessBoard[x - 2][y + 1] = 0;
        currentState--;
    }
    if(x - 2 >= 0 && y - 1 >= 0 && ChessBoard[x - 2][y - 1] == 0)
    {
        // Pos 6
        //printf("Pos1\n");
        
        currentState++;
        ChessBoard[x - 2][y - 1] = currentState;
        MoveCheckHorse(x - 2, y - 1);   
        ChessBoard[x - 2][y - 1] = 0;
        currentState--;
    }
    if(x - 1 >= 0 && y - 2 >= 0 && ChessBoard[x - 1][y - 2] == 0)
    {
        // Pos 7
        //printf("Pos1\n");
        
        currentState++;
        ChessBoard[x - 1][y - 2] = currentState;
        MoveCheckHorse(x - 1, y - 2);   
        ChessBoard[x - 1][y - 2] = 0;
        currentState--;
    }
    if(x + 1 < CHESSBOARD_SIZE && y - 2 >= 0 && ChessBoard[x + 1][y - 2] == 0)
    {
        // Pos 8
        //printf("Pos1\n");
        
        currentState++;
        ChessBoard[x + 1][y - 2] = currentState;
        MoveCheckHorse(x + 1, y - 2);   
        ChessBoard[x + 1][y - 2] = 0;
        currentState--;
    }
	if(currentState == CHESSBOARD_SIZE * CHESSBOARD_SIZE)
	{
        	CheckChessBoard();
	}
}

void CheckChessBoard()
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < CHESSBOARD_SIZE; i++)
    {
        printf("\n");
        
         for (j = 0; j < CHESSBOARD_SIZE; j++)
        {
            printf("%-2d ", ChessBoard[j][i]);
        }   
    }
    printf("\n");
}

int main()
{
    ChessBoard[0][0] = currentState;    
    MoveCheckHorse(0, 0);
    return 0;
}



