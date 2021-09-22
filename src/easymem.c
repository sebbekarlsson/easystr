#include <easymem.h>
#include <stdio.h>

void* easy_calloc(uint32_t length, size_t chunksize) {
  void* data = calloc(length, chunksize);

  if (!data) {
    printf("Easystr: Could not allocate (%d, %ld)\n", length, chunksize);
    exit(1);
  }

  return data;
}
