#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  int p1[2], p2[2];
  char buf[5];

  if (argc > 1){
    fprintf(2, "usage: pingpong\n");
    exit(1);
  }

  pipe(p1); // from child to father
  pipe(p2); // from father to child

  if(fork() == 0){
    read(p2[0], buf, 1);
    if (buf[0] == 's'){
      fprintf(1, "%d: received ping\n", getpid());
      write(p1[1], buf, 1);
    }
  }else{
    write(p2[1], "s", 1);
    read(p1[0], buf, 1);
    if(buf[0] == 's'){
      fprintf(1, "%d: received pong\n", getpid());
    }
  }
  close(p1[0]);
  close(p1[1]);
  close(p2[0]);
  close(p2[1]);

  exit(0);
}
