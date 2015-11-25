/*	File:		RandomTestJig.c	Contains:	Test Jig.	Written by:	Steve Bollinger	Copyright:	Copyright (c) 1999 Apple Computer, Inc., All Rights Reserved.				You may incorporate this Apple sample source code into your program(s) without				restriction. This Apple sample source code has been provided "AS IS" and the				responsibility for its operation is yours. You are not permitted to redistribute				this Apple sample source code as "Apple sample source code" after having made				changes. If you're going to re-distribute the source, we require that you make				it clear in the source that the code was descended from Apple sample source				code, but that you've made changes.*/#include <stdio.h>#include <files.h>#include "RandomTestJig.h"#include "CreateRandExpNumbers.h"#define NUMNUMBERS		50000#define MAXNUMVAL		1000void TestRandom(void){	static unsigned long		madelist1[NUMNUMBERS];	static unsigned long		madelist2[NUMNUMBERS];	static unsigned long		madelist3[NUMNUMBERS];	unsigned					iter;	FILE						*nufile;	nufile = fopen("sizelist","w");	fprintf(nufile,"%lu\n",NUMNUMBERS);	RandomlySeedRandom();	CreateRandomExpNumbers(madelist1,MAXNUMVAL-4,NUMNUMBERS);	CreateRandomExpNumbers(madelist2,MAXNUMVAL-4,NUMNUMBERS);	CreateRandomExpNumbers(madelist3,MAXNUMVAL-4,NUMNUMBERS);	for (iter = 0; iter < NUMNUMBERS; iter++)	{		if (madelist2[iter] < madelist1[iter])			madelist1[iter] = madelist2[iter];		if (madelist3[iter] < madelist1[iter])			madelist1[iter] = madelist3[iter];		fprintf(nufile,"%lu\n",madelist1[iter]+4);	}	fclose(nufile);}