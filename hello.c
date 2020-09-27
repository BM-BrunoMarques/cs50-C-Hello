#include <stdio.h>
#include <cs50.h>


int main(void)
{
    //this will hold the user name
    string name;
    //print greeting user name. "get_string" is from cs50
    printf("hello, %s\n", name = get_string("What's your name?\n"));
}