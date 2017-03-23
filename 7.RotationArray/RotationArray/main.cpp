//
//  main.cpp
//  RotationArray
//
//  Created by wyy on 2017/3/22.
//  Copyright © 2017年 wyy. All rights reserved.
//

#include <iostream>

int sequenceSort(int *numbers, int pre, int last) {
    int value = numbers[pre];
    for (int index = pre + 1; index < last; index ++) {
        if (value > numbers[index]) return  numbers[index];
    }
    return value;
}

int min(int *numbers ,int lenght) {
    if (numbers == NULL || lenght < 0) return -1;
    int pre = 0;
    int last = lenght - 1;
    int indexMid = pre;
    if(numbers[pre] < numbers[last]) return numbers[pre];
    while (numbers[pre] >= numbers[last]) {
        if (last - pre == 1) {
            indexMid = last;
            break;
        }
        indexMid = (pre + last)/2;
        
        if (numbers[pre] == numbers[indexMid] && numbers[last] == numbers[indexMid]) {
            return  sequenceSort(numbers, pre, last);
        }
        
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
//    int in[6] = {5,6,1,2,3,4};
    int in[5] = {1,0,1,1,1};
    int b =  min(in,5);
    
    return 0;
}

