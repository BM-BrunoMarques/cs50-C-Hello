#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//this program will request as input from user, which will be a phrase/string. Furthermore validating and
// attributting a grade accordingly with the Scholastic grading system.


//functions declared uphead for Main
int validate_args(int argc, string argv);
string cypherText(string plainT, string argv);


int main(int argc, char *argv[])
{
    // checking if args are valid before passing into function
    if (argc != 2)
    {
        printf("Err: please rerun the program and insert one argument.\n");
        return 1;
    }
    else
    {
        int result = validate_args(argc, argv[1]); //function call, validate the cypher argument, alpha / length / repetition
        if (result != 0)
        {
            return 1;
        }
    }

    string plainT = get_string("plaintext: ");

    string cypherT = cypherText(plainT, argv[1]);

    printf("ciphertext: %s\n", cypherT);

}



int validate_args(int argc, string argv)
{
    int cyphlen = strlen(argv);
    unsigned long long multCorrect = 1;
    unsigned long long multValidadte = 1;
    char abc = 'A';

    if (cyphlen != 26)
    {
        printf("Err: please rerun the program and insert a valid argument with 26 length.\n");
        return 1;
    }

    // this is the multiplication of the ASCII table characters from A to Z in upperCase.
    for (int i = 0; i < cyphlen; i++)
    {
        multCorrect *= abc;

        abc++;
    }

    // multiplication of all values in cypher
    for (int i = 0; i < cyphlen; i++)
    {
        if (isalpha(argv[i]))
        {
            multValidadte *= toupper(argv[i]);
        }
        else
        {
            printf("Err: please make sure there are ONLY alpha values in argument\n");
            return 1;
        }
    }

    // if multiplication of regular ABC and Cypher key matches, it's because they are equal.
    // I am using this method to avoid using a sort algorithm, and then an iteration for repetitions.
    // not fully tested, but seems like it works.
    if (multCorrect != multValidadte)
    {
        printf("Err: please make sure there are no repeated letters in argument.\n");
        return 1;
    }

    return 0;

}

//in this function I am converting alpha characters and subtracting A or a to make a char equal to the array postions of the argv passed.
string cypherText(string plainT, string argv)
{
    int plainIndex = 0;
    int plainLen = strlen(plainT);
    string cypherText = NULL;

    for (int i = 0 ; i < plainLen; i++)
    {
        char plainC = plainT[i];
        if (isalpha(plainC))
        {
            bool upper = isupper(plainC) ? true : false;

            if (upper)
            {
                plainIndex = plainC - 'A';
                plainT[i] = toupper(argv[plainIndex]);
            }
            else
            {
                plainIndex = plainC - 'a';
                plainT[i] = tolower(argv[plainIndex]);
            }
        }

    }

    return plainT;
}