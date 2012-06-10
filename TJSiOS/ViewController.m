//
//  ViewController.m
//  Test
//
//  Created by Yi Zhang on 6/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <wchar.h>
#import "ViewController.h"

#import "TJSTest.h"

@interface ViewController ()

@end

@implementation ViewController
@synthesize clear;
@synthesize textfield;
@synthesize run;
@synthesize textview;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    viewCtl = self;
    testtjs();
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
    } else {
        return YES;
    }
}

- (void)runScript:(id)sender
{
    wchar_t* ucsString = (wchar_t*)[textfield.text cStringUsingEncoding:NSUTF32StringEncoding];
    
    //Echo;
    wchar_t buffer_echo[strlen([textfield.text UTF8String])+2];
    buffer_echo[0] = L'>';
    buffer_echo[1] = 0;
    wcscat(buffer_echo,(wchar_t*)[textfield.text cStringUsingEncoding:NSUTF32StringEncoding]);
    [self viewAppend:buffer_echo];
    
    //Eval the input;
    evalw(ucsString);
    
    //Clear the input field
    textfield.text = @"";
}

- (void)clearView:(id)sender
{
    textview.text = @"";
}

- (void)viewAppend:(const wchar_t*) string
{
    textview.text = [[textview.text stringByAppendingString:
                     [[NSString alloc] initWithBytes:string 
                                    length: wcslen(string)*sizeof(wchar_t) 
                                    encoding:NSUTF32LittleEndianStringEncoding]] stringByAppendingFormat: @"\n"];
    NSString *str = textview.text;
    [textview scrollRangeToVisible:NSMakeRange(textview.text.length-5, 4)];

}


- (BOOL)textFieldShouldReturn:(UITextField *)field
{
    [self runScript:field];
    return NO;
}

- (void)dealloc
{  
    [clear release];
    [textfield release];
    [run release];
    [textview release];
    
    [super dealloc];
}

@end
