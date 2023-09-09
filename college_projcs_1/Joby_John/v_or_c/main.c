#include<stdio.h>
#include<ctype.h>
#include<conio.h>

void main()
{
    char letter;
    printf("Enter the letter you want to check for vowel or consonant\n");
    scanf("%c", &letter);
    letter = tolower(letter);

    switch(letter)
    {
        case ('a'):
             printf("Yes! %c, is a vowel", letter);
             break;
        case ('e'):
             printf("Yes!, %c, is a vowel", letter);
             break;  
        case ('i'):
             printf("Yes! %c, is a vowel", letter);
             break;
        case ('o'):
             printf("Yes! %c, is a vowel", letter);
             break;
        case ('u'):
             printf("Yes! %c, is a vowel", letter);
             break;               
        default:
             printf("%c is a consonant", letter);                                       
    }
getch();
}