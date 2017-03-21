//
//  Stack.h
//  Queue
//
//  Created by wyy on 2017/3/21.
//  Copyright © 2017年 wyy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Stack : NSObject
- (void)push:(NSString *)obj;
- (NSString *)pop;
- (NSUInteger)size;
@end
