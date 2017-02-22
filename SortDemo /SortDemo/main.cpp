//
//  main.cpp
//  SortDemo
//
//  Created by wyy on 2017/1/18.
//  Copyright © 2017年 wyy. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAXSIZE 11
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

//冒泡
void inefficiencyBubblingMethod(Sqlist *list) {
    int length = list -> length;
    for (int i = 0; i < list -> length; i ++)
        for (int j = length -1; j >= i; j --) {
            if ((list -> r[i]) > (list -> r[j])) {
                swapValus(list, i, j);
            }
        }
}

//插入
void insertSort(Sqlist *list) {
    int length = list -> length;
    for (int i = 1; i < length; i++) {
        int temp = list -> r[i];
        for (int j = i -1; j >= 0; j --) {
            if (temp < list -> r[j]) {
                swapValus(list, j, j+1);
            }
        }
    }
}

//希尔
void shellSort(Sqlist *list) {
    int length = list -> length;
    int gap = length/2;
    while (gap >= 1) {
        for (int i = gap; i < length; i ++) {
            for (int j = i; j > 0; j -= gap) {
                if (list -> r[j - gap] >list -> r[j]) {
                   swapValus(list, j - gap, j);
                }
            }
        }
        gap = gap/2;
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

//快排分组，从小到大
int partitionIncreasing(Sqlist *list, int left, int right) {
    int storeIndex = left;
    int pivot = list -> r[right]; // 直接选最右边的元素为基准元素
    for (int i = left; i < right; i++) {
        if ((list -> r[i]) < pivot) {
            swapValus(list, storeIndex, i);
            storeIndex++;
        }
    }
    swapValus(list,right,storeIndex);
    return storeIndex;
}

void quickSort(Sqlist *list, int left, int right) {
    if (left > right) return;
    int storeIndex = partitionIncreasing(list, left, right);
    quickSort(list, left, storeIndex - 1);
    quickSort(list, storeIndex + 1, right);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int ri[12] = {1,2,5,7,8,4,3,55,6,6,35,24};
    Sqlist list ;
    list.length = sizeof(ri)/sizeof(ri[0]);
    for (int i = 0; i < list.length; i ++) {
        list.r[i] = ri[i];
    }
//    inefficiencyBubblingMethod(&list);
//    selectSort(&list);
    //insertSort(&list);
    //shellSort(&list);
    quickSort(&list, 0, list.length -1);
    return 0;
}


