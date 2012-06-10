//
//  TJSTest.h
//  TJSiOS
//
//  Created by Yi Zhang on 6/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TJSiOS_TJSTest_h
#define TJSiOS_TJSTest_h

#include "tjs.h"
#include "tjsError.h"
#include "tjsNative.h"
#include "tjsString.h"
#include "tjsVariant.h"

#import "ViewController.h"

extern iTJSDispatch2* TVPGetScriptDispatch();
extern void TVPThrowExceptionMessage(wchar_t*, ...);
extern void TVPExecuteExpression(const ttstr & , tTJSVariant*);

extern void testtjs();

extern int eval(char*);
extern int evalw(wchar_t*);

extern void NCBindLink();
extern void NCBindUnlink();

extern ViewController* viewCtl;

#endif
