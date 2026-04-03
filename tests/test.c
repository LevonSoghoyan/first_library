#include "levlib.h"
#include <stdio.h>
#include "test.h"
#include <stdbool.h>

void assert(int condition, char *pTestName) 
{
    if (condition) {
        printf("DONE %s\n",pTestName);
    } else {
        printf("FAIL %s\n",pTestName);
    }
}

bool test_isalpha()
{
    char c = 65;

    while (c < 123) {

       if (tt_isalpha(c)) {
            c++;

            if (c == 91) {
                c = 97;
            }

        } else {

            return false;
        }
    }
    
    if (tt_isalpha('1')) {
        return false;
    }

    return true;
}

bool test_isprint()
{

    char c = 32;

    while (c < 127) {

       if (tt_isprint(c)) {
            c++;

        } else {

            return false;
        }
    }

    if (tt_isalpha('')) {
        return false;
    }

    return true;
}

bool test_strlen()
{
    char *pChar = malloc(sizeof(char));

    if (tt_strlen(pChar) != 0) {
        return false;
    }

    return tt_strlen("test string") == 11;
}

bool test_strcpy()
{
    char *pStr = malloc(sizeof("Hello"));
    pStr = tt_strcpy(pStr, "Hello");

    if(tt_strcmp(pStr, "Hello") == 0) {
        return true;
     }

     return false;
}

bool test_strlcpy()
{

    char *pStr = malloc(sizeof("Hello"));
    int lenght = tt_strlcpy(pStr, "Hello", 4);

    if(tt_strcmp(pStr, "Hell") == 0 && lenght == 4) {
        return true;
     }

     return false;
}

bool test_tolower()
{

    char c = 0;

    while (c < 127) {

       if (tt_tolower(c) == c + 32 && c > 63 && c < 91) {
            c++;

        } else {

            return tt_tolower(c) == c;
        }
    }
}

bool test_strcmp()
{
    return !tt_strcmp("", "");
}

bool test_atoi()
{
    if (tt_atoi("-120") == -120 && tt_atoi("12as") == 12) {
            return true;
    }

    return false;
}

bool test_split() 
{
    char **str;
    str = tt_split("test case",' ');
    return tt_strcmp(str[0], "test") == 0 && tt_strcmp(str[1], "case") == 0;
}

bool test_calloc()
{
    int *arr = tt_calloc(4,sizeof(int));
    return arr[3] == 0;
}

bool test_strdup()
{
    char *pDest = tt_strdup("test");
    return tt_strcmp(pDest, "test") == 0;
}

int main() 
{
    assert(test_isalpha(),"tt_isalpha");   
    assert(test_isprint(),"tt_isprint");   
    assert(test_strlen(),"tt_strlen");   
    assert(test_strcpy(),"tt_strcpy");   
    assert(test_strlcpy(),"tt_strlcpy");   
    assert(test_tolower(),"tt_tolower");   
    assert(test_strcmp(),"tt_strcmp");   
    assert(test_atoi(),"tt_atoi");   
    assert(test_split(),"tt_split");   
    assert(test_calloc(),"tt_calloc");   
    assert(test_strdup(),"tt_strdup");   
	return 0;
}
