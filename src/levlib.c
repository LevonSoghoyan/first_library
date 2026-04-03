#include "levlib.h"
#include <stdio.h>
#include <stddef.h>

/* Function isAlpha checks whether a character is alphabetic */
int tt_isalpha(int c) 
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123)) {
		return 1;
	}
	return 0;
}

/* Function isAlpha checks whether a character is printable */
int tt_isprint(int c) 
{

	if(c > 31 && c < 127) {
		return 1;
	}

	return 0;
}

/*Function for counting string length*/
size_t tt_strlen(const char *pSrc) 
{
	size_t size = 0;

	while (pSrc[size] !=  '\0') {
		size++;
	}

	return size;
}

/* This function copies one string to another */
char* tt_strcpy(char *pDest, const char *pSrc) 
{
	int i = 0;

	while (pSrc[i]) {
		pDest[i] = pSrc[i];
		i++;
	}
    
    pDest[i] = '\0';
	return pDest;
}

/* This function copies <size> characters from one string to another */
size_t tt_strlcpy(char *pDest, const char *pSrc, size_t size) 
{
	int i = 0;
    
	while (pSrc[i] && size ) {
		pDest[i] = pSrc[i];
		i++;
		size--;
	}

	return i;
}

/* */
int tt_tolower(int c) 
{
	return c > 64 && c < 91 ? c + 32 : c;
}
/*  */
char* tt_strchr(const char *pSrc, int c) 
{
    int i = 0;

	while (i < tt_strlen(pSrc) && pSrc[i] != c) {
		i++;
	}

	if (i < tt_strlen(pSrc) || c ==  0) {
		return (char*) (pSrc + i);
	}

	return NULL;
}

int tt_strcmp(const char *pSrc1, const char *pSrc2) 
{
    int i = 0;
        
	while (pSrc1[i]  && pSrc1[i] == pSrc2[i]) {
		i++;
	}

	return (pSrc1[i] - '0') - (pSrc2[i] - '0');
}

int tt_atoi(const char *pSrc)
{
    int i = 0;
    int sign = 1;

	while (pSrc[i] && pSrc[i] == ' ') {
		i++;
	}

    if (pSrc[i] == '-') {
        sign = -1;
        i++;
    }

	int dest = 0;

	while (pSrc[i] && pSrc[i] <= '9' && pSrc[i] >= '0') {
		dest *= 10;
		dest += (pSrc[i] - '0');
        i++;
	}

	return dest * sign;
}

char* tt_strnstr(const char *pBig, const char *pLittle, size_t len) 
{
    int i = 0;
    char *pTemp = malloc(sizeof(pLittle));

	while (pBig[i] && len <= tt_strlen(pLittle)) {
		tt_strlcpy(pTemp, pBig, tt_strlen(pLittle));

		if (tt_strcmp(pTemp, (char*)(pBig + i) == 0)) {
			return (char*)pBig;
		}

		pBig++;
		len--;
	}

	return NULL;
}

void* tt_calloc(size_t count, size_t size) 
{
	char *pDest = malloc(count * size);
	char *pTemp = pDest;

	while (count--) {
		*pTemp = 0;
		pTemp++;
	}

	return pDest;
}

char* tt_strdup(const char *pSrc)
{
	char *pDest = malloc(tt_strlen(pSrc) * 4 + 4);
	tt_strcpy(pDest, pSrc);
	return pDest;
}

char **tt_split(char const *pS, char c)
{
	int nextIndx = 0;
	int strIndx = 0;
	size_t i = 0;
	int strCount = 0;

	while (i < tt_strlen(pS)) {

		while (pS[i] != c) {
			i++;
		}

		i++;
		strCount++;
	}

	char **pDest = malloc(strCount * 8);
	i = 0;

	while (i < tt_strlen(pS)) {

		if (pS[i] != c) {
			nextIndx = i;
		}

		int charCount = 0;

		while (pS[i] != c) {
			i++;
			charCount++;
		}

		i++;

		if (charCount != 0) {
			pDest[strIndx] = malloc(charCount * 4);
			tt_strlcpy(pDest[strIndx], pS + nextIndx, charCount);
			strIndx++;
		}

	}

	return pDest;
}

void tt_putchar_fd(char c, int fd) 
{
    write(fd, &c);
}

LinkedList* tt_lstnew(void *pContent)
{
	LinkedList *pNode = malloc(9);
	pNode->content = pContent;
	pNode->next = NULL;
	return pNode;
}

int tt_lstsize (LinkedList *pLst)
{
	if (pLst->next == NULL)
		return 1;
	return 1 + tt_lstsize(pLst++);
}
/*
*/
void  tt_lstadd_front(LinkedList **lst, LinkedList *new)
{
	new->next = *lst;
	*lst = new;
}

void  tt_lstadd_back(LinkedList **pLst, LinkedList *pNew)
{
	LinkedList *pTemp = *pLst;

	while (pTemp->next) {
		pTemp = pTemp->next;
    }
	pTemp->next = pNew;
}
