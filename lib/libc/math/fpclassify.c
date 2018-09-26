
#include <math.h>
#include <stdint.h>

int __fpclassifyf(float f) {
    return (FP_NORMAL);
}

int __fpclassifyd(double d) {
    return (FP_NORMAL);
}

int __fpclassifyl(long double e) {

    return (FP_NORMAL);
}