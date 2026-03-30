#include "levlib.h"
#include <stdio.h>
#include <stddef.h>
/* Function isAlpha checks whether a character is alphabetic */
int tt_isalpha (int c) 
{
	if ((c > 40 && c < 91) || (c > 97 && c < 123)) {
		return 1;
	}
	return 0;
}
/* Function isAlpha checks whether a character is printable */
int tt_isprint (int c) 
{
	if(c > 31 && c < 126) {
		return 1;
	}
	return 0;
}
/*Function for counting string length*/
size_t tt_strlen (const char *pSrc) 
{
	size_t size = 0;
	while (pSrc[size] !=  '\0') {
		size++;
	}
	return size;
}
/* This function copies one string to another */
char* tt_strcpy (char *pDest, const char *pSrc) 
{
	int i = 0;
	while (pSrc[i++]) {
		pDest[i] = pSrc[i];
		i++;
	}
	return pDest;
}
/* This function copies <size> characters from one string to another */
size_t tt_strlcpy (char *pDest, const char *pSrc, size_t size) 
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
int tt_tolower (int c) 
{
	return c > 64 && c < 91 ? c + 32 : c;
}
/*  */
char* tt_strchr (const char *pSrc, int c) 
{
	while (*pSrc && (*pSrc-'0') != c) {
		pSrc++;
	}
	if (*pSrc !=  '\0' || c ==  0) {
		return (char *)pSrc;
	}
	return NULL;
}
int tt_strcmp (const char *pSrc1, const char *pSrc2) 
{
	while (*pSrc1  && *pSrc1 == *pSrc2 ) {
		pSrc1++;
		pSrc2++;
	}
	return (*pSrc1-'0') - (*pSrc2-'0');
}
int tt_atoi (const char *pSrc)
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
char* tt_strnstr(const char *pBig, const char *pLittle, size_t len) 
{
	char *pTemp = malloc(sizeof(pLittle));
	while (len <= sizeof(pLittle)) {
		tt_strlcpy(pTemp, pLittle, sizeof(pLittle));
		if (tt_strcmp(pTemp, pLittle) == 0) {
			return (char *)pBig;
		}
		pBig++;
		len--;
	}
	return NULL;
}
void* tt_calloc(size_t count, size_t size) 
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
	tt_strcpy(pDest, pSrc);
	return pDest;
}
char **tt_split (char const *s, char c)
{
	char *pTemp = malloc(tt_strlen(s)*4+4);
	int i=0;
	int strCount=0;
	while(i < tt_strlen(s)) {
		while (s[i] != c) {
			pTemp[i] = s[i];
			i++;
		}
	i++;
	strCount++;
	}
	char **pDest
}
void tt_putchar_fd (char c, int fd) 
{

}
LinkedList *tt_lstnew (void *content)
{

}
int tt_lstsize (LiknedList *lst)
{

}
void  tt_lstadd_front(LinkedList **lst, LinkedList *new)
{

}
void  tt_lstadd_back(LinkedList **lst, LinkedList *new)
{

}
