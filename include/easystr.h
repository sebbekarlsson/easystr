#ifndef EASYSTR_H
#define EASYSTR_H
#include <stdint.h>
#include <string.h>

typedef struct {
  char* value;
  uint32_t length;
} EStr;

typedef struct {
  EStr** items;
  uint32_t length;
} EStrList;

#define ESTR(val)                               \
  ((EStr){ val, strlen(val) })

EStr* e_init();

EStr* e_fromstr(char* val);

EStr* e_fromchar(char c);

EStrList* e_split(EStr s, char* delim);

unsigned int e_contains_str(EStr s, char* v);

unsigned int e_contains_char(EStr s, char c);

EStr* e_concat(EStr* a, EStr b);
EStr* e_concat_char(EStr* a, char c);
EStr* e_concat_str(EStr* a, char* ss);

char* e_chartostr(char c);

void e_free(EStr* s);
#endif
