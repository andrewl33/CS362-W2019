#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char inputChar()
{
  char testChars[] = {'[',
                      ']',
                      '(',
                      ')',
                      '{',
                      '}',
                      ' ',
                      'a',
                      'x',
                      '\0'};

  return testChars[rand() % 10];
}

void inputString(char *s)
{
  char testString[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
  char testChars[5] = {'r', 'e', 's', 'e', 't'};

  for (int i = 0; i < 5; i++)
  {
    int randVal;
    do
    {
      randVal = rand() % 6;
    } while (testString[randVal] != '\0');

    testString[randVal] = testChars[i];
  }

  strcpy(s, testString);
}

void testme()
{
  int tcCount = 0;
  char *s = (char *)malloc(sizeof(char) * 6);
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    inputString(s); // modified to keep memory
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0)
      state = 1;
    if (c == '(' && state == 1)
      state = 2;
    if (c == '{' && state == 2)
      state = 3;
    if (c == ' ' && state == 3)
      state = 4;
    if (c == 'a' && state == 4)
      state = 5;
    if (c == 'x' && state == 5)
      state = 6;
    if (c == '}' && state == 6)
      state = 7;
    if (c == ')' && state == 7)
      state = 8;
    if (c == ']' && state == 8)
      state = 9;
    if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
    {
      printf("error\n");
      exit(200);
    }
  }

  free(s);
}

int main(int argc, char *argv[])
{
  srand(time(NULL));
  testme();
  return 0;
}
