#include <iostream>

using namespace std;

int CHESSBOARD_SIZE = 8;

int ChessBoard[8][8];
int Xoccupied[8];
int Yoccupied[8];
int Xpossess[8];
int Ypossess[8];
int Sumoccupied[8 * 2];
int Diffoccupied[8 * 2];
int currentState = 0;

void MoveQueen();
void CheckChessBoard();

int main()
{
    MoveQueen();
}

void MoveQueen()
{

    // spawn queens
    int x = 0;
    int y = 0;
    
    int temp_x = 0, tx = 0;
    int temp_y = 0, ty = 0;
    
    while (x < CHESSBOARD_SIZE)
    {
        while (y < CHESSBOARD_SIZE)
        {
            //check if spot valid
            if(ChessBoard[x][y] == 0 && Xoccupied[x] != 1 && Yoccupied[y] != 1 && Diffoccupied[CHESSBOARD_SIZE + (x - y)] != 1 && Sumoccupied[x + y] != 1)
            {
                ChessBoard[x][y] = 1;
                Xoccupied[x] = 1;
                Yoccupied[y] = 1;
                Diffoccupied[CHESSBOARD_SIZE + (x - y)] = 1;
                Sumoccupied[x + y] = 1;
                Xpossess[currentState] = x;
                Ypossess[currentState] = y;
                currentState++;
                
                CheckChessBoard();
                printf("%d\n", currentState);
                
                y = 0;
                break;
            }
            else
            {
                y++;
            }
        }
        
        // if did not spawn queen
        if(currentState >= 8)
        {
            printf("Done\n");
            CheckChessBoard();
            break;
        }
        else if(y == 0)
        {
            x++;
            continue;   
        }
        else
        {
            currentState--;
            tx = Xpossess[currentState];
            ty = Ypossess[currentState];
            
            ChessBoard[tx][ty] = 0;
            Xoccupied[tx] = 0;
            Yoccupied[ty] = 0;
            Xpossess[currentState] = 0;
            Ypossess[currentState] = 0;
            Diffoccupied[CHESSBOARD_SIZE + (tx - ty)] = 0;
            Sumoccupied[tx + ty] = 0;
            
            x = tx;
            y = ty + 1;
        }
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
            printf("%d ", ChessBoard[j][i]);
        }   
    }
    printf("\n");
}
