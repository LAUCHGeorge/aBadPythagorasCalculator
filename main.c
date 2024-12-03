/*
  Author: LAUCHGeorge

  A very simple Calculator for Pythagorean theorem.
  This was created as an attempt to get familiar with the basics of C.
  I chose this task, as I have already made this exact thing in Java previously.

  If you don't like the fuckton of comments, that's a skill issue on your behalf.

*/

#include <stdio.h>
#include <math.h>

// Declaring variables outside any functions, for easy access.
double a;
double b;
double c;
double p;
double q;
double h;
double A;

void calculate() { // Simple function to calculate all values, for easier readability of code.
    c = sqrt(pow(a,2)+pow(b,2));
    q = pow(b,2)/c;
    p = c-q;
    h = sqrt(p*q);
    A = a*b/2;
}

double getInput(char prompt[]) { // Getting the user input in a sort of safe way.

    double userInput = 0;

    while(1) {
        printf("%s",prompt);
        scanf("%lf",&userInput);    // Getting the user input and saving it in a previously declared variable.
        while (getchar() != '\n');        // Clearing scanf buffer thingy or smth. Either way, it's needed as the program will otherwise get stuck in a loop.
        if(userInput != 0) {             // Checking if userInput is valid.
            return userInput;
        } else {printf("%s\n\n","That is not a valid number. Please either enter a valid number or press Alt+F4.");}
    }
}

int main(void) { // Starting point of the program.

    printf("%s\n%s\n%s\n\n",
           "***************************",
           "a Bad Pythagoras-Calculator",
           "***************************");

    // Calling function to get Input (x2).
    a = getInput("Please enter the length of a:");
    b = getInput("Please enter the length of b:");

    // Calling function to calculate.
    calculate();

    printf("\n%-25s%10.3lf\n%-25s%10.3lf\n%-25s%10.3lf\n%-25s%10.3lf\n%-25s%10.3lf\n",  // Pulling the "fancy af. shit", that ain't even that fancy anymore in C.
            "Side length c:", a,
            "Hypotenuse section p:", p,
            "Hypotenuse section q:", q,
            "Height h:", h,
            "Area A:", A );

    return 0;
}