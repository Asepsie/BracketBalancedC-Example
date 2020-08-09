#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


unsigned int open = 0;
unsigned int close = 0;
char *bopen;
char *bclose;
char emptys[] = "";
static int i = 0;

int checkString( char *s)
{

  static unsigned int j = 0;
  j++;
  printf("string lenght: %d, i: %d, s: %s\n", (int)strlen(s), i, s);

  if (strlen(s) == 0) goto end;

  if(*(s) == *(bopen)) 
  {
    printf("open\n");
    i++;
    checkString(s+1);
  }
  else if(*(s) == *(bclose))
  {
    printf("close\n");
    i--;
    checkString(s+1);
  }

end:
  return i;
}

int main(void)
{
  char s[] = "{{{}}}";
  
  bopen = "{";
  bclose = "}";

  int result = checkString(&s[0]);

  if(result == 0)  printf("Bracket are balanced\n");
  else printf("Bracket are NOT balanced\n");
}