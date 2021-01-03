#include "stdint.h"

#define EXIT_FAILURE 1
#define AF_INET 2      // Internet IP protocol
#define SOCK_DGRAM 2   // for UDP
#define PROT_ICMP 1

#undef assert
#define assert(expr) \
  ((void)((expr) || (__assert(#expr, __FILE__, __LINE__), 0)))


typedef long ssize_t;
typedef uint32_t socklen_t;
typedef unsigned long size_t;
typedef uint32_t in_addr_t;

// c.f.
// https://elixir.bootlin.com/linux/v4.15/source/include/uapi/linux/in.h#L85
struct in_addr {
  uint32_t s_addr;
};

// c.f.
// https://elixir.bootlin.com/linux/v5.4.66/source/include/linux/socket.h#L31
struct sockaddr {
  unsigned short sa_family; /* address family, AF_xxx   */
  char sa_data[14];         /* 14 bytes of protocol address */
};

// c.f.
// https://elixir.bootlin.com/linux/v4.15/source/include/uapi/linux/in.h#L232
struct sockaddr_in {
  uint16_t sin_family;
  uint16_t sin_port;
  struct in_addr sin_addr;
  uint8_t padding[8];
  // c.f.
  // https://elixir.bootlin.com/linux/v4.15/source/include/uapi/linux/in.h#L231
};

void Print(const char* s);
void Println(const char* s);
void PrintNum(int v);

void PrintIPv4Addr(in_addr_t addr);
void PrintHex8ZeroFilled(uint8_t v);
char NumToHexChar(char v);

int socket(int domain, int type, int protocol);
int close(int fd);

ssize_t sendto(int sockfd,
               void* buf,
               size_t len,
               int flags,
               const struct sockaddr* dest_addr,
               socklen_t addrlen);
ssize_t recvfrom(int sockfd,
                 void* buf,
                 size_t len,
                 int flags,
                 struct sockaddr* src_addr,
                 socklen_t* addrlen);


void* memset(void* s, int c, size_t n);
void exit(int);


in_addr_t MakeIPv4AddrFromString(const char* s);
uint8_t StrToByte(const char* s, const char** next);
void __assert(const char* expr_str, const char* file, int line);

void panic(const char* s);
