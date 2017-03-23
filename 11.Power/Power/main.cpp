//
//  main.cpp
//  Power
//
//  Created by wyy on 2017/3/23.
//  Copyright © 2017年 wyy. All rights reserved.
//

#include <iostream>
double power (double base , int exponent) {
    if (base == 0) return 0.0;
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    
    if (exponent < 0) {
        exponent = -exponent;
        base = 1/base;
    }
    
    double result = 1.0f;
    for (int index = 0; index < exponent; index ++) {
        result *= base;
    }
    
    return result;
}

double powerWithUnsignedExponent (double base , int exponent) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    
    if (exponent < 0) {
        exponent = -exponent;
        base = 1/base;
    }
    
    double result = powerWithUnsignedExponent(base, exponent >> 1);
    std::cout << result <<"Hello, World!\n";
    result *= result;
    if ((exponent &1) == 1) {
        result *= base;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    double result =  power(2.0, -4);
    double result = powerWithUnsignedExponent(2, 7);
    
    return 0;
}
