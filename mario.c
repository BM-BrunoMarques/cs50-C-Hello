#include <stdio.h>
#include <cs50.h>

int printThis(char ch, int n);

int main(void)
{
    int n;
    //this will prompt the user for a number between 1-8
    do
    {
        n = get_int("Please insert a number for height between 1 - 8: \n");
    }
    while (n < 1 || n > 8);


    //Vars declared here for 'for loop'.
    char space = ' ';
    char cardinal = '#';

    //Will run n times, n is the user input for height
    for (int i = 1 ; i <= n ; i++)
    {

        printThis(space, n - i);
        printThis(cardinal, i);
        printThis(space, 2);     // space between pyramid sides
        printThis(cardinal, i);

        printf("\n");
    }
}


//this function will print a character as 'ch' n times.
int printThis(char ch, int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("%c", ch);
    }
    return 0;
}