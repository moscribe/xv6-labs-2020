#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  if (argc != 2){
    fprintf(2, "usage: sleep time\n");
    exit(1);
  }

  int t = atoi(argv[1]);

  if (!(t > 0)){
    fprintf(2, "usage: please enter a positive integer\n");
    exit(1);
  }

  sleep(t);

  exit(0);
}
