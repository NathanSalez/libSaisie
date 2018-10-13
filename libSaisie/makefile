all : testLib.exe

debug : DEBUG = -D__MODE_DEBUG_LIB_SAISIE__
debug : testDebugLib.exe 

testLib.exe : libSaisie.o
	gcc libSaisie.o testUtilisationLib.c -o testLib.exe 
	
testDebugLib.exe : libSaisie.o
	gcc $(DEBUG) libSaisie.c -o testDebugLib.exe

libSaisie.o : libSaisie.c
	gcc -c libSaisie.c

clean :
	rm *.o *.exe
