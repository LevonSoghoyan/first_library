#include "levlib.h"
#include <stdio.h>
int main() 
{
	printf("%d isalpha\n", tt_isalpha(5));
	printf("%d\n", tt_isalpha('s'));
	printf("%d isprint\n", tt_isprint('a'));
	printf("%d\n", tt_isprint(''));
	const char *pTemp = "Hello";
	printf("%d strlen\n", tt_strlen(pTemp));
	char *pStrcpy = malloc(100);
	tt_strcpy(pStrcpy, pTemp);
	printf("%sstrcpt\n", pStrcpy);
	free(pStrcpy);
	*pStrcpy = malloc(100);
	tt_strlcpy(pStrcpy, pTemp, 5);
	printf("%s strlcpi\n", pStrcpy);
	printf("%c tolower\n", tt_tolower('H'));
    printf("%c strchr\n", *tt_strchr(pTemp, 'o'));
    printf("%d strcmp\n", tt_strcmp("gggc","gggg"));
    printf("%d atoi\n", tt_atoi("46548"));
    printf("%s strnstr\n", tt_strnstr("hello","llo", 6));   
    printf("%d calloc\n", tt_calloc(10,10));
    printf("%s strdup\n", tt_strdup("string"));
    printf("%s split\n", tt_split("my test string",' ')[1]);
    
	return 0;
}
