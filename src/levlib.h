#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int isAlpha (int c);
int isPrint (int c);
size_t strlen (const char *pSrc);
char* strcpy (char *pDest, const char *pSrc);
size_t strlcpy (char *pDest, const char *pSrc, size_t size);
int tolower (int c);
char* strchr (const char *pSrc, int c);
int strcmp (const char *pSrc1, const char *pSrc2);
int atoi (const char *pSrc);
char* strnstr (const char *pBig, const char *pLittle, size_t len);
void* lCalloc (size_t count, size_t size);
char* strdup (const char *pSrc);
