/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int ChessBoard[8][8];
int XPosses[65];
int YPosses[65];
int MoveTypes[65];
int currentState = 1;
#define CHESSBOARD_SIZE     8

void MoveCheckHorse(int x, int y);
void CheckChessBoard();

void MoveCheckHorse(int x, int y)
{

    int ini_x = x;
    int ini_y = y;
    
    ChessBoard[x][y] = currentState;
    XPosses[currentState] = x;
    YPosses[currentState] = y;
    
    while (1)
    {
	if (currentState < 35)
        	printf("currentState = %d, x = %d , y = %d\n", currentState, x, y);
        
        if(x + 2 < CHESSBOARD_SIZE && y - 1 >= 0 && ChessBoard[x + 2][y - 1] == 0 && MoveTypes[currentState] < 1)
        {
            // Pos 1
            
            //printf("Pos1\n");
            
            MoveTypes[currentState] = 1;
            
            x += 2;
            y -= 1;
            
        }
        else if(x + 2 < CHESSBOARD_SIZE && y + 1 < CHESSBOARD_SIZE && ChessBoard[x + 2][y + 1] == 0 && MoveTypes[currentState] < 2)
        {
            // Pos 2
            //printf("Pos1\n");
            MoveTypes[currentState] = 2;
            
            x += 2;
            y += 1;
            
        }
        else if(x + 1 < CHESSBOARD_SIZE && y + 2 < CHESSBOARD_SIZE && ChessBoard[x + 1][y + 2] == 0 && MoveTypes[currentState] < 3)
        {
            // Pos 3
            //printf("Pos1\n");
            MoveTypes[currentState] = 3;
            
            x += 1;
            y += 2;
            
        }
        else if(x - 1 >= 0 && y + 2 < CHESSBOARD_SIZE && ChessBoard[x - 1][y + 2] == 0 && MoveTypes[currentState] < 4)
        {
            // Pos 4
            //printf("Pos1\n");
            MoveTypes[currentState] = 4;
            
            x -= 1;
            y += 2;
            
        }
        else if(x - 2 >= 0 && y + 1 < CHESSBOARD_SIZE && ChessBoard[x - 2][y + 1] == 0 && MoveTypes[currentState] < 5)
        {
            // Pos 5
            //printf("Pos1\n");
            MoveTypes[currentState] = 5;
            
            x -= 2;
            y += 1;
            
        }
        else if(x - 2 >= 0 && y - 1 >= 0 && ChessBoard[x - 2][y - 1] == 0 && MoveTypes[currentState] < 6)
        {
            // Pos 6
            //printf("Pos1\n");
            MoveTypes[currentState] = 6;
            
            x -= 2;
            y -= 1;
            
        }
        else if(x - 1 >= 0 && y - 2 >= 0 && ChessBoard[x - 1][y - 2] == 0 && MoveTypes[currentState] < 7)
        {
            // Pos 7
            //printf("Pos1\n");
            MoveTypes[currentState] = 7;
            
            x -= 1;
            y -= 2;
            
        }
        else if(x + 1 < CHESSBOARD_SIZE && y - 2 >= 0 && ChessBoard[x + 1][y - 2] == 0 && MoveTypes[currentState] < 8)
        {
            // Pos 8
            //printf("Pos1\n");
            MoveTypes[currentState] = 8;
            
            x += 1;
            y -= 2;
            
        }
        else
        {
            
            if(currentState == CHESSBOARD_SIZE * CHESSBOARD_SIZE || (x == ini_x && y == ini_y))
            {
                break;
            }
            else
            {
                MoveTypes[currentState] = 0;
                currentState--; 
                ChessBoard[x][y] = 0;
                x = XPosses[currentState];
                y = YPosses[currentState];   
            }
            
            continue;
        }
        
        currentState++;
        XPosses[currentState] = x;
        YPosses[currentState] = y;
        ChessBoard[x][y] = currentState;
    }
    
    // while loop end
    
    CheckChessBoard();
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
            printf("%-4d ", ChessBoard[j][i]);
        }   
    }
    printf("\n");
}

int main()
{
    MoveCheckHorse(0, 0);
    
    return 0;
}


