#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//this program will request as input from user, which will be a phrase/string. Furthermore validating and
// attributting a grade accordingly with the Scholastic grading system.


//functions declared uphead for Main
int *countPhrase(string phrase, int phLen);
int Scholastic(int *phraseAT);

int main()
{

    //prompt user for a string
    string phrase = get_string("Please insert your credit card number:\n");

    int phLen = strlen(phrase);

    //this function will count and return the number of letters words and senteces from the input given string, into an array.
    int *phraseAT = countPhrase(phrase, phLen);

    int grade = Scholastic(phraseAT);

    if (grade > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    printf("Grade %d\n", grade);


}

int *countPhrase(string phrase, int phLen)
{

    static int counter[3];

    counter[0] = 0; // letters
    counter[1] = 1; // words
    counter[2] = 0; // sentences

    for (int i = 0; i < phLen; i++)
    {
        //letters
        if (isalpha(phrase[i]))
        {
            counter[0]++;
        }
        //words
        if (phrase[i] == ' ')
        {
            counter[1]++;
        }
        //sentences
        if (phrase[i] == '.' || phrase[i] == '!' || phrase[i] == '?')
        {
            counter[2]++;
        }
    }

    return counter;

}

int Scholastic(int *phraseAT)
{
//
//Scholastic ( index = 0.0588 * L - 0.296 * S - 15.8 )
// - L is the average number of letters per 100 words in the text, and
// - S is the average number of sentences per 100 words in the text.
//
// phraseAT = [0] letters ; [1] words ; [2] sentences

    printf(" letters: %i\n words: %i\n sentences: %i\n", phraseAT[0], phraseAT[1], phraseAT[2]);

    float L = (phraseAT[0] * 100.00) / phraseAT[1];
    float S = (phraseAT[2] * 100.00) / phraseAT[1];

    float index = 0.0588 * L - 0.296 * S - 15.8;

    return (int)round(index);
    return 0;
}