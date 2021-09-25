#include <easystr.h>
#include <easymem.h>
#include <stdio.h>

EStr* e_init() {
  EStr* e = (EStr*)easy_calloc(1, sizeof(EStr));
  e->value = 0;
  e->length = 0;

  return e;
}

EStr* e_fromchar(char c) {
  EStr* e = e_init();
  e->value = (char*)easy_calloc(2, sizeof(char));
  e->value[0] = c;
  e->value[1] = '\0';

  return e;
}

EStr* e_fromstr(char* val) {
  EStr* e = e_init();
  e->value = val != 0 ? strdup(val) : 0;
  e->length = val != 0 ? strlen(val) : 0;

  return e;
}

EStrList* e_split(EStr s, char* delim) {
  EStrList* elist = (EStrList*)easy_calloc(1, sizeof(EStrList));
  elist->items = 0;
  elist->length = 0;
  if (!s.value) return elist;

  char* strval = strdup(s.value);
  if (!strval) return elist;

  char* tok = strtok(strval, delim);

  while (tok != 0) {
    EStr* estr = e_fromstr(tok);
    elist->length += 1;
    elist->items = (EStr**)realloc(elist->items, elist->length*sizeof(EStr*));
    elist->items[elist->length-1] = estr;
    tok = strtok(0, delim);
  }

  free(strval);

  return elist;
}

unsigned int e_contains_str(EStr s, char* v) {
  return strstr(s.value, v) != 0;
}

unsigned int e_contains_char(EStr s, char c) {
  return strchr(s.value, c) != 0;
}

EStr* e_concat(EStr* a, EStr b) {
  if (!a) {
    printf("Warning: e_concat: `a` is null.\n");
    return a;
  }

  if (!b.length || !b.value) return a;
  uint32_t added_length = b.length;
  uint32_t length_before = a->length;

  a->length += added_length;

  a->value = realloc(a->value, (a->length + 1) * sizeof(char));

  if (!a->value) {
    printf("e_concat: not reallocate\n");
    exit(1);
  }

  memset(&a->value[length_before], 0, (added_length + 1));
  strcat(a->value, b.value);

  return a;
}

char* e_chartostr(char c) {
  char* v = (char*)calloc(2, sizeof(char));
  v[0] = c;
  v[1] = '\0';

  return v;
}

EStr* e_concat_char(EStr* a, char c) {
  if (!c) {
    printf("Warning: e_concat_char: c is zero.\n");
    return a;
  }
  char* ss = e_chartostr(c);
  e_concat(a, ESTR(ss));
  free(ss);

  return a;
}

void e_free(EStr* s) {
  if (s->value) free(s->value);
  free(s);
}
