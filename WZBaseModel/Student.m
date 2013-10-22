//
//  Student.m
//  WZBaseModel
//
//  Created by 魏哲 on 13-10-22.
//
//

#import "Student.h"

@implementation Student

+ (NSDictionary *)dictionaryForServerAndClientKeys
{
    return @{
             @"s_id"   : @"sid",
             @"s_name" : @"name",
             };
}

+ (NSArray *)keyNames
{
    return @[@"sid"];
}

@end
