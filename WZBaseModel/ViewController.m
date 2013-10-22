//
//  ViewController.m
//  WZBaseModel
//
//  Created by 魏哲 on 13-10-22.
//
//

#import "ViewController.h"
#import "Student.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    Student *s1 = [Student modelFromDictionary:@{@"sid":@(1), @"name":@"John"}];
    Student *s2 = [Student modelFromDictionary:@{@"sid":@(1), @"name":@"Tom"}];
    
    if (s1 == s2) {
        NSLog(@"%@", s1.name);
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
