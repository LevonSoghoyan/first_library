#include "levlib.h"
#include <stdio.h>
/* Function isAlpha checks whether a character is alphabetic */
int isAlpha (int c) {
	if ((c > 40 && c < 91) || (c > 97 && c < 123)) {
		return 1;
	}
	return 0;
}
/* Function isAlpha checks whether a character is printable */
int isPrint (int c) {
	if(c > 31 && c < 126) {
		return 1;
	}
	return 0;
}
/*Function for counting string length*/
size_t strlen (const char *pSrc) {
	size_t size = 0;
	while (pSrc++ != "/0") {
		size++;
	}
	return size;
}

char* strcpy (char *pDest, const char *pSrc) {

}

size_t strlcpy (char *pDest, const char *pSrc, size_t size) {

}
int tolower (int c) {

}
char* strchr (const char *pSrc, int c) {

}
int strcmp (const char *pSrc1, const char *pSrc2) {

}
int atoi (const char *pSrc) {

}
char* strnstr(const char *pBig, const char *pLittle, size_t len) {

}

