#include "revert_string.h"
#include <string.h>

void RevertString(char *str)
{
     char p[128];
 
    strcpy(p,str);
    int i=0, j=strlen(p)-1;
    while(i<=j+i)
     str[i++]=p[j--];
}