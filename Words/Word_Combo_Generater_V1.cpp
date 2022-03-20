#include <stdio.h>
#include <cstring>

char word[10] = "abcde";

void LoopLettersInWords(char word[10]);

int main()
{
    LoopLettersInWords(word);
}

void LoopLettersInWords(char word[])
{
    int len = strlen(word);
    int current = len - 2;
    int i;
    
    char newWord[10];
    int digit[10] = {3, 2, 1, 0};
    int currentLoopVar[10] = {0, 0, 0, 0};
    char temp_letter;
    int count = 1;
    
    for(i = 0; i < len; i++) {
        digit[i] = len - 1 - i;
        currentLoopVar[i] = 0;
    }
    strcpy(newWord, word);
    
    printf("%d %s\n", count, newWord);
    
    while (currentLoopVar[0] <= digit[0])
    {
        if (len - current - currentLoopVar[current] >= 2) {
            currentLoopVar[current] = currentLoopVar[current] + 1;
        } else {
            do {
                current = current - 1;
            } while (currentLoopVar[current] >= digit[current]);
            if (current == -1) {
                break;
            }
            for (i = 0; i < len; i++) {
                if ( i == current) {
                    currentLoopVar[i]++;
                } 
                if (i > current) {
                    currentLoopVar[i] = 0;
                }
            }
            current = len - 2;
        }
        strcpy(newWord, word);
        for (i = 0; i < len; i++) {
            if (currentLoopVar[i] == 0) {
                continue;
            } else {
                temp_letter = newWord[i];
                newWord[i] = newWord[currentLoopVar[i] + i];
                newWord[currentLoopVar[i] + i] = temp_letter;
            }
        }
        count++;
        printf("%d %s\n", count, newWord);
    }
    
}
