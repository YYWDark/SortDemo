//
//  Queue.m
//  Queue
//
//  Created by wyy on 2017/3/21.
//  Copyright © 2017年 wyy. All rights reserved.
//

#import "Queue.h"
#import "Stack.h"

@interface Queue ()
@property (nonatomic, strong) Stack *A;
@property (nonatomic, strong) Stack *B;
@end
@implementation Queue
- (instancetype)init {
    self = [super init];
    if (self) {
        self.A = [Stack new];
        self.B = [Stack new];
    }
    return self;
}

- (NSString *)pop {
    //如果B还有内容
    NSString *popObj  = nil;
    if (self.B.size) {
        popObj = [self.B pop];
        return popObj;
    }
    //如果没有内容直接将A的push到B
    while (self.A.size) {
       NSString *obj = [self.A pop];
       [self.B push:obj];
    }
    
    if (self.B.size) {
        popObj = [self.B pop];
    }
    return popObj;
}

- (void)push:(NSString *)obj {
    [self.A push:obj];
}

- (NSUInteger)size {
   return [self.A size];
}
@end
