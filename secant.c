#include <math.h>
#include "myfunc.h"


// Calculat the roots by plugging x0, x1, y0, y1 values using the secant method and return X

double X(double x0, double x1, double y0, double y1) {
        return x1-y1*(x1-x0)/(y1-y0);
}
