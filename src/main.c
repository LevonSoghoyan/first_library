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
	printf("%c\n", tt_tolower('H'));
 //   printf("%c\n", *tt_strchr(pTemp, 'o'));
    printf("%d\n", tt_strcmp("gggc","gggg"));
    printf("%d\n", tt_atoi("46548"));
    //printf("%s\n", tt_strnstr("hello","llo", 6));   
    printf("%d\n", tt_calloc(10,10));
    printf("%s\n", tt_strdup("string"));
    printf("%s\n", tt_split("my test string",' ')[0]);
    
	return 0;
}
