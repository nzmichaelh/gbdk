/* Unix */

#ifndef GBDKLIBDIR
#define GBDKLIBDIR "/home/michaelh/projects/gbdk-lib/"
#endif

#include <string.h>

char *suffixes[] = { ".c", ".i", ".asm;.s", ".o;.obj", ".gb", 0 };
char inputs[256] = "";

char *cpp[] = { GBDKLIBDIR "bin/sdcpp",
		"-Wall", "-lang-c++", "-DSDCC=1", "-DSDCC_PORT=gbz80",
		"-DSDCC_PROC=gbz80", "-DGB", "-DGAMEBOY", "-DINT_16_BITS",
		"$1", "$2", "$3", 0 };
char *include[] = { "-I" GBDKLIBDIR "include", 0 };

char *com[] = { GBDKLIBDIR "bin/sdcc",
		"-mgbz80", "--c1mode",
		"$1", "$2", "$3", 0 };

char *as[] = { GBDKLIBDIR "bin/as-gbz80", "-pog", "$1", "$3", "$2", 0 };
char *ld[] = { GBDKLIBDIR "bin/link-gbz80", "-n", "--",
	       "-z",
	       "$1", 
	       "-k" GBDKLIBDIR "lib/gbz80", "-lgbz80.lib",
	       "-k" GBDKLIBDIR "lib/gb", "-lgb.lib",
	       "$3", GBDKLIBDIR "lib/gb/crt0.o", "$2", 0 };

extern char *concat(char *, char *);

int option(char *arg) {
    return 0;
}
