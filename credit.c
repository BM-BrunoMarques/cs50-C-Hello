#include <stdio.h>
#include <cs50.h>
#include <math.h>

//this program will request as input from user, a credit card number, which will be validated through:
// - non negative input.
// - Luhns algo.
// - veryfiyng allowed first two digits for MASTERCARD and AMEX and one digit for VISA.

//function declared to avoid error in main
string luhns(long x, string ameri, string visa, string master, string invalid);

int main()
{
    // this vars are declared here and passed throughout functions
    string ameri    = "AMEX\n";
    string visa     = "VISA\n";
    string master   = "MASTERCARD\n";
    string invalid    = "INVALID\n";
    long n = 0;

    //prompt user for non negative number
    do
    {
        n = get_long("Please insert your credit card number:\n");
    }
    while (n < 1);

    //this function will handle luhns algo and will return: ameri, visa, master or invalid
    string result = luhns(n, ameri, visa, master, invalid);

    printf("%s", result);

}


string luhns(long x, string ameri, string visa, string master, string invalid)
{

    int lastDigit = 0;
    int firstDigits = 0;
    int total = 0;
    int counter = 1;
    string nameAux  = "";

    // x is the user input " card number"
    while (x > 0)
    {
        //this will store the last two digits in the end.
        if (x > 9 && x < 100)
        {
            firstDigits = x;
        }

        lastDigit = x % 10;

        // doing odd even logic to multiply & add or add
        if (counter % 2 == 0)
        {
            int lastDigitAux = lastDigit * 2;
            while (lastDigitAux > 0)
            {
                // if lastDigit > 10 we are adding digit by digit to total
                total += (lastDigitAux > 9)
                         ? (lastDigitAux % 10)
                         : lastDigitAux;

                lastDigitAux /= 10;
            }
        }
        else
        {
            total += lastDigit;
        }
        x /= 10;

        counter++;
    }

    total = total % 10;

    counter--;

    switch (lastDigit) //here is the last digit remaining after finishing dividing x
    {
        case 3:
            nameAux = ((counter == 15) && (firstDigits == 34 || firstDigits == 37) && (total == 0))
                      ? ameri
                      : invalid;
            break;
        case 4:
            nameAux = ((counter == 13 || counter == 16) && (total == 0))
                      ? visa
                      : invalid;
            break;
        case 5:
            nameAux = ((counter == 16) && (firstDigits > 50 && firstDigits < 56) && (total == 0))
                      ? master
                      : invalid;
            break;
        default:
            nameAux = invalid;
            break;
    }

    return nameAux;
}