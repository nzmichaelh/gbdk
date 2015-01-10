/** @file ctype.h
    Character type functions.
*/
#ifndef _CTYPE_H
#define _CTYPE_H

#include <types.h>

BOOLEAN
isalpha(char c) BANKED;

BOOLEAN
isupper(char c) BANKED;

BOOLEAN
islower(char c) BANKED;

BOOLEAN
isdigit(char c) BANKED;

BOOLEAN
isspace(char c) BANKED;

char
toupper(char c) BANKED;

char
tolower(char c) BANKED;

#endif /* _CTYPE_H */
