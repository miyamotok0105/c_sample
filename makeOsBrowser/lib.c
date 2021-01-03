#include "lib.h"

void Print(const char* s) {
  write(1, s, strlen(s));
}

void Println(const char* s) {
  write(1, s, strlen(s));
  write(1, "\n", 1);
}

void PrintNum(int v) {
  char s[16];
  int i;
  if (v < 0) {
    write(1, "-", 1);
    v = -v;
  }
  for (i = sizeof(s) - 1; i > 0; i--) {
    s[i] = v % 10 + '0';
    v /= 10;
    if (!v)
      break;
  }
  write(1, &s[i], sizeof(s) - i);
}

void PrintIPv4Addr(in_addr_t addr) {
  uint8_t buf[4];
  *(uint32_t*)buf = addr;
  for (int i = 0;; i++) {
    PrintNum(buf[i]);
    if (i == 3)
      break;
    Print(".");
  }
}

void PrintHex8ZeroFilled(uint8_t v) {
  char s[2];
  s[0] = NumToHexChar((v >> 4) & 0xF);
  s[1] = NumToHexChar(v & 0xF);
  write(1, s, 2);
}

char NumToHexChar(char v) {
  if (v < 10)
    return v + '0';
  if (v < 16)
    return v - 10 + 'A';
  return '?';
}

in_addr_t MakeIPv4AddrFromString(const char* s) {
  // "a.b.c.d" -> in_addr_t (=uint32_t)
  uint8_t buf[4];
  for (int i = 0;; i++) {
    buf[i] = StrToByte(s, &s);
    if (i == 3)
      break;
    assert(*s == '.');
    s++;
  }
  return *(uint32_t*)buf;
}

uint8_t StrToByte(const char* s, const char** next) {
  uint32_t v = 0;
  while ('0' <= *s && *s <= '9') {
    v = v * 10 + *s - '0';
    s++;
  }
  if (next) {
    *next = s;
  }
  return v;
}

void* memset(void* s, int c, size_t n) {
  char* dest = (char*)s;
  while (n > 0) {
    *dest = (char)c;
    dest++;
    n--;
  }
  return s;
}


void __assert(const char* expr_str, const char* file, int line) {
  Print("\nAssertion failed: ");
  Print(expr_str);
  Print(" at ");
  Print(file);
  Print(":");
  PrintNum(line);
  Print("\n");
  exit(EXIT_FAILURE);
}
