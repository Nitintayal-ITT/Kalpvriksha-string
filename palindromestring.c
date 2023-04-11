#include <stdio.h>
#include <string.h>

int isPalindrome(char str[])
{
    int len = strlen(str);
    int flag = 1;

    for (int i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        if (str[i] != str[j])
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void main()
{
    char str[100];
    scanf("%[^\n]%*c", str);
    //gets(str);
    if (isPalindrome(str))
    {
        printf("it is palindrome.");
    }
    else
    {
        printf("not a palindrome.");
    }
}