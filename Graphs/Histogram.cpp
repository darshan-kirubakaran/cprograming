#include <iostream>
#include <stdio.h>
#include<string.h>

using namespace std;

int main()
{
    int num[10] = {1, 5, 7, 3, 8, 8};
    
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    
    for(i = 9; i > 0; i--)
    {
        printf("%d |", i);
        
        for(x = 0; x < 6; x++)
        {
            printf("   ");
            
            if(num[x] >= i)
            {
                printf("|");    
            }
            else
            {
                printf(" ");
            }
        }
        
        printf("\n");
    }
    
    printf("0 |_________________________\n");

    return 0;
}
