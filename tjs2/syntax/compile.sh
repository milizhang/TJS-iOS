#!/bin/sh
echo tjs.y :
perl CR.pl tjs.y
bison -dv tjs.y
perl postbison.pl tjs.tab.c
perl wrapTJSns.pl tjs.tab.h
echo copying ...
echo tjspp.y :
perl CR.pl tjspp.y
bison -dv --name-prefix=pp tjspp.y
perl postbison.pl tjspp.tab.c
perl wrapTJSns.pl tjspp.tab.h
echo copying ...
cp tjs.tab.c ../tjs.tab.cpp
cp tjs.tab.h ../tjs.tab.h
cp tjspp.tab.c ../tjspp.tab.cpp
cp tjspp.tab.h ../tjspp.tab.h
echo tjsdate.y :
perl CR.pl tjsdate.y
bison -dv --name-prefix=dp tjsdate.y
perl postbison.pl tjsdate.tab.c
perl wrapTJSns.pl tjsdate.tab.h
echo copying ...
cp tjsdate.tab.c ../tjsdate.tab.cpp
cp tjsdate.tab.h ../tjsdate.tab.h
./gen_wordtable.sh
