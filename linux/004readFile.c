//gcc hoge.c
//a.out

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_PATH "./README.md"

ssize_t read(int fd, void *buf, size_t bufsize);

int
main(int argc, char *argv[])
{
    fd = open (LOG_FILE_PATH, O_RDONLY);
    if (fd < 0)
    {
      return -1;
    }
    size = my_read (fd, buf, sizeof (buf));
    

    exit(0);
}
