# easystr
> C string library

## Usage

``` C
#include <easystr.h>
#include <stdio.h>


int main(int argc, char* argv[]) {

  EStr* str = e_fromstr("Hello world");
  str = e_concat(str, ESTR("John Doe"));


  printf("%s\n", str->value);

  printf("%d\n", e_contains_str(*str, "John"));
  printf("%d\n", e_contains_char(*str, 'H'));

  e_free(str);

  return 0;
}
```
