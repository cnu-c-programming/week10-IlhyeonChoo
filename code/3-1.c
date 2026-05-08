#include <stdio.h>
#include <stdlib.h>

struct Student {
  char *name;
  int score;
};

void add(char *name, int score) {
  struct Student s = malloc(sizeof(struct Student));
}
