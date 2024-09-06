#include <stdio.h>
#include <math.h>
#include "secant.h"
#include "myfunc.h"

#define TRUE 1
#define FALSE 0


int main(void) {

// Ask the user to enter the coefficients for the polynomial function and read and store the inputs (a, b, c, d, e, f)

        double a, b, c, d, e, f;
        printf("Enter the coefficients for a polynomial of the form: \n");
        printf("     a + bx+ cx^2 + dx^3 + ex^4 + fx^5 \n\n");

        printf("Enter a b c d e f: ");
        scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
        printf("\n");


// Print the complete user-input polynomial function

        printf("The function is: %.2lf + %.2lfx + %.2lfx^2 + %.2lfx^3 + %.2lfx^4 + %.2lfx^5\n\n", a, b, c, d, e, f);


// Loop until user is done with the program

        int done = FALSE;
        while(!done) {


// Ask the user to chose the starting and ending x-values for a table and read and store the inputs (xmin, xmax)

                printf("The range of x-values for calculations of the table \n");

                double xmin;
                double xmax;

                printf("Enter start end: ");
                scanf("%lf %lf", &xmin, &xmax);
                printf("\n");


// Ask the user to enter the number of intervals and read and store the input (steps) and calculate the increment

                int steps;

                printf("Enter the number of intervals for your table: ");
                scanf("%i", &steps);
                printf("\n");

                double incr;
                incr = (xmax - xmin)/steps;


// Print the table for x-values and y-values

                printf(" x-value            y-value\n");
                printf("==========	==============\n");

                double x;


// Declare i iterator and j iterator for loops

                int i;
                int j=0;


// Initialize i = 0, loop until i<= steps, increment i by 1 for FOR loop

                for (i=0; i<=steps; i++) {
                        x = xmin + i*incr;


// Declare previous to keep track of sign changes

                        double previousx;
                        previousx = x - incr;


// Call 'myfunc.c' to print the calculated x and y values in the table

                        printf("%9.3lf        %13.3lf", x, F(a, b, c, d, e, f, x));


// Set signChange = FALSE so that it resets to FALSE everytime after a complete loop which allows us to keep track of the number of sign changes

                        double x0, x1, x2, y0, y1, y2, xnew;
                        double epsilon = 0.001;
                        int signChange = FALSE;


// If there is a sign change, then call 'secant.c' to calculat the root

                        if (F(a, b, c, d, e, f, previousx) < 0 && F(a, b, c, d, e, f, x) >= 0 || F(a, b, c, d, e, f, previousx) >= 0 && F(a, b, c, d, e, f, x) < 0) {
                                x1 = x-incr;
                                x2 = x;
                                xnew = x2;
                                signChange = TRUE;

                                while (fabs(F(a, b, c, d, e, f, x2)) > epsilon) {
                                        y1 = F(a, b, c, d, e, f, x1);
                                        y2 = F(a, b, c, d, e, f, x2);

                                        xnew = X(x1, x2, y1, y2);

                                        x = x1;
                                        x1 = x2;
                                        x2 = xnew;
                                }


// After done finding the xnew (converged), add 1 to the iterator and restart the loop

                                x = xnew;
                                printf("   <= the root located is %.3lf\n", xnew);
                                j++;
                        }


// If there is no root, print blank spaces

                        else {
                              	printf("   \n");
                        }

// End the loop

               	}

                printf("\n");
                printf("Total sign changes located on table is: %i\n", j);


// Ask the user if they are done with the program or want to continue and change the search range

                char choice;
                printf("\n");
                printf("Do you wish to change the search range for the table? (y/n): ");
                scanf(" %c", &choice);


// If yes = go back to the while not done loop, otherwise, end the program

                if (choice == 'y' || choice == 'Y') {
                        printf("\n");
                        done = FALSE;
                }


                else {
                      	done = TRUE;
                }

        }

	return 0;

}
