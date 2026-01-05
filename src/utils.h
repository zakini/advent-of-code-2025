#ifndef AOC25_SRC_UTILS_H
#define AOC25_SRC_UTILS_H

enum { DECIMAL_BASE = 10 };

#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)

char *trim(char input[]);

#define exit_if(val, fmt, ...)                                                                                        \
  do {                                                                                                                \
    if (val) {                                                                                                        \
      /* NOLINTNEXTLINE(cert-err33-c) we're about to exit. If we can't print then we'll just have to exit silently */ \
      fprintf(stderr, fmt __VA_OPT__(, ) __VA_ARGS__);                                                                \
      exit(EXIT_FAILURE);                                                                                             \
    }                                                                                                                 \
  } while (0)

#endif
