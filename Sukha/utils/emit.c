#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

unsigned char buffer[100];
size_t position = 0;
size_t size = sizeof(buffer);

void execpu() {
  void *map;
  map = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if(map == MAP_FAILED) {
    printf("Failed to execute.\n");
    exit(EXIT_FAILURE);
  }

  memcpy(map, buffer, position);

  void (*exec)(void) = map;
  exec();

  munmap(map, size);
}

void emit8(unsigned char byte) {
  if (position >= size) {
     printf("Buffer oveflow ):\n");
     exit(EXIT_FAILURE);
  }
  buffer[position++] = byte;
}

void emit32(int value) {
    emit8(value & 0xFF);
    emit8((value >> 8) & 0xFF);
    emit8((value >> 16) & 0xFF);
    emit8((value >> 24) & 0xFF);
}
