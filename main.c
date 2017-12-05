#include <stdio.h>
#include <string.h>

int isnumber(int c) {
  return (c >= '0' && c <= '9') || c == '.';
}

int str_isnumber(char const *str) {
  int i, len = strlen(str);
  for (i = 0; i < len; i++) {
    if (!isnumber(str[i])) {
      return 0;
    }
  }
  return 1;
}

int count_significant_digits(char const *str) {
  int i, len, heading=1, decimal=0, zerocount=0, count = 0;
  len = strlen(str);
  for (i = 0; i < len; i++) {
    switch(str[i]) {
      case '.':
        decimal = 1;
        continue;
      case '0':
        if (!heading) {
          zerocount++;
        }
        break;
      default:
        heading = 0;
        count += zerocount + 1;
        zerocount = 0;
    }
  }
  if (decimal) {
    count += zerocount;
  }
  return count;
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    if (str_isnumber(argv[1])) {
      printf("Number %s has %d significant digits.\n",
          argv[1], count_significant_digits(argv[1]));
      return 0;
    }
  }
  printf("Please provide some number as an argument.\n");
  return 1;
}
