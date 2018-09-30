#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

 
//http://programing.dip.jp/index.php?C%E8%A8%80%E8%AA%9E%2Fread
#define LOG_FILE_PATH "./README.md"

static ssize_t
my_read (int fd, char *buf, size_t size)
{
  ssize_t done = 0;
  size_t s = size;
 
  while (s > 0)
    {
      done = read (fd, (void *)buf, s);
 
      if (done < 0)
        {
          if (errno == EINTR)   /* Interrupt */
            {
              continue;
            }
          else                  /* Error */
            {
              return done;
            }
        }
      else if (done == 0)       /* EOF */
        {
          return size - s;
        }
      else
        {
          buf += done;
          s -= done;
        }
    }
 
  return size;
}
 
int
main (void)
{
  int fd, size;
  char buf[128];
 
  fd = open (LOG_FILE_PATH, O_RDONLY);
 
  if (fd < 0)
    {
      return -1;
    }
 
  size = my_read (fd, buf, sizeof (buf));
  if (size != sizeof (buf))
    {
      close (fd);
      return -1;
    }
 
  /* 処理を書く */

  printf("size %d", size);

  close (fd);
  return 0;
}