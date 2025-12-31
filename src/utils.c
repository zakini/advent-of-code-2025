#include <ctype.h>
#include <string.h>

char *trim(char input[]) {
  char *end;

  while (isspace(input[0])) {
    input++;
  }

  if (input[0] == 0) {
    return input;
  }

  end = input + strlen(input) - 1;
  while (end > input && isspace(*end)) {
    end--;
  }
  end[1] = '\0';

  return input;
}
