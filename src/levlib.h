#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	void *content;
	struct LinkedList *next;
} LinkedList;
int tt_isalpha (int c);
int tt_isprint (int c);
size_t tt_strlen (const char *pSrc);
char* tt_strcpy (char *pDest, const char *pSrc);
size_t tt_strlcpy (char *pDest, const char *pSrc, size_t size);
int tt_tolower (int c);
char* tt_strchr (const char *pSrc, int c);
int tt_strcmp (const char *pSrc1, const char *pSrc2);
int tt_atoi (const char *pSrc);
char* tt_strnstr (const char *pBig, const char *pLittle, size_t len);
void* tt_calloc (size_t count, size_t size);
char* tt_strdup (const char *pSrc);
char** tt_split (char const *s, char c);
void tt_putchar_fd (char c, int fd);
LinkedList *tt_lstnew (void *content);
int tt_lstsize (LinkedList *lst);
void  tt_lstadd_front(LinkedList **lst, LinkedList *new);
void  tt_lstadd_back(LinkedList **lst, LinkedList *new);
