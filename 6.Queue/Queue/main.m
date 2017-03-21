//
//  main.m
//  Queue
//
//  Created by wyy on 2017/3/21.
//  Copyright © 2017年 wyy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Queue.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        Queue *a = [Queue new];
        [a push:@"A"];
        [a push:@"B"];
        [a push:@"C"];
        NSLog(@"pop == %@",[a pop]);
        NSLog(@"pop == %@",[a pop]);
        NSLog(@"pop == %@",[a pop]);
        [a push:@"D"];
         NSLog(@"pop == %@",[a pop]);
        [a push:@"E"];
        [a push:@"F"];
        NSLog(@"pop == %@",[a pop]);
        NSLog(@"pop == %@",[a pop]);
    }
    return 0;
}
