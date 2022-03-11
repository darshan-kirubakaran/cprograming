#include <iostream>
#include <cstring>

char word[16] = "soccer";

void LoopLettersInWord(char word[10]);

int main()
{
    LoopLettersInWord(word);
}

void LoopLettersInWord(char word[])
{
    int i = 0;
    int j = 0;
    int a = 0;
    int c = 1;
    int start = 1;
    int end = 1;
    int temp_num;
    
    bool canprint = false;
    int len = strlen(word);
    char temp_word[len];
    char temp_letter[1];
    end = len;
    
    for (i = 2; i <= len; i++) {
        start = (start * 10) + i;
        end = (end * 10) + (len - i + 1);
    }
    printf("start = %d end = %d\n", start, end);
    
    for(i = start; i <= end; i++)
    {
        sprintf(temp_word, "%d", i);
    
        for(j = 1; j <= len; j++)
        {
            for(a = 0; a < len; a++)
            {
                if(temp_word[a] != j + 48)
                {
                    canprint = false;
                    continue;
                }
                else
                {
                    canprint = true;
                    break;
                }
            }
            
            if (canprint == false) 
            {
                break;
            }
        }
        
        if(canprint == true)
        {
            printf("%d.", c);
            
            c++;
            
            for(a = 0; a < len; a++)
            {
                temp_letter[0] = temp_word[a];
                sscanf(temp_letter, "%d", &temp_num);
                printf("%c", word[temp_num - 1]);
            }
            
            printf("\n");
        }
    
    }
}
