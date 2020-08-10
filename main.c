#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* For generating parenthesis */
unsigned int open = 0;
unsigned int close = 0;

char *bopen;
char *bclose;
static int i = 0;

int checkString( char *s)
{

  static unsigned int j = 0;
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

void printParenthesis(int position, int close, int open, int lenght)
{
  static char s[100];


  if(close == lenght)
  {
    printf("%s\n", s);
    return;
  }
  else
  {
    if(open > close)
    {
      printf("-- add }  pos: %d close: %d open: %d \n", position, close, open);
      s[position] = '}';
      printParenthesis(position+1, close+1, open, lenght);
    }
    if(open < lenght)
    {
     printf("-- add {  pos: %d close: %d open: %d \n", position, close, open);
      s[position] = '{';
      printParenthesis(position+1, close, open+1, lenght);
    }
  printf("--end pp\n");
  }
}


int main(void)
{
  char s[] = "{{{}}}";
  
  bopen = "{";
  bclose = "}";

  int result = checkString(&s[0]);

  if(result == 0)  printf("Bracket are balanced\n");
  else printf("Bracket are NOT balanced\n");

  printParenthesis(0,0,0,3);


}