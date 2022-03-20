#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    int num = 10;
    
    char output[1000];
    int val = 0;
    int reminder = 0;
    int len = 1000 - 1;
    
    int i = 0;
    int j = 0;
    
    for(j = 1000 - 1; j >= 0; j--)
    {
        output[j] = '0';
    }
       
    output[1000 - 1] = '1';
        
    for(i = 2; i <= num; i++)
    {
        for(j = 1000 - 1; j >= 0; j--)
        {
            val = (i * (output[j] - '0')) + reminder;
            
            if(val == 0 && j <= len) 
            {
                len = j;
                break;
            }
            
            output[j] = (val % 10) + '0';
            reminder = val / 10;
        }
    }
    
    int x = 0;
    
    for(x = len + 1; x < 1000; x++)
    {
        printf("%c", output[x]);
    }
    
    return 0;
}
