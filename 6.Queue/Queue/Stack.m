//
//  Stack.m
//  Queue
//
//  Created by wyy on 2017/3/21.
//  Copyright © 2017年 wyy. All rights reserved.
//

#import "Stack.h"
@interface Stack ()
@property (nonatomic, strong) NSMutableArray *array;
@end
@implementation Stack
- (instancetype)init {
    self = [super init];
    if (self) {
        _array = [NSMutableArray array];
    }
    return self;
}

- (void)push:(NSString *)obj {
    [self.array addObject:obj];
}

- (NSString *)pop {
    NSString *popObj = nil;
    if (self.array.count) {
        popObj = [self.array lastObject];
        [self.array removeLastObject];
    }
    return popObj;
}

- (NSUInteger)size {
    return _array.count;
}
@end
