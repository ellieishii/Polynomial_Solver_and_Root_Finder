#include <math.h>

// calculate F(x) by plugging a,b,c,d,e,f values and x into the polynomial function and return F(x)

double F(double a, double b, double c, double d, double e, double f, double x) {
        return a+b*x+c*pow(x,2)+d*pow(x,3)+e*pow(x,4)+f*pow(x,5);
}
