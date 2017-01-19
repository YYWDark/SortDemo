//
//  main.cpp
//  SortDemo
//
//  Created by wyy on 2017/1/18.
//  Copyright © 2017年 wyy. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAXSIZE 10
typedef struct {
    int r[MAXSIZE + 1];
    int length;
}Sqlist;

void swapValus(Sqlist *list,int i, int j) {
    if (i == j) return;
    if (i > list -> length) return;
    if (j > list -> length) return;

    int temp = list -> r[i];
    list -> r[i] = list -> r[j];
    list -> r[j] = temp;
}

void inefficiencyBubblingMethod(Sqlist *list) {
    int length = list -> length;
    for (int i = 0; i < list -> length; i ++)
        for (int j = length -1; j >= i; j --) {
            if ((list -> r[i]) > (list -> r[j])) {
                swapValus(list, i, j);
            }
        }
}

void selectSort(Sqlist *list){
    int length = list -> length;
    int i,j,min;
    for (i = 0; i < length; i++) {
        min = i;
        for (j = i + 1; j <= length; j++) {
            if ((list -> r[min]) > (list -> r[j])) {
                min = j;
            }
        }
        if (i != min) {
            swapValus(list, i, min);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int ri[11] = {1,2,5,7,8,4,3,55,6,35,24};
    Sqlist list ;
    list.length = sizeof(ri)/sizeof(ri[0]);
    for (int i = 0; i < list.length; i ++) {
        list.r[i] = ri[i];
    }
//    inefficiencyBubblingMethod(&list);
//    selectSort(&list);
    
    return 0;
}


