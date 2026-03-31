#include "levlib.h"
#include <stdio.h>
int main() 
{
	printf("%d\n", tt_isalpha(5));
	printf("%d\n", tt_isalpha('s'));
	printf("%d\n", tt_isprint('a'));
	printf("%d\n", tt_isprint(''));
	const char *pTemp = "Hello";
	printf("%d\n", tt_strlen(pTemp));
	char *pStrcpy = malloc(100);
	tt_strcpy(pStrcpy, pTemp);
	printf("%s\n", pStrcpy);
	free(pStrcpy);
	*pStrcpy = malloc(100);
	tt_strlcpy(pStrcpy, pTemp, 5);
	printf("%s\n", pStrcpy);
	printf("%s\n", tt_tolower('H'));
	return 0;
}
