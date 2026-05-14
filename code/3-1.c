#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char *name;
  int score;
  struct Student *next;
};

void add(char *name, int score, struct Student *s1) {
  struct Student *new_student = malloc(sizeof(struct Student));

  new_student->name = malloc(strlen(name) + 1);

  strcpy(new_student->name, name);
  new_student->score = score;
  new_student->next = NULL;

  while (s1->next != NULL) {
    s1 = s1->next;
  }
  s1->next = new_student;
}

void delete(char *name, struct Student *s1) {
  struct Student *prev = s1;
  struct Student *next;

  while (strcmp(prev->next->name, name)) {
    prev = prev->next;
  }

  next = prev->next->next;
  free(prev->next->name);
  free(prev->next);
  prev->next = next;
}

void print(struct Student *s1) {
  struct Student *current = s1->next;

  while (current != NULL) {
    printf("%s %d\n", current->name, current->score);
    current = current->next;
  }
}

void quit(struct Student *s1) {
  struct Student *current = s1->next;

  while (current != NULL) {
    struct Student *next = current->next;

    free(current->name);
    free(current);

    current = next;
  }

  s1->next = NULL;
}

int main() {
  char op[20], name[100];
  int score;
  struct Student s = {NULL, 0, NULL};

  while (scanf("%s", op) == 1) {
    if (strcmp(op, "add") == 0) {
      scanf("%s %d", name, &score);
      add(name, score, &s);
    } else if (strcmp(op, "delete") == 0) {
      scanf("%s", name);
      delete(name, &s);
    } else if (strcmp(op, "print") == 0) {
      print(&s);
    } else if (strcmp(op, "quit") == 0) {
      quit(&s);
      break;
    }
  }

  return 0;
}
