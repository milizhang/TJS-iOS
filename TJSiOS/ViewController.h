//
//  ViewController.h
//  TJSiOS
//
//  Created by Yi Zhang on 6/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController{
    UITextView *textview;
    UITextField *textfield;
    UIButton *run;
    UIButton *clear;
}

@property (retain, nonatomic) IBOutlet UITextView *textview;
@property (retain, nonatomic) IBOutlet UITextField *textfield;
@property (retain, nonatomic) IBOutlet UIButton *run;
@property (retain, nonatomic) IBOutlet UIButton *clear;

-(IBAction) runScript: (id) sender;
-(IBAction) clearView: (id) sender;

- (void)viewAppend:(const wchar_t*) string;

@end
