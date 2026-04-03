#include "levlib.h"
#include <stdio.h>
#include <stddef.h>
/***************************************************************** 
 *@brief Checks whether a character is alphabetic
 * @param c input character
 * @Returns 1 if c is alphabetic, otherwise 0
 ****************************************************************/
int tt_isalpha(int c) 
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123)) {
		return 1;
	}
	return 0;
}
/***************************************************************** 
 * @brief Checks whether a character is printable
 * @param c input character
 * @Returns 1 if c is printable, otherwise 0
 ****************************************************************/

int tt_isprint(int c) 
{

	if(c > 31 && c < 127) {
		return 1;
	}

	return 0;
}
/*****************************************************************
  * @brief Checks whether a character is printable
  * @param c input character
  * @Returns 1 if c is printable, otherwise 0
 ****************************************************************/

size_t tt_strlen(const char *pSrc) 
{
	size_t size = 0;

	while (pSrc[size] != '\0') {
		size++;
	}

	return size;
}
/*****************************************************************
 * @brief   Copies one string into another
 * @param   pDest Destination string address
 * @param   pSrc  Source string address
 * @return  Address of the destination string
 ****************************************************************/
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
/*****************************************************************
 * @brief   Copies a specific-length portion of one string into another
 * @param   pDest Destination string address
 * @param   pSrc  Source string address
 * @param   size  Number of characters to be copied
 * @return  Number of characters copied
 ****************************************************************/
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
/*****************************************************************
 * @brief   Converts an uppercase alphabetic character to lowercase
 * @param   c Input character
 * @return  c converted to lowercase if it is alphabetic, otherwise c unchanged
 ****************************************************************/
int tt_tolower(int c) 
{
	return c > 64 && c < 91 ? c + 32 : c;
}
/*****************************************************************
 * @brief   Finds the first occurrence of a character in a string
 * @param   pSrc Source string
 * @param   c    Character to search for
 * @return  Address of the first occurrence if found, otherwise NULL
 ****************************************************************/

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
/*****************************************************************
 * @brief   Compares two strings lexicographically
 * @param   pSrc1 First string
 * @param   pSrc2 Second string
 * @return  A negative value if the first string is lexicographically smaller,
 *          0 if the strings are equal, or a positive value otherwise
 ****************************************************************/

int tt_strcmp(const char *pSrc1, const char *pSrc2) 
{
    int i = 0;
        
	while (pSrc1[i]  && pSrc1[i] == pSrc2[i]) {
		i++;
	}

	return (pSrc1[i] - '0') - (pSrc2[i] - '0');
}
/*****************************************************************
 * @brief   Parses a string to an integer
 * @param   pSrc Input string
 * @return  The integer value at the beginning of the string
 ****************************************************************/

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
/*****************************************************************
 * @brief   Checks whether the source string contains the given string within a prefix
 * @param   pBig    Source string
 * @param   pLittle String to search for
 * @param   size    Size of the prefix
 * @return  Address of the first match within the prefix, otherwise NULL
 ****************************************************************/
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
/*****************************************************************
 * @brief   Allocates memory and initializes it to zero
 * @param   count Number of elements in the array
 * @param   size  Size of each element in bytes
 * @return  Pointer to the allocated memory, or NULL on failure
 ****************************************************************/

void* tt_calloc(size_t count, size_t size) 
{
	char *pDest = malloc(count * size);
	char *pTemp = pDest;

    if(!pDest) {
        return NULL;
    }

	while (count--) {
		*pTemp = 0;
		pTemp++;
	}

	return pDest;
}
/*****************************************************************
 * @brief   Duplicates a string into newly allocated memory
 * @param   pSrc Input string address
 * @return  Pointer to a new string that is a duplicate of pSrc,
 *          or NULL on failure
 ****************************************************************/
char* tt_strdup(const char *pSrc)
{
	char *pDest = malloc(sizeof(pSrc));
    
    if(!pDest) {
        return NULL;
    }

	tt_strcpy(pDest, pSrc);
	return pDest;
}
/*****************************************************************
 * @brief   Allocates memory and splits a string using a delimiter
 * @param   pS Source string
 * @param   c  Delimiter character
 * @return  Array of strings resulting from the split, or NULL on failure
 ****************************************************************/
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

	char **pDest = malloc(strCount * sizeof(char*));

    if (!pDest) {
        return NULL;
    }

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
/*****************************************************************
 * @brief   Writes a character to a file descriptor
 * @param   c  Input character
 * @param   fd File descriptor
 ****************************************************************/
 
void tt_putchar_fd(char c, int fd) 
{
    write(fd, &c);
}
/*****************************************************************
 * @brief   Adds a new node to a list
 * @param   pContent Address of the content
 * @return  Address of the newly added node
 ****************************************************************/

LinkedList* tt_lstnew(void *pContent)
{
	LinkedList *pNode = malloc(sizeof(LinkedList));
	pNode->content = pContent;
	pNode->next = NULL;
	return pNode;
}
/*****************************************************************
 * @brief   Counts the size of a linked list
 * @param   pList Address of the linked list
 * @return  Size of the list
 ****************************************************************/

int tt_lstsize (LinkedList *pLst)
{
	if (!pLst->next) {
		return 1;
    }
	return 1 + tt_lstsize(pLst->next);
}
/*****************************************************************
 * @brief   Adds a new node to the front of a linked list
 * @param   pLst Address of the pointer to the linked list
 * @param   pNew Address of the new node
 ****************************************************************/

void  tt_lstadd_front(LinkedList **pLst, LinkedList *pNew)
{
    if (!pLst || !pNew) {
        return;
    }

	pNew->next = *pLst;
	*pLst = pNew;
}
/*****************************************************************
 * @brief   Adds a new node to the end of a linked list
 * @param   pLst Address of the pointer to the linked list
 * @param   pNew Address of the new node
 ****************************************************************/

void  tt_lstadd_back(LinkedList **pLst, LinkedList *pNew)
{
	LinkedList *pTemp;
    
    if (!pLst || !pNew) {
        return;
    }

    if (*pLst == NULL) {
        *pLst = pNew;
        return;
    }

    pTemp = *pLst;

	while (pTemp->next) {
		pTemp = pTemp->next;
    }
	pTemp->next = pNew;
}
