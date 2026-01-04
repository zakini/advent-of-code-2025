#ifndef AOC25_SRC_UTILS_H
#define AOC25_SRC_UTILS_H

enum { DECIMAL_BASE = 10 };

#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)

char *trim(char input[]);

#endif
