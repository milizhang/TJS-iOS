//
//  TJSTest.cpp
//  TJSiOS
//
//  Created by Yi Zhang on 6/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <wchar.h>

#include "TJSTest.h"


tTJS *tjsengine;
ViewController *viewCtl = nil;

void destroytjs();


class ConsolePrint : public tTJSNativeFunction
{
    public :
    tjs_error Process ( tTJSVariant *result, tjs_int numparams,
                       tTJSVariant **param, iTJSDispatch2 *objthis )
    {
        if ( numparams <1 ) return TJS_E_BADPARAMCOUNT ;
        TJS::tTJSString str = param[0]->AsString() ;
        [viewCtl viewAppend:str.Independ()];
        return TJS_S_OK ;
    }
};


void inittjs()
{
    tjsengine = new tTJS () ;
    iTJSDispatch2* global = tjsengine->GetGlobalNoAddRef () ;
    
    iTJSDispatch2 * func = new ConsolePrint () ;
    
    tTJSVariant func_var(func) ;
    func->Release () ;
    
    TJS_THROW_IF_ERROR (
                        global->PropSet ( TJS_MEMBERENSURE, TJS_W("print"), NULL, &func_var, global ) );
    
    NCBindLink();
    
}

int eval(char *buf)
{
    try {
        tTJSVariant result ;
        tjsengine->ExecScript ( buf,
                               &result, NULL,
                               NULL ) ;
        return (int)result;
    }
    
    catch ( TJS::eTJSScriptError &e )
    {
        tjs_int l = e.GetSourceLine ();
        tjs_int pos = e.GetPosition ();
        
        TJS::ttstr tr = e.GetMessage();
        //std::cout << "Error: Line "<< l << ",Block " << tr.AsStdString() << std::endl ;
        
        wchar_t buffer[300];
        swprintf(buffer, 300, L"Error: Line %d, Block %d, %S.", l, pos, tr.Independ());
        
        [viewCtl viewAppend:buffer];
    }
    
    catch (...)
    {
        //std::cout << "Error:\n" << std::endl ;    
        [viewCtl viewAppend:L"Error:."];
    }
}

int evalw(wchar_t* buf)
{
    try {
        tTJSVariant result ;
        tjsengine->ExecScript ( buf,
                               &result, NULL,
                               NULL ) ;
        return (int)result;
    }
    
    catch ( TJS::eTJSScriptError &e )
    {
        tjs_int l = e.GetSourceLine ();
        tjs_int pos = e.GetPosition ();
        
        TJS::ttstr tr = e.GetMessage();
        //std::cout << "Error: Line "<< l << ",Block " << tr.AsStdString() << std::endl ;
        
        wchar_t buffer[300];
        swprintf(buffer, 300, L"Error: Line %d, Block %d, %S.", l, pos, tr.Independ());
        
        [viewCtl viewAppend:buffer];
    }
    
    catch (...)
    {
        //std::cout << "Error:\n" << std::endl ;        
        [viewCtl viewAppend:L"Error:."];
    }
}

void destroytjs()
{
    tjsengine->Shutdown () ;
    tjsengine->Release () ;
}

void verbose()
{
    char verbose[70];
    sprintf(verbose, "print(\"TJS2 Script Engine Interpreter [TJSi] (TJS/%d.%d.%d)\n\");",TJSVersionMajor,
            TJSVersionMinor, TJSVersionRelease);
	eval(verbose);
}


void testtjs()
{
    inittjs();
    verbose();
}


//---------------------------------------------------------------------------
//Functions for NCBind
//---------------------------------------------------------------------------

void TVPExecuteExpression(const ttstr & content , tTJSVariant* result = NULL)
{
    try {
        tjsengine->ExecScript ( content,
                               result, NULL,
                               NULL ) ;
    }
    
    catch ( TJS::eTJSScriptError &e )
    {
        tjs_int l = e.GetSourceLine ();
        tjs_int pos = e.GetPosition ();
        
        TJS::ttstr tr = e.GetMessage();
        //std::cout << "Error: Line "<< l << ",Block " << tr.AsStdString() << std::endl ;
        
        wchar_t buffer[300];
        swprintf(buffer, 300, L"Error: Line %d, Block %d, %S.", l, pos, tr.Independ());
        
        [viewCtl viewAppend:buffer];
    }
    
    catch (...)
    {
        //std::cout << "Error:\n" << std::endl ;    
        [viewCtl viewAppend:L"Error:."];
    }
}


iTJSDispatch2* TVPGetScriptDispatch()
{
    return tjsengine->GetGlobal();
}

void TVPThrowExceptionMessage(wchar_t*, ...)
{
    return;
}
