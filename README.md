WZBaseModel
===========

## 简介

一个方便对象映射的BaseModel。

## 特性

- 支持同时使用服务端和客户端的参数名来生成model，使用```+ (NSDictionary *)dictionaryForServerAndClientKeys```来返回一个服务端字段名与客户端属性名的字典。
- 支持联合主键，```+ (NSArray *)keyNames```用来返回主键属性名的数组。
- 支持通过`NSDictionary`来映射`WZBaseModel`，如果同主键的Model已存在，则使用`NSDictionary`中的值来替换原有Model的值，然后返回。
- 支持KVO，对于主键相同的model，全局只存在一个实例，因此可以对其进行KVO，从而实现全局的数据同步。
- 支持使用`NSKeyedArchiver`和`NSKeyedUnarchiver`将model保存到`NSUserDefaults`，WZBaseModel已经覆写了`- (void)encodeWithCoder:(NSCoder *)coder`和`- (void)encodeWithCoder:(NSCoder *)coder`方法。
- 支持忽略服务端的冗余参数，如果不想总是看到不需要的Log警告，可以使用```+ (NSArray *)banNames```来返回要忽略的参数名数组。

## 示例

覆写`+ (NSDictionary *)dictionaryForServerAndClientKeys`，以便能使用服务端的字段名生成model。

```objective-c
+ (NSDictionary *)dictionaryForServerAndClientKeys
{
    return @{
             @"s_id"   : @"sid",
             @"s_name" : @"name",
             };
}
```

覆写`+ (NSArray *)keyNames`以便能使用KVO进行数据同步。

```objective-c
+ (NSArray *)keyNames
{
    return @[@"sid"];
}
```

```objective-c
Student *s1 = [Student modelFromDictionary:@{@"sid":@(1), @"name":@"John"}];
Student *s2 = [Student modelFromDictionary:@{@"sid":@(1), @"name":@"Tom"}];
    
if (s1 == s2) {
	NSLog(@"%@", s1.name);
}
```
`s1`和`s2`指向同一个`Student`实例，将会输出Tom。

## 联系方式

新浪微博 [@禁行线](http://weibo.com/weiguijiji)

Email: 123nobody@gmail.com