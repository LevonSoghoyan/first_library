#include "levlib.h"
#include <stdio.h>
#include <stddef.h>
/* Function isAlpha checks whether a character is alphabetic */
int isAlpha (int c) 
{
	if ((c > 40 && c < 91) || (c > 97 && c < 123)) {
		return 1;
	}
	return 0;
}
/* Function isAlpha checks whether a character is printable */
int isPrint (int c) 
{
	if(c > 31 && c < 126) {
		return 1;
	}
	return 0;
}
/*Function for counting string length*/
size_t strlen (const char *pSrc) 
{
	size_t size = 0;
	while (pSrc[size] !=  '\0') {
		size++;
	}
	return size;
}
/* This function copies one string to another */
char* strcpy (char *pDest, const char *pSrc) 
{
	int i = 0;
	while (pSrc[i++]) {
		pDest[i] = pSrc[i];
		i++;
	}
	return pDest;
}
/* This function copies <size> characters from one string to another */
size_t strlcpy (char *pDest, const char *pSrc, size_t size) 
{
	
	int i = 0;
	while (pSrc[i++] && size ) {
		pDest[i] = pSrc[i];
		i++;
		size--;
	}
	return i;
}
/* */
int tolower (int c) 
{
	return c > 64 && c < 91 ? c + 32 : c;
}
/*  */
char* strchr (const char *pSrc, int c) 
{
	while (*pSrc && (*pSrc-'0') != c) {
		pSrc++;
	}
	if (*pSrc !=  '\0' || c ==  0) {
		return (char *)pSrc;
	}
	return NULL;
}
int strcmp (const char *pSrc1, const char *pSrc2) 
{
	int Id = 0;
	while (*pSrc1  && *pSrc1 == *pSrc2 ) {
		pSrc1++;
		pSrc2++;
	}
	return (*pSrc1-'0') - (*pSrc2-'0');
}
int atoi (const char *pSrc)
{
	while (*pSrc == ' ') {
		pSrc++;
	}
	int dest=0;
	while (*pSrc <= '9' && *pSrc >= '0') {
		dest *= 10;
		dest += (*pSrc-'0');
	}
	return dest;
}
char* strnstr(const char *pBig, const char *pLittle, size_t len) 
{
	char *pTemp;
	while (len <= sizeof(pLittle)) {
		strlcpy(pTemp, pLittle, sizeof(pLittle));
		if (strcmp(pTemp, pLittle) == 0) {
			return (char *)pBig;
		}
		pBig++;
		len--;
	}
	return NULL;
}
void* lCalloc(size_t count, size_t size) 
{
	char *pDest = malloc (count * size);
	char *pTemp = pDest;
	while (count--) {
		*pTemp = 0;
		pTemp++;
	}
	return pDest;
}
char* strdup(const char *pSrc)
{
	char *pDest = malloc (sizeof(pSrc));
	strcpy(pDest, pSrc);
	return pDest;
}
