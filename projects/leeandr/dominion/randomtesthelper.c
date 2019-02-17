#include <stdio.h>
#include <string.h>
#include "randomtesthelper.h"

void assertEqual(char *message, int expected, int actual)
{

  int len = strlen(message);
  char outputString[len + 10];
  memset(&outputString, 0, sizeof(outputString));
  if (expected == actual)
  {
    strcat(outputString, "True: ");
    strcat(outputString, message);

    printf("%s\n", outputString);
  }
  else
  {
    strcat(outputString, "False: ");
    strcat(outputString, message);

    printf("%s\n", outputString);
  }
}