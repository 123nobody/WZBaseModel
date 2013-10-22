//
//  WZBaseModel.h
//  WZBaseModel
//
//  Created by 魏哲 on 13-10-22.
//
//

#import <Foundation/Foundation.h>

/**
 *  基本数据模型
 */
@interface WZBaseModel : NSObject

/**
 *  使用Dictionary来获取一个Model对象
 *
 *  @param dictionary 包含Model对象<属性名> - <值>的字典。
 *
 *  @return Model对象
 */
+ (instancetype)modelFromDictionary:(NSDictionary *)dictionary;

/**
 *  使用Model对象来获取一个Dictionary
 *
 *  @param model Model对象。
 *
 *  @return 包含Model对象<属性名> - <值>的字典
 */
+ (NSDictionary *)dictionaryFromModel:(WZBaseModel *)model;

/**
 *  使用Dictionary来获取一个Model对象
 *
 *  @param dictionary 包含Model对象<属性名> - <值>的字典。
 *
 *  @return Model对象
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

#pragma mark - WZBaseModelCenter Class

/**
 *  全局的ModelCenter，用来存储model，实现KVO。
 */
@interface WZBaseModelCenter : NSObject

/**
 *  用来保存Model的字典
 */
@property (nonatomic, strong) NSMutableDictionary *modelDictionary;

/**
 *  获取WZBaseModelCenter单例
 *
 *  @return WZBaseModelCenter单例
 */
+ (WZBaseModelCenter *)sharedInstance;

@end
