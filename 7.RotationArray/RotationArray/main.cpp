//
//  main.cpp
//  RotationArray
//
//  Created by wyy on 2017/3/22.
//  Copyright © 2017年 wyy. All rights reserved.
//

#include <iostream>

int min(int *numbers ,int lenght) {
    if (numbers == NULL || lenght < 0) return -1;
    int pre = 0;
    int last = lenght - 1;
    int indexMid = pre;
    while (numbers[pre] >= numbers[last]) {
        if (last - pre == 1) {
            indexMid = last;
            break;
        }
        indexMid = (pre + last)/2;
        if (numbers[indexMid] >= numbers[pre]) {
            pre = indexMid;
        }else if (numbers[indexMid] <= numbers[last]) {
            last = indexMid;
        }
    }
    return numbers[indexMid];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
//    int in[8]  = {1,2,3,4,5,6,7,8};
//    int in[6] = {4,5,6,1,2,3};
//    int in[7] = {4,5,6,7,1,2,3};
    int in[6] = {5,6,1,2,3,4};

    int b =  min(in,6);
    
    return 0;
}

